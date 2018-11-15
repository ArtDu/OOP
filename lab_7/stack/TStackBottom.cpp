#include "TStackBottom.h"

template <class T>
TStackBottom<T>::TStackBottom() : top(nullptr), size(0) {
}

template <class T>
TStackBottom<T>::TStackBottom(const TStackBottom<T>& orig) {
    std::shared_ptr<TStackItem<T>> item = orig.top;
    size = orig.size;
    while(item != nullptr) {
        item = item->GetPrev();
        this->push( item->GetValue());
    }

}

template <class T>
size_t TStackBottom<T>::getSize() {
    return this->size;
}

template <class T>
void TStackBottom<T>::push(T &&trap) {
    std::shared_ptr<TStackItem<T>> newItem(new TStackItem<T>(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T>
void TStackBottom<T>::push(T &trap) {
    std::shared_ptr<TStackItem<T>> newItem(new TStackItem<T>(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T>
bool TStackBottom<T>::empty() {
    return top==nullptr;
}

template <class T>
T TStackBottom<T>::pop() {
    T result;
    if (top != nullptr) {
        std::shared_ptr<TStackItem<T>>old_top = top;
        top = top->GetPrev();
        result = old_top->GetValue();
        old_top->SetPrev(nullptr);
        size--;
    }
    else {
        std::cout << "Stack isn't have elements" << std::endl;
    }

    return result;
}

template <class T>
TStackBottom<T>::~TStackBottom() {
    while(!this->empty()) {
        this->pop();
    }
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TStackBottom<T>& stack) {
    std::shared_ptr<TStackItem<T>>item = stack.top;
    os << "\tStack 2nd lvl: " << std::endl;

    while(item != nullptr) {
        os << *item;
        item = item->GetPrev();

    }
    return os;
}


template <class T> TIterator<TStackItem<T>,T> TStackBottom<T>::begin()
{
    return TIterator<TStackItem<T>,T>( top );
}

template <class T> TIterator<TStackItem<T>,T> TStackBottom<T>::end()
{
    return TIterator<TStackItem<T>,T>( nullptr );
}




template class TStackBottom<std::shared_ptr<Figure>>;
template std::ostream& operator<<(std::ostream &os, const TStackBottom<std::shared_ptr<Figure>>& stack);