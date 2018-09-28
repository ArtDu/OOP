//
// Created by art on 27.09.18.
//

#ifndef LAB_1_TRAPEZE_H
#define LAB_1_TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapeze : public Figure {
public:

    Trapeze ();
    Trapeze (std::istream &is);
    Trapeze (size_t base_a, size_t base_b, size_t height);
    Trapeze (const Trapeze& orig);
    double Square() override;
    void   Print() override;
    virtual ~Trapeze();

private:
    size_t base_a;
    size_t base_b;
    size_t height;


};


#endif //LAB_1_TRAPEZE_H
