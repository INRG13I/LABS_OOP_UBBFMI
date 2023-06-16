//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#ifndef LAB_6_CONSOLE_H
#define LAB_6_CONSOLE_H


#include "../Services/Service.h"

class Console
{
private:
    Service service;

    void printOptions();
    char getOption();
    void add();
    void del();
    void update();
    void printAll();
    void biggestRectangle();
    void allInDialOne();
    void longestSequenceOfEquals();


public:
    Console() = default;
    ~Console() = default;

    void run();
};


#endif //LAB_6_CONSOLE_H
