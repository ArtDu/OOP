#include "TStack.h"
#include <functional>

template <class T>
TStack<T>::TStack() : top(nullptr), size(0) {
}

template <class T>
void TStack<T>::sort() {
    if (getSize() > 1) {
        T middle = pop();
        TStack<T> left, right;

        while (!empty()) {
            T item = pop();
            if (*item < *middle) {
                left.push(item);
            } else {
                right.push(item);
            }
        }

        left.sort();
        right.sort();

        while (!left.empty()) push(left.pop_last());
        push(middle);
        while (!right.empty()) push(right.pop_last());

    }
}

template<class T >
std::future<void> TStack<T>::sort_in_background() {
    /*
    std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TStack<T>::sort_parallel), this));
    std::future<void> res(task.get_future());
    std::thread th(std::move(task));
    th.detach();
    return res;
   */
    return std::async(std::bind(std::mem_fn(&TStack<T>::sort_parallel), this));
}

template <class T>
void TStack<T>::sort_parallel() {
    if (getSize() > 1) {
        T middle = pop_last();
        TStack<T> left, right;

        while (!empty()) {
            T item = pop_last();
            if (*item < *middle) {
                left.push(item);
            } else {
                right.push(item);
            }
        }

        std::future<void> left_res = left.sort_in_background();
        std::future<void> right_res = right.sort_in_background();


        left_res.get();


        while (!left.empty()) push(left.pop_last());
        push(middle);

        right_res.get();
        while (!right.empty()) push(right.pop_last());

    }
}



template <class T>
TStack<T>::TStack(const TStack<T>& orig) {
    std::shared_ptr<TStackItem<T>> item = orig.top;
    size = orig.size;
    while(item != nullptr) {
        item = item->GetPrev();
        this->push(item->GetFigure());
    }

}

template <class T>
size_t TStack<T>::getSize() {
    return this->size;
}

template <class T>
void TStack<T>::push(T &&trap) {
    std::shared_ptr<TStackItem<T>> newItem(new TStackItem<T>(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T>
void TStack<T>::push(T &trap) {
    std::shared_ptr<TStackItem<T>> newItem(new TStackItem<T>(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T>
bool TStack<T>::empty() {
    return top==nullptr;
}

template <class T>
T TStack<T>::pop() {
    T result;
    if (top != nullptr) {
        std::shared_ptr<TStackItem<T>>old_top = top;
        top = top->GetPrev();
        result = old_top->GetFigure();
        old_top->SetPrev(nullptr);
        size--;
    }
    else {
        std::cout << "Stack isn't have elements" << std::endl;
    }

    return result;
}

template <class T>
T TStack<T>::pop_last() {
    T result;

    if (top != nullptr) {
        std::shared_ptr<TStackItem < T>> element = top;
        std::shared_ptr<TStackItem < T>> prev = nullptr;

        while (element->GetPrev() != nullptr) {
            prev = element;
            element = element->GetPrev();
        }

        if (prev != nullptr) {
            prev->SetPrev(nullptr);
            result = element->GetFigure();

        } else {
            result = element->GetFigure();
            top = nullptr;
        }
    }

    return result;

}

template <class T>
TStack<T>::~TStack() {
    while(!this->empty()) {
        this->pop();
    }
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TStack<T>& stack) {
    std::shared_ptr<TStackItem<T>>item = stack.top;
    os << "Stack: " << std::endl<< std::endl;

    while(item != nullptr) {
        os << *item;
        item = item->GetPrev();

    }
    return os;
}


template <class T> TIterator<TStackItem<T>,T> TStack<T>::begin()
{
    return TIterator<TStackItem<T>,T>( top );
}

template <class T> TIterator<TStackItem<T>,T> TStack<T>::end()
{
    return TIterator<TStackItem<T>,T>( nullptr );
}




template class TStack<std::shared_ptr<Figure>>;
template std::ostream& operator<<(std::ostream &os, const TStack<std::shared_ptr<Figure>>& stack);