
#include "Trapeze.h"
#include <iostream>

Trapeze::Trapeze() : Trapeze(0,0,0) {

}

Trapeze::Trapeze(std::istream &is) {
    std::cout << "Enter first base, second base and height:"<<std::endl;
    is >> base_a >> base_b >> height;
}

Trapeze::Trapeze(const Trapeze &orig) {
    base_a = orig.base_a;
    base_b = orig.base_b;
    height = orig.height;
}

Trapeze::Trapeze(size_t base_a, size_t base_b, size_t height): base_a(base_a), base_b(base_b), height(height) {
    //std::cout << "Trapeze created: " << base_a << ", " << base_b << ", " << height << std::endl;
}

void Trapeze::Print() const {
    std::cout << "Trapeze:" <<std::endl;
    std::cout <<"first base = " << base_a << ", second base = " << base_b << ", height = " << height << std::endl;
}

double Trapeze::Square() const {
    return ((base_a + base_b) / 2) * height;
}

Trapeze::~Trapeze() {
    //std::cout << "Trapeze delete" << std::endl;
}