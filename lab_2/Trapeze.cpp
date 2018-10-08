
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

std::ostream& operator<< (std::ostream& os, const Trapeze& trap) {
    //os << "Trapeze" << std::endl;
    os << "first base = " << trap.base_a;
    os << ", second base = " << trap.base_b;
    os << ", height = " << trap.height << std::endl;
    //os << "Square = " << trap.Square() << std::endl;
    return os;
}

std::istream& operator>> (std::istream& is, Trapeze& trap) {
    std::cout << "Enter first base, second base and height:"<<std::endl;
    is >> trap.base_a >> trap.base_b >> trap.height;
    return is;
}

Trapeze& Trapeze::operator= (const Trapeze& right) {
    if (this == &right) return *this;

    //std::cout << "Trapeze copied" << std::endl;
    base_a = right.base_a;
    base_b = right.base_b;
    height = right.height;

    return *this; // a = b = c
}

bool Trapeze::operator== (const Trapeze& right) const {
    if(base_a == right.base_a && base_b == right.base_b && height == right.height) {
        return true;
    }
    return false;
}

void Trapeze::Print() const {
    //std::cout << "Trapeze:" <<std::endl;
    std::cout <<"first base = " << base_a << ", second base = " << base_b << ", height = " << height << std::endl;
}

double Trapeze::Square() const {
    return ((base_a + base_b) / 2) * height;
}

Trapeze::~Trapeze() {
    //std::cout << "Trapeze delete" << std::endl;
}