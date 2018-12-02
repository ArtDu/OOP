#ifndef LAB_4_TITERATOR_H
#define LAB_4_TITERATOR_H

#include <memory>
#include <iostream>

template <class node, class T>
class TIterator
{
public:

    TIterator(std::shared_ptr<node> n)   {

        node_ptr = n;
    }


    T operator * (){
        return node_ptr->GetFigure();
    }

    T operator -> (){
        return node_ptr->GetFigure();
    }

    void operator ++ (){
        node_ptr = node_ptr->GetPrev();
    }

    TIterator operator ++ (int){
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIterator const& i){
        return node_ptr == i.node_ptr;
    }

    bool operator != (TIterator const& i){
        return !(*this == i);
    }

private:

    std::shared_ptr<node> node_ptr;
};

#endif //LAB_4_TITERATOR_H
