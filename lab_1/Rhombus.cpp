
#include "Rhombus.h"
#include <iostream>

Rhombus::Rhombus() : Rhombus(0,0) {

}

Rhombus::Rhombus(std::istream &is) {
    is >> side >> height;
}

Rhombus::Rhombus(const Rhombus &orig) {
    side = orig.side;
    height = orig.height;
}

Rhombus::Rhombus(size_t side, size_t height): side(side), height(height) {
    std::cout << "Rhombus created: " << side << ", " << height << std::endl;
}

void Rhombus::Print() {
    std::cout <<"side = " << side << ", height = " << height << std::endl;
}

double Rhombus::Square() {
    return side * height;
}

Rhombus::~Rhombus() {
    std::cout << "Rhombus delete" << std::endl;
}