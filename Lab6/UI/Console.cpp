//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#include <iostream>
#include "../Rectangle/Rectangle.h"
#include "../Repositories/Repository.h"
#include "../Services/Service.h"
#include "Console.h"

void Console::printOptions()
{
    std::cout << "1. Add. \n";
    std::cout << "2. Delete. \n";
    std::cout << "3. Update. \n"; // TODO : Debug
    std::cout << "4. Biggest Rectangle. \n";
    std::cout << "5. Longest sequence of equal Rectangles. \n";
    std::cout << "6. All rectangles in dial one. \n";
    std::cout << "7. Print all \n";

}

char Console::getOption()
{
    char option;
    std::cout << "Select option: ";
    std::cin >> option;
    std::cout << "\n";
    return option;
}

void Console::add()
{
    Rectangle rectangle;
    std::cin >> rectangle;
    std::cout << "\n";

    service.add(rectangle);
}

void Console::del()
{
    int position;
    std::cout << "Position of Rectangle: ";
    std::cin >> position;
    std::cout << "\n";

    service.del(position);
}

void Console::update()
{
    int position;
    std::cout << "Position of update: ";
    std::cin >> position;
    std::cout << "\n";

    service.del(position);

    Rectangle rectangle;
    std::cin >> rectangle;
    std::cout << "\n";

    service.update(position,rectangle);
}

void Console::printAll()
{
    service.printAll();

}

void Console::biggestRectangle()
{
    Rectangle rectangle;
    rectangle = service.biggestRectangle();
    std::cout << rectangle << "\n";
}

void Console::allInDialOne()
{
    Repository<Rectangle> temp;
    temp = service.allRectanglesInDialOne();
    temp.printAll();
}

void Console::longestSequenceOfEquals()
{
    Repository<Rectangle> temp;
    temp = service.longestSequenceOfEquals();
    temp.printAll();
}

void Console::run()
{
    while (true)
    {
        this->printOptions();
        switch (this->getOption())
        {
            case'1':
                this->add();
                break;
            case'2':
                this->del();
                break;
            case'3':
                this->update();
                break;
            case'4':
                this->biggestRectangle();
                break;
            case'5':
                this->longestSequenceOfEquals();
                break;
            case'6':
                this->allInDialOne();
                break;
            case '7':
                this->printAll();
                break;
            default:
                return;
                break;
        }
    }
}

