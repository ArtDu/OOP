#ifndef LAB_2_TSTACKITEM_H
#define LAB_2_TSTACKITEM_H

#include "Trapeze.h"


class TStackItem {
public:
    //type conversion
    TStackItem(const Trapeze& trap);
    //copy construct
    TStackItem(const TStackItem& orig);

    friend std::ostream& operator<<(std::ostream& os, const TStackItem& item);

    void SetPrev(TStackItem* prev);
    TStackItem* GetPrev();
    Trapeze GetTrapeze() const;

    virtual ~TStackItem();
private:

    Trapeze trapeze;
    TStackItem* prev;
};


#endif //LAB_2_TSTACKITEM_H
