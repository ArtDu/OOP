
#include "TStackItem.h"


TStackItem::TStackItem(const std::shared_ptr<Figure> &trap) {
    figure = trap;
    prev = nullptr;
    //std::cout << "Stack item: created" << std::endl;
}

TStackItem::TStackItem(const TStackItem& orig) {
    figure = orig.figure;
    prev = orig.prev;
    //std::cout << "Stack item: copied" << std::endl;
}

void TStackItem::SetPrev(std::shared_ptr<TStackItem> prev) {
    if(this != nullptr)
        this->prev = prev;
}

std::shared_ptr<TStackItem> TStackItem::GetPrev() {
    return this->prev;
}

std::shared_ptr<Figure> TStackItem::GetFigure() const{
    return this->figure;
}

TStackItem::~TStackItem() {
    //std::cout << "Stack item: deleted" << std::endl;

}

std::ostream& operator<<(std::ostream& os, const TStackItem& item) {
    std::cout << *item.figure;
    return os;
}