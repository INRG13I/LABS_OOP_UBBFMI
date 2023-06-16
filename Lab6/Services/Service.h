//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#ifndef LAB_6_SERVICE_H
#define LAB_6_SERVICE_H


#include "../Repositories/RepositoryMap.h"
#include"../Repositories/Repository.h"
#include "../Rectangle/Rectangle.h"

class Service
{
private:
    RepositoryMap<Rectangle> repo;
public:
    Service() = default;
    ~Service() = default;

    void add(Rectangle newRectangle);
    void del(int position);
    void update(int position, Rectangle newRectangle);
    void printAll();
    Rectangle getFromPosition(int position);

    Rectangle biggestRectangle();
    Repository<Rectangle> longestSequenceOfEquals();
    Repository<Rectangle> allRectanglesInDialOne();

};


#endif //LAB_6_SERVICE_H
