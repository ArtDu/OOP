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
                ptr = new Trapeze(std::cin);
                break;
            }
            case '2':{
                ptr = new Rhombus(std::cin);
                break;
            }
            case '3':{
                ptr = new Pentagon(std::cin);
                break;
            }
            default:{
                std::cout << "Unknown option" << std::endl;;
                break;
            }

        }

        ptr->Print();
        std::cout << "Square:" << std::endl << ptr->Square() << std::endl;
        delete ptr;
    }



    return 0;
}

