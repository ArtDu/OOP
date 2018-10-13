#include "TStack.h"

template <class T>
TStack<T>::TStack() : top(nullptr), size(0) {
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

template class TStack<std::shared_ptr<Figure>>;
template std::ostream& operator<<(std::ostream &os, const TStack<std::shared_ptr<Figure>>& stack);