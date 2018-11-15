#include <cstdlib>
#include <iostream>
#include "figure/Figure.h"
#include "stack/TStackBottom.h"
#include "stack/TStackTop.h"
#include "stack/TRemoveCriteriaAll.h"
#include "stack/TRemoveCriteriaByValue.h"
#include "stack/TRemoveCriteriaByType.h"



int main(int argc, char** argv) {


    TStackTop<std::shared_ptr<TStackBottom<std::shared_ptr<Figure>>>, std::shared_ptr<Figure>> stackTop;


    unsigned int action;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Add figure" << std::endl;
        std::cout << "2) Delete figures with square = <x>" << std::endl;
        std::cout << "3) Delete figures with type = <y>" << std::endl;
        std::cout << "4) Delete all figures" << std::endl;
        std::cout << "5) Print" << std::endl;
        std::cout << "6) Print size" << std::endl;
        std::cout << "0) Quit" << std::endl;
        std::cin >> action;

        if (action == 0) {
            break;
        }

        switch (action) {
            case 1: {
                char figure_type;
                std::cout
                        << "Enter figure type: t - trapeze, p - pentagon, r - rhombus: ";
                std::cin >> figure_type;
                std::shared_ptr<Figure> t;
                switch (figure_type) {
                    case 't': {
                        t = std::make_shared<Trapeze>(std::cin);
                        stackTop.InsertSubitem(t);
                        break;
                    }
                    case 'p': {
                        t = std::make_shared<Pentagon>(std::cin);
                        stackTop.InsertSubitem(t);
                        break;
                    }
                    case 'r': {
                        t = std::make_shared<Rhombus>(std::cin);
                        stackTop.InsertSubitem(t);
                        break;
                    }
                    default: {
                        std::cout << "Try more..." << std::endl;
                        break;
                    }
                }

                break;
            }
            case 2: {
                int square;
                std::cout << "Enter square:\n";
                std::cin >> square;
                TRemoveCriteriaByValue<std::shared_ptr<Figure>> criteria(square);
                stackTop.RemoveSubitem(&criteria);
                break;
            }
            case 3: {
                char figure_type;
                std::cout
                        << "Enter figure type: t - trapeze, p - pentagon, r - rhombus: ";
                std::cin >> figure_type;
                TRemoveCriteriaByType<std::shared_ptr<Figure>> criteria(figure_type);
                stackTop.RemoveSubitem(&criteria);
                break;
            }
            case 4: {
                TRemoveCriteriaAll<std::shared_ptr<Figure>> criteria;
                stackTop.RemoveSubitem(&criteria);
                break;
            }

            case 5: {
                std::cout << stackTop << std::endl;
                break;
            }

            case 6: {
                size_t size = stackTop.getSize();
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

