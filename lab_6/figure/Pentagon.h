#ifndef LAB_1_PENTAGON_H
#define LAB_1_PENTAGON_H
#include "Figure.h"

class Pentagon : public Figure {
public:

    Pentagon ();
    Pentagon (std::istream &is);
    Pentagon (size_t side, size_t height);
    Pentagon (const Pentagon& orig);

    double Square() const override;
    void   Print() const override;
    virtual ~Pentagon();

private:
    size_t side;
    size_t apothem;

};


#endif //LAB_1_PENTAGON_H
