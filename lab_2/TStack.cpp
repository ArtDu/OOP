//
// Created by art on 08.10.18.
//

#include "TStack.h"


TStack::TStack() : top(nullptr), size(0) {
}

TStack::TStack(const TStack &orig) {
    TStackItem *item = orig.top;
    size = orig.size;
    while(item != nullptr) {
        item = item->GetPrev();
        this->push(item->GetTrapeze());
    }

}

size_t TStack::getSize() {
    return this->size;
}

void TStack::push(Trapeze &&trap) {
    TStackItem* newItem = new TStackItem(trap);
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

void TStack::push(Trapeze &trap) {
    TStackItem* newItem = new TStackItem(trap);
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

bool TStack::empty() {
    return top==nullptr;
}

Trapeze TStack::pop() {
    Trapeze result;
    if (top != nullptr) {
        TStackItem *old_top = top;
        top = top->GetPrev();
        result = old_top->GetTrapeze();
        old_top->SetPrev(nullptr);
        delete old_top;
        size--;
    }
    else {
        std::cout << "Stack isn't have elements" << std::endl;
    }

    return result;
}

TStack::~TStack() {
    while(!this->empty()) {
        this->pop();
    }
}

std::ostream& operator<<(std::ostream &os, const TStack& stack) {
    TStackItem *item = stack.top;
    os << "Stack: " << std::endl;

    while(item != nullptr) {
        os << *item;
        item = item->GetPrev();

    }
    return os;
}