//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#include "Rectangle.h"
#include "../Dot/Dot.h"


std::istream& operator>>(std::istream& is, Rectangle& newRectangle)
{
    is >> newRectangle.dotOne;
    is >> newRectangle.dotTwo;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
{
    os << "First dot coords: "<< rectangle.dotOne;
    os << "Second dot coords: "<< rectangle.dotTwo;
    os << "Length: " << rectangle.getLength()<<" Depth: "<<rectangle.getDepth()<<"\n";
    return os;
}

Rectangle::Rectangle(Dot newDotOne, Dot newDotTwo)
{
    this->setDotOne(newDotOne);
    this->setDotTwo(newDotTwo);
}

Rectangle::Rectangle(const Rectangle& newRectangle)
{
    this->setDotOne(newRectangle.getDotOne());
    this->setDotTwo(newRectangle.getDotTwo());
}

void Rectangle::setDotOne(Dot newDotOne)
{
    this->dotOne = newDotOne;
}

void Rectangle::setDotTwo(Dot newDotTwo)
{
    this->dotTwo = newDotTwo;
}

Dot Rectangle::getDotOne()const
{
    return this->dotOne;
}

Dot Rectangle::getDotTwo()const
{
    return this->dotTwo;
}

double Rectangle::getLength() const
{
    return abs(this->getDotOne().getX() - this->getDotTwo().getX());
}

double Rectangle::getDepth() const
{
    return abs(this->getDotOne().getY() - this->getDotTwo().getY());
}

double Rectangle::getArea() const
{
    return this->getLength()*this->getDepth();
}

double Rectangle::getPerimeter() const
{
    return (this->getLength() * 2) + (this->getDepth() * 2);
}

double Rectangle::getDiagonal() const
{
    return this->getDotOne().distance(this->getDotTwo());
}

bool Rectangle::isDialOne() const
{
    if (this->getDotOne().isDialOne() && this->getDotTwo().isDialOne()) {
        return true;
    }
    return false;
}

bool Rectangle::operator>(const Rectangle& newRectangle) const
{
    if (this->getArea() > newRectangle.getArea()) {
        return true;
    }
    return false;
}

bool Rectangle::operator<(const Rectangle& newRectangle) const
{

    if (this->getArea() < newRectangle.getArea()) {
        return true;
    }
    return false;
}

bool Rectangle::operator==(const Rectangle& newRectangle) const
{
    if (this->getLength() == newRectangle.getLength() && this->getDepth() == newRectangle.getDepth()) {
        return true;
    }
    if (this->getLength() == newRectangle.getDepth() && this->getDepth() == newRectangle.getLength()) {
        return true;
    }
    return false;
}
