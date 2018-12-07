//
// TStackItemSnd.cpp
// 07.12.18
//

#include "TStackItemSnd.h"

template <class T>
TStackItemSnd<T>::TStackItemSnd(const T &fig) {
    figure = fig;
    prev = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

template <class T>
TStackItemSnd<T>::TStackItemSnd(const TStackItemSnd& orig) {
    figure = orig.figure;
    prev = orig.prev;
    //std::cout << "Stack item: copied" << std::endl;
}

template <class T>
void TStackItemSnd<T>::SetPrev(std::shared_ptr<TStackItemSnd<T>> prev) {
    if(this != nullptr)
    this->prev = prev;
}

template <class T>
std::shared_ptr<TStackItemSnd<T>> TStackItemSnd<T>::GetPrev() {
    return this->prev;
}

template <class T>
T TStackItemSnd<T>::GetFigure() const{
    return this->figure;
}

template <class T>
TStackItemSnd<T>::~TStackItemSnd() {
    //std::cout << "Stack item: deleted" << std::endl;

}

template class TStackItemSnd<void*>;

