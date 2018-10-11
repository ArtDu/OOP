//
// Created by art on 08.10.18.
//

#ifndef LAB_2_TSTACK_H
#define LAB_2_TSTACK_H


#include "TStackItem.h"

class TStack {
public:
    TStack();
    //copy constructor
    TStack(const TStack& orig);

    //for rvalue
    void push(std::shared_ptr<Figure> &&trap);
    //for lvalue
    void push(std::shared_ptr<Figure> &trap);
    size_t getSize();
    bool empty();
    std::shared_ptr<Figure> pop();

    friend std::ostream& operator<<(std::ostream &os, const TStack& stack);

    ~TStack();

private:
    std::shared_ptr<TStackItem> top;
    size_t size;
};


#endif //LAB_2_TSTACK_H
