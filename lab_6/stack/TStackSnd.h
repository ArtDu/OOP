
#ifndef LAB_4_TSTACKSND_H
#define LAB_4_TSTACKSND_H

#include "TStackItemSnd.h"
#include "TIterator.h"

template <class T>
class TStackSnd {
public:
    TStackSnd();
    //copy constructor
    TStackSnd(const TStackSnd<T>& orig);

    //for rvalue
    void push(T &&trap);
    //for lvalue
    void push(T &trap);
    size_t getSize();
    bool empty();
    T pop();


    TIterator<TStackItemSnd<T>,T> begin();
    TIterator<TStackItemSnd<T>,T> end();


    ~TStackSnd();

private:
    std::shared_ptr<TStackItemSnd<T>> top;
    size_t size;
};





#endif //LAB_4_TSTACKSND_H
