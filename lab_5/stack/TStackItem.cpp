
#include "TStackItem.h"

template <class T>
TStackItem<T>::TStackItem(const T &fig) {
    figure = fig;
    prev = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

template <class T>
TStackItem<T>::TStackItem(const TStackItem& orig) {
    figure = orig.figure;
    prev = orig.prev;
    //std::cout << "Stack item: copied" << std::endl;
}

template <class T>
void TStackItem<T>::SetPrev(std::shared_ptr<TStackItem<T>> prev) {
    if(this != nullptr)
        this->prev = prev;
}

template <class T>
std::shared_ptr<TStackItem<T>> TStackItem<T>::GetPrev() {
    return this->prev;
}

template <class T>
T TStackItem<T>::GetFigure() const{
    return this->figure;
}

template <class T>
TStackItem<T>::~TStackItem() {
    //std::cout << "Stack item: deleted" << std::endl;

}

template <class T>
std::ostream& operator<<(std::ostream& os, const TStackItem<T>& item) {
    std::cout << *item.figure;
    return os;
}

template class TStackItem<std::shared_ptr<Figure>>;
template std::ostream& operator<<(std::ostream &os, const TStackItem<std::shared_ptr<Figure>>& stack);