#include <cstdlib>
#include <iostream>
#include "TStack.h"


int main(int argc, char** argv) {


    TStack stack;
    unsigned int action;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Push figure" << std::endl;
        std::cout << "2) Pop figure" << std::endl;
        std::cout << "3) Print" << std::endl;
        std::cout << "4) Print size" << std::endl;
        std::cout << "0) Quit" << std::endl;
        std::cin >> action;

        if (action == 0) {
            break;
        }

        switch (action) {
            case 1: {
                Trapeze t;
                std::cin >> t;
                stack.push(t);
                break;
            }
            case 2: {
                stack.pop();
                break;
            }

            case 3: {
                std::cout<<stack;
                break;
            }

            case 4: {
                size_t size = stack.getSize();
                std::cout << "size: " << size << std::endl;
                break;
            }
            default:
                std::cout << "Invalid action" << std::endl;
                break;
        }
    }


    return 0;
}

