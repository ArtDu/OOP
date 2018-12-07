//
// TStackSnd.cpp
// 07.12.18
//

#include "TStackSnd.h"

template <class T>
TStackSnd<T>::TStackSnd() : top(nullptr), size(0) {
}

template <class T>
TStackSnd<T>::TStackSnd(const TStackSnd<T>& orig) {
    std::shared_ptr<TStackItemSnd<T>> item = orig.top;
    size = orig.size;
    while(item != nullptr) {
        item = item->GetPrev();
        this->push(item->GetFigure());
    }

}

template <class T>
size_t TStackSnd<T>::getSize() {
    return this->size;
}

template <class T>
void TStackSnd<T>::push(T &&trap) {
    std::shared_ptr<TStackItemSnd<T>> newItem(new TStackItemSnd<T>(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T>
void TStackSnd<T>::push(T &trap) {
    std::shared_ptr<TStackItemSnd<T>> newItem(new TStackItemSnd<T>(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T>
bool TStackSnd<T>::empty() {
    return top==nullptr;
}

template <class T>
T TStackSnd<T>::pop() {
    T result;
    if (top != nullptr) {
        std::shared_ptr<TStackItemSnd<T>>old_top = top;
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
TStackSnd<T>::~TStackSnd() {
    while(!this->empty()) {
        this->pop();
    }
}


template <class T> TIterator<TStackItemSnd<T>,T> TStackSnd<T>::begin()
{
    return TIterator<TStackItemSnd<T>,T>( top );
}

template <class T> TIterator<TStackItemSnd<T>,T> TStackSnd<T>::end()
{
    return TIterator<TStackItemSnd<T>,T>( nullptr );
}

template class TStackSnd<void*>;