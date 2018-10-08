
#include "TStackItem.h"


TStackItem::TStackItem(const Trapeze& trap) {
    trapeze = trap;
    prev = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

TStackItem::TStackItem(const TStackItem &orig) {
    trapeze = orig.trapeze;
    prev = orig.prev;
    //std::cout << "Stack item: copied" << std::endl;
}

void TStackItem::SetPrev(TStackItem *prev) {
    if(this != nullptr)
        this->prev = prev;
}

TStackItem* TStackItem::GetPrev() {
    return this->prev;
}

Trapeze TStackItem::GetTrapeze() const {
    return this->trapeze;
}

TStackItem::~TStackItem() {
    //std::cout << "Stack item: deleted" << std::endl;
    delete prev;
}

std::ostream& operator<<(std::ostream& os, const TStackItem& item) {
    std::cout << item.trapeze;
    return os;
}