#ifndef LAB_2_TSTACKITEM_H
#define LAB_2_TSTACKITEM_H

#include "../figure/Trapeze.h"
#include "../figure/Pentagon.h"
#include "../figure/Rhombus.h"

template <class T>
class TStackItem {
public:
    //type conversion
    TStackItem(const T &fig);
    //copy construct
    TStackItem(const TStackItem& orig);

    template <class A>
    friend std::ostream& operator<<(std::ostream& os, const TStackItem<A>& item);

    void SetPrev(std::shared_ptr<TStackItem<T>> prev);
    std::shared_ptr<TStackItem<T>> GetPrev();
    T GetFigure() const;

    virtual ~TStackItem();
private:

    T figure;
    std::shared_ptr<TStackItem<T>> prev;
};


#endif //LAB_2_TSTACKITEM_H
