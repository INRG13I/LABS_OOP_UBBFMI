//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#ifndef LAB_6_RECTANGLE_H
#define LAB_6_RECTANGLE_H


#include <iostream>
#include "../Dot/Dot.h"

class Rectangle
{
private:
    Dot dotOne, dotTwo;
public:
    Rectangle() = default;
    Rectangle(Dot newDotOne, Dot newDotTwo);
    Rectangle(const Rectangle& newRectangle);

    ~Rectangle() = default;

    void setDotOne(Dot newDotOne);
    void setDotTwo(Dot newDotTwo);

    Dot getDotOne()const;
    Dot getDotTwo()const;

    double getLength()const;
    double getDepth()const;

    double getArea()const;
    double getPerimeter()const;
    double getDiagonal()const;
    bool isDialOne()const;
    bool operator>(const Rectangle& newRectangle)const;
    bool operator<(const Rectangle& newRectangle)const;
    bool operator==(const Rectangle& newRectangle)const;

    friend std::istream& operator>>(std::istream& is, Rectangle& newRectangle);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);

};


#endif //LAB_6_RECTANGLE_H
