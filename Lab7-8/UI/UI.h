//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#ifndef LAB_8_UI_H
#define LAB_8_UI_H


#include "../Services/Service.h"

class UI {
private:

    Service service;

    void printMenu();
    void add1();
    void add2();
    void del1();
    void del2();
    void del3();
    void printAll();
    void print1();
    void print2();
    void print3();
    void print4();
    void print5();
    void update();
    void filter1();
    void filter2();



public:
    void console();
    void run();
};


#endif //LAB_8_UI_H
