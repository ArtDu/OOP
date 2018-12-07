//
// TStackItemSnd.h
// 07.12.18
//

#ifndef LAB_4_TSTACKITEMSND_H
#define LAB_4_TSTACKITEMSND_H

#include <memory>

template <class T>
class TStackItemSnd {
public:
    //type conversion
    TStackItemSnd(const T &fig);
    //copy construct
    TStackItemSnd(const TStackItemSnd& orig);


    void SetPrev(std::shared_ptr<TStackItemSnd<T>> prev);
    std::shared_ptr<TStackItemSnd<T>> GetPrev();
    T GetFigure() const;

    virtual ~TStackItemSnd();
private:

    T figure;
    std::shared_ptr<TStackItemSnd<T>> prev;
};



#endif //LAB_4_TSTACKITEMSND_H
