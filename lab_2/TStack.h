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
    void push(Trapeze &&trap);
    //for lvalue
    void push(Trapeze &trap);
    size_t getSize();
    bool empty();
    Trapeze pop();

    friend std::ostream& operator<<(std::ostream &os, const TStack& stack);

    ~TStack();

private:
    TStackItem* top;
    size_t size;
};


#endif //LAB_2_TSTACK_H
