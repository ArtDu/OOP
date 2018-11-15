
#include "TStackItem.h"

template <class T>
TStackItem<T>::TStackItem(const T &fig) {
    value = fig;
    prev = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

template <class T>
TStackItem<T>::TStackItem(const TStackItem& orig) {
    value = orig.value;
    prev = orig.prev;
    //std::cout << "Stack item: copied" << std::endl;
}

template<class T>
TAllocationBlock TStackItem<T>::allocator(
        sizeof(TStackItem<T> ), 20);


template<class T>
void * TStackItem<T>::operator new(size_t size) {
    //std::cout<<"//TStackItem: new item"<<std::endl;
    return allocator.allocate();
}

template<class T>
void TStackItem<T>::operator delete(void *p) {
    //std::cout<<"//TStackItem: item deleted"<<std::endl;
    allocator.deallocate(p);
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
T TStackItem<T>::GetValue() const{
    return this->value;
}

template <class T>
TStackItem<T>::~TStackItem() {
    //std::cout << "Stack item: deleted" << std::endl;

}

template <class T>
std::ostream& operator<<(std::ostream& os, const TStackItem<T>& item) {
    std::cout << *item.value;
    return os;
}

#include "TStackBottom.h"

template class TStackItem<std::shared_ptr<Figure>>;
template class TStackItem<std::shared_ptr<TStackBottom<std::shared_ptr<Figure>>>>;
template std::ostream& operator<<(std::ostream &os, const TStackItem<std::shared_ptr<Figure>>& stack);
template std::ostream& operator<<(std::ostream &os, const TStackItem<std::shared_ptr<TStackBottom<std::shared_ptr<Figure>>>>& stack);