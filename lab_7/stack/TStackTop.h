//
// TStackTop.h
// 13.11.18
//

#ifndef LAB_4_TSTACKTOP_H
#define LAB_4_TSTACKTOP_H

#include "TStackItem.h"
#include "TIterator.h"
#include "TRemoveCriteria.h"

template <class T, class TT>
class TStackTop {

public:

    TStackTop();

    void InsertSubitem(TT &value);
    void InsertSubitem(TT &&value);

    void RemoveSubitem(TRemoveCriteria<TT> * criteria);

    //for rvalue
    void push(T &&elem);
    //for lvalue
    void push(T &elem);
    size_t getSize();
    bool empty();
    T pop();

    TIterator<TStackItem<T>,T> begin();
    TIterator<TStackItem<T>,T> end();

    template <class A, class AA>
    friend std::ostream& operator<<(std::ostream &os, const TStackTop<A, AA>& stack);

    ~TStackTop();

private:
    std::shared_ptr<TStackItem<T>> top;
    size_t size;
};


#endif //LAB_4_TSTACKTOP_H
