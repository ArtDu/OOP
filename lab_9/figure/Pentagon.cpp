#include "Pentagon.h"
#include <iostream>
//apothem

Pentagon::Pentagon() : Pentagon(0,0) {

}

Pentagon::Pentagon(std::istream &is) {
    std::cout << "Enter side and apothem:"<<std::endl;
    is >> side >> apothem;
}

Pentagon::Pentagon(const Pentagon &orig) {
    side = orig.side;
    apothem = orig.apothem;
}

Pentagon::Pentagon(size_t side, size_t apothem): side(side), apothem(apothem) {
    //std::cout << "Rhombus created: " << side << ", " << apothem << std::endl;
}

void Pentagon::Print() const{
    std::cout << "Pentagon:" <<std::endl;
    std::cout <<"side = " << side << ", apothem = " << apothem << std::endl;
}

double Pentagon::Square() const{
    return (side * apothem / 2) * 5 ;
}

Pentagon::~Pentagon() {
    //std::cout << "Pentagon delete" << std::endl;
}