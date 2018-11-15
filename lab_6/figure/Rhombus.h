#ifndef LAB_1_RHOMBUS_H
#define LAB_1_RHOMBUS_H
#include "Figure.h"

class Rhombus : public Figure {
public:

    Rhombus ();
    Rhombus (std::istream &is);
    Rhombus (size_t side, size_t height);
    Rhombus (const Rhombus& orig);
    double Square() const override;
    void   Print() const override;
    virtual ~Rhombus();

private:
    size_t side;
    size_t height;

};


#endif //LAB_1_RHOMBUS_H
