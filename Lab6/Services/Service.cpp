//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#include "Service.h"

void Service::add(Rectangle newRectangle)
{
    repo.addElement(newRectangle);
}

void Service::del(int position)
{
    repo.deleteElement(position);
}

void Service::update(int position, Rectangle newRectangle)
{
    repo.updateElement(position, newRectangle);
}

void Service::printAll()
{
    repo.printAll();
}

Rectangle Service::getFromPosition(int position)
{
    return repo.getElement(position);
}

Rectangle Service::biggestRectangle()
{
    Rectangle max;
    for (int i = 0; i < repo.getSize(); i++)
    {
        if (repo.getElement(i) > max) {
            max = repo.getElement(i);
        }
    }
    return max;
}

Repository<Rectangle> Service::longestSequenceOfEquals()
{
    int maxlen = 0, pos = 0, len = 1;
    for (int i = 0; i < repo.getSize() - 1; i++)
    {
        if (repo.getElement(i) == repo.getElement(i + 1)) {
            len++;
        }
        else
        {
            if (len > maxlen) {
                maxlen = len;
                pos = i - len + 1;
            }
            len = 1;
        }
    }

    if (len > maxlen) {
        maxlen = len;
        pos = repo.getSize() - len;
    }

    Repository<Rectangle> temp;

    for (int i = pos; i < pos+maxlen; i++)
    {
        temp.addElement(repo.getElement(i));
    }

    return temp;
}

Repository<Rectangle> Service::allRectanglesInDialOne()
{
    Repository<Rectangle> temp;

    for (int i = 0; i < repo.getSize(); i++)
    {
        if (repo.getElement(i).isDialOne()) {
            temp.addElement(repo.getElement(i));
        }
    }

    return temp;
}
