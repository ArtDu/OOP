#ifndef LAB_1_TRAPEZE_H
#define LAB_1_TRAPEZE_H
#include "Figure.h"

class Trapeze : public Figure {
public:

    Trapeze ();
    Trapeze (std::istream &is);
    Trapeze (size_t base_a, size_t base_b, size_t height);
    Trapeze (const Trapeze& orig);

    double Square() const override;
    void   Print() const override;
    virtual ~Trapeze();

private:
    size_t base_a;
    size_t base_b;
    size_t height;


};


#endif //LAB_1_TRAPEZE_H
