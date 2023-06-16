//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#include <math.h>
#include "Dot.h"

Dot::Dot()
{
    this->setX(0);
    this->setY(0);
}

Dot::Dot(int newX, int newY)
{
    this->setX(newX);
    this->setY(newY);
}

Dot::Dot(const Dot& newDot)
{
    this->setX(newDot.getX());
    this->setY(newDot.getY());
}

int Dot::getX() const
{
    return this->x;
}

int Dot::getY() const
{
    return this->y;
}

void Dot::setX(int newX)
{
    this->x = newX;
}

void Dot::setY(int newY)
{
    this->y = newY;
}

double Dot::distance(const Dot& newDot)const
{
    double xDistance = pow(this->getX() - newDot.getX(), 2);
    double yDistance = pow(this->getY() - newDot.getY(), 2);
    return sqrt(xDistance + yDistance);
}

bool Dot::isDialOne() const
{
    if (this->getX() >= 0 && this->getY() >= 0) {
        return true;
    }
    return false;
}

Dot& Dot::operator=(const Dot newDot)
{
    if (this != &newDot) {
        this->setX(newDot.getX());
        this->setY(newDot.getY());
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Dot& newDot)
{
    std::cout << "X coord: ";
    is >> newDot.x;
    std::cout << "Y coord: ";
    is >> newDot.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Dot& dot)
{
    os << "X coord: " << dot.x << " Y coord: " << dot.y << "\n";
    return os;
}