#include "Rhombus.h"


Rhombus::Rhombus() : Rhombus(0,0) {

}

Rhombus::Rhombus(std::istream &is) {
    std::cout << "Enter side and height:"<<std::endl;
    is >> side >> height;
}

Rhombus::Rhombus(const Rhombus &orig) {
    side = orig.side;
    height = orig.height;
}

Rhombus::Rhombus(size_t side, size_t height): side(side), height(height) {
    //std::cout << "Rhombus created: " << side << ", " << height << std::endl;
}

void Rhombus::Print() const{
    std::cout << "Rhombus:";
    std::cout <<"( " << side << ", " << height << " )" << std::endl;
}

double Rhombus::Square() const{
    return side * height;
}

bool Rhombus::operator==(const Rhombus& other){
    return (side==other.side) && (height==other.height);
}

char Rhombus::getType() const {
    return 'r';
}

Rhombus::~Rhombus() {
    //std::cout << "Rhombus delete" << std::endl;
}