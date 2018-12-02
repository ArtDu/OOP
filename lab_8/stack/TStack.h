#ifndef LAB_2_TSTACK_H
#define LAB_2_TSTACK_H

#include "TStackItem.h"
#include "TIterator.h"
#include <memory>
#include <future>
#include <mutex>


template <class T>
class TStack {
public:
    TStack();
    //copy constructor
    TStack(const TStack<T>& orig);

    //for rvalue
    void push(T &&trap);
    //for lvalue
    void push(T &trap);
    size_t getSize();
    bool empty();
    T pop();
    T pop_last();


    TIterator<TStackItem<T>,T> begin();
    TIterator<TStackItem<T>,T> end();

    void sort();
    void sort_parallel();

    template <class A>
    friend std::ostream& operator<<(std::ostream &os, const TStack<A>& stack);

    ~TStack();

private:
    std::future<void> sort_in_background();
    std::shared_ptr<TStackItem<T>> top;
    size_t size;

};


#endif //LAB_2_TSTACK_H
