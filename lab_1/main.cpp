#include <cstdlib>
#include <iostream>
#include "Trapeze.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main(int argc, char** argv) {
    char option = '0';
    Figure *ptr;

    while(true) {
        std::cout << std::endl << "Menu: " << std::endl;
        std::cout << "1) Trapeze" << std::endl;
        std::cout << "2) Rhombus" << std::endl;
        std::cout << "3) Pentagon" << std::endl;
        std::cout << "4) Exit" << std::endl;
        std::cout << "Enter the option:" << std::endl;
        std::cin >> option;
        if(option == '4') {
            break;
        }
        switch (option) {
            case '1':{
                std::cout << "Enter first base, second base and height:"<<std::endl;
                ptr = new Trapeze(std::cin);
                std::cout << "Trapeze:" <<std::endl;
                ptr->Print();
                std::cout << "Square of Trapeze: " << std::endl;
                std::cout << ptr->Square() << std::endl;
                delete ptr;

                break;
            }
            case '2':{
                std::cout << "Enter side and height:"<<std::endl;
                ptr = new Rhombus(std::cin);
                std::cout << "Rhombus:" <<std::endl;
                ptr->Print();
                std::cout << "Square of Rhombus: " << std::endl;
                std::cout << ptr->Square() << std::endl;

                delete ptr;
                break;
            }
            case '3':{
                std::cout << "Enter side and apothem:"<<std::endl;
                ptr = new Pentagon(std::cin);
                std::cout << "Pentagon:" <<std::endl;
                ptr->Print();
                std::cout << "Square of Pentagon: " << std::endl;
                std::cout << ptr->Square() << std::endl;

                delete ptr;
                break;
            }
            default:{
                std::cout << "Unknown option" << std::endl;;
                break;
            }

        }
    }



    return 0;
}

