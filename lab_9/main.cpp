#include <cstdlib>
#include <iostream>
#include <future>
#include <functional>
#include <random>
#include <thread>
#include <ctime>
#include "figure/Figure.h"
#include "stack/TStack.h"


int main(int argc, char** argv) {


    srand(time(NULL));

    TStack<std::shared_ptr<Figure>> stack;
    typedef std::function<void (void) > command;
    TStack <std::shared_ptr<command>> stack_cmd;


    command cmd_insert = [&]() {
        std::cout << "Command: Insert figure with random sides" << std::endl;

        int fst_value = (rand() %1000) + 1;
        int snd_value = (rand() %1000) + 1;
        int trd_value = (rand() %1000) + 1;
        std::shared_ptr<Figure> t;
        int action = (rand() %3) + 1;
        switch (action) {
            case 1:
                t = std::make_shared<Pentagon>(fst_value, snd_value);
                break;
            case 2:
                t = std::make_shared<Rhombus>(fst_value, snd_value);
                break;
            case 3:
                t = std::make_shared<Trapeze>(fst_value, snd_value, trd_value);
                break;
        }

        stack.push(t);
    };

    command cmd_print = [&]() {
        std::cout << "Command: Print stack" << std::endl;
        std::cout << stack;
    };

    command cmd_delete = [&]() {
        int number;
        std::cout << "Enter the number(delete lambda)"<<std::endl;
        std::cin >> number;
        TStack<std::shared_ptr<Figure>> tmp;
        while(!stack.empty()) {
            auto figure = stack.pop();
            if(figure->Square() >= number) {
                tmp.push(figure);
            }
        }
        while (!tmp.empty()) {
            auto figure = tmp.pop();
            stack.push(figure);
        }
    };

    unsigned int action;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Add command generate" << std::endl;
        std::cout << "2) Add command print" << std::endl;
        std::cout << "3) Add command delete" << std::endl;
        std::cout << "4) Add command execute" << std::endl;
        std::cout << "5) Print" << std::endl;
        std::cout << "0) Quit" << std::endl;
        std::cin >> action;

        if (action == 0) {
            break;
        }

        switch (action) {
            case 1: {

                stack_cmd.push(std::shared_ptr<command> (&cmd_insert, [](command*) {
                }));

                break;
            }
            case 2: {
                stack_cmd.push(std::shared_ptr<command> (&cmd_print, [](command*) {
                }));
                break;
            }

            case 3: {
                stack_cmd.push(std::shared_ptr<command> (&cmd_delete, [](command*) {
                }));
                break;
            }

            case 4: {
                while (!stack_cmd.empty()) {
                    std::shared_ptr<command> cmd = stack_cmd.pop();
                    std::future<void> ft = std::async(*cmd);
                    ft.get();
                }
                break;
            }
            case 5: {
                for(auto i : stack)
                    std::cout << *i << std::endl;
                break;
            }
            default:
                std::cout << "Invalid action" << std::endl;
                break;
        }
    }


    return 0;
}

