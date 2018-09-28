//
// Created by art on 27.09.18.
//

#ifndef LAB_1_PENTAGON_H
#define LAB_1_PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure {
public:

    Pentagon ();
    Pentagon (std::istream &is);
    Pentagon (size_t side, size_t height);
    Pentagon (const Pentagon& orig);
    double Square() override;
    void   Print() override;
    virtual ~Pentagon();

private:
    size_t side;
    size_t apothem;

};


#endif //LAB_1_PENTAGON_H
