#include "TStack.h"


TStack::TStack() : top(nullptr), size(0) {
}

TStack::TStack(const TStack& orig) {
    std::shared_ptr<TStackItem> item = orig.top;
    size = orig.size;
    while(item != nullptr) {
        item = item->GetPrev();
        this->push(item->GetFigure());
    }

}

size_t TStack::getSize() {
    return this->size;
}

void TStack::push(std::shared_ptr<Figure> &&trap) {
    std::shared_ptr<TStackItem> newItem(new TStackItem(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

void TStack::push(std::shared_ptr<Figure> &trap) {
    std::shared_ptr<TStackItem> newItem(new TStackItem(trap));
    newItem->SetPrev(top);
    top = newItem;
    size++;
}

bool TStack::empty() {
    return top==nullptr;
}

std::shared_ptr<Figure> TStack::pop() {
    std::shared_ptr<Figure> result;
    if (top != nullptr) {
        std::shared_ptr<TStackItem>old_top = top;
        top = top->GetPrev();
        result = old_top->GetFigure();
        old_top->SetPrev(nullptr);
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
    std::shared_ptr<TStackItem>item = stack.top;
    os << "Stack: " << std::endl<< std::endl;

    while(item != nullptr) {
        os << *item;
        item = item->GetPrev();

    }
    return os;
}