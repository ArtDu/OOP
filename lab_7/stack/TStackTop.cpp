//
// TStackTop.cpp
// 13.11.18
//

#include "TStackTop.h"
#include "TStackBottom.h"

template <class T, class TT>
TStackTop<T, TT>::TStackTop() : top(nullptr), size(0) {
}

template <class T, class TT>
size_t TStackTop<T, TT>::getSize() {
    return this->size;
}

template <class T, class TT>
void TStackTop<T, TT>::push(T &&elem) {
    std::shared_ptr<TStackItem<T>> newItem(new TStackItem<T>(elem));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T, class TT>
void TStackTop<T, TT>::push(T &elem) {
    std::shared_ptr<TStackItem<T>> newItem(new TStackItem<T>(elem));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

template <class T, class TT>
bool TStackTop<T, TT>::empty() {
    return top == nullptr;
}

template <class T, class TT>
T TStackTop<T, TT>::pop() {
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

template <class T, class TT>
void TStackTop<T, TT>::InsertSubitem(TT &value) {

    bool inserted = false;
    if (top != nullptr) {

        for (auto i : * this) {
            if (i->getSize() < 5) {
                T t_value;
                t_value = std::make_shared<TStackBottom<std::shared_ptr<Figure>>>();
                double sq = value->Square();
                while(!i->empty()) {
                    TT elem = i->pop();
                    if(elem->Square() < sq) {
                        i->push(elem);
                        break;
                    }
                    t_value->push(elem);
                }
                i->push(value);
                while (!t_value->empty()) {
                    TT elem = t_value->pop();
                    i->push(elem);
                }

                //std::cout << "Stack: Add Element in stack:" << i->getSize() << std::endl;
                inserted = true;
            }
        }
    }

    if (!inserted) {
        //std::cout << "Stack: New stack element created" << std::endl;
        T t_value;
        t_value = std::make_shared<TStackBottom<std::shared_ptr<Figure>>>();
        t_value->push(value);
        push(t_value);
    }
}

template <class T, class TT>
void TStackTop<T, TT>::InsertSubitem(TT &&value) {

    bool inserted = false;
    if (top != nullptr) {

        for (auto i : * this) {
            if (i->getSize() < 5) {
                T t_value;
                t_value = std::make_shared<TStackBottom<std::shared_ptr<Figure>>>();
                double sq = value->Square();
                while(!i->empty()) {
                    TT elem = i->pop();
                    if(elem->Square() < sq) {
                        i->push(elem);
                        break;
                    }
                    t_value->push(elem);
                }
                i->push(value);
                while (!t_value->empty()) {
                    TT elem = t_value->pop();
                    i->push(elem);
                }

                //std::cout << "Stack: Add Element in stack:" << i->getSize() << std::endl;
                inserted = true;
            }
        }
    }

    if (!inserted) {
        //std::cout << "Stack: New stack element created" << std::endl;
        T t_value;
        t_value = std::make_shared<TStackBottom<std::shared_ptr<Figure>>>();
        t_value->push(value);
        push(t_value);
    }
}

template <class T, class TT>
void TStackTop<T, TT>::RemoveSubitem(TRemoveCriteria<TT> * criteria) {
    std::cout << "---------------------->" << std::endl;
    for (auto i : * this) {
        T copy;
        copy = std::make_shared<TStackBottom<std::shared_ptr<Figure>>>();
        while (!i->empty()) {
            TT value = i->pop();

            if (criteria->isIt(value))
                std::cout << "Stack: Delete element "<< std::endl << *value << std::endl;
            else {
                copy->push(value);
            }
        }

        while (!copy->empty()) {
            TT elem = copy->pop();
            i->push(elem);
        }

    }
    TStackTop<T, TT> copy;

    while( !this->empty() ) {
        T elem = this->pop();
        if( !elem->empty() ) {
            copy.push(elem);
        }
    }

    while( !copy.empty() ) {
        T elem = copy.pop();
        this->push(elem);
    }

    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

}

template <class T, class TT>
TStackTop<T, TT>::~TStackTop() {
    while(!this->empty()) {
        this->pop();
    }
}

template <class T, class TT>
std::ostream& operator<<(std::ostream &os, const TStackTop<T, TT>& stack) {
    std::shared_ptr<TStackItem<T>>item = stack.top;
    os << "Stack 1st lvl: " << std::endl;

    while(item != nullptr) {
        os << *item;
        item = item->GetPrev();

    }
    return os;
}


template <class T, class TT>
TIterator<TStackItem<T>,T> TStackTop<T, TT>::begin()
{
    return TIterator<TStackItem<T>,T>( top );
}

template <class T, class TT>
TIterator<TStackItem<T>,T> TStackTop<T, TT>::end()
{
    return TIterator<TStackItem<T>,T>( nullptr );
}


#include "TStackBottom.h"

template class TStackTop<std::shared_ptr<TStackBottom<std::shared_ptr<Figure>>>, std::shared_ptr<Figure>>;
template std::ostream& operator<<(std::ostream &os, const TStackTop<std::shared_ptr<TStackBottom<std::shared_ptr<Figure>>>, std::shared_ptr<Figure>>& stack);