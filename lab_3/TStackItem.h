#ifndef LAB_2_TSTACKITEM_H
#define LAB_2_TSTACKITEM_H

#include "Trapeze.h"
#include "Pentagon.h"
#include "Rhombus.h"


class TStackItem {
public:
    //type conversion
    TStackItem(const std::shared_ptr<Figure> &trap);
    //copy construct
    TStackItem(const TStackItem& orig);

    friend std::ostream& operator<<(std::ostream& os, const TStackItem& item);

    void SetPrev(std::shared_ptr<TStackItem> prev);
    std::shared_ptr<TStackItem> GetPrev();
    std::shared_ptr<Figure> GetFigure() const;

    virtual ~TStackItem();
private:

    std::shared_ptr<Figure> figure;
    std::shared_ptr<TStackItem> prev;
};


#endif //LAB_2_TSTACKITEM_H
