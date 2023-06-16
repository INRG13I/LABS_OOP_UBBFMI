//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#ifndef LAB_6_DOT_H
#define LAB_6_DOT_H


#include <iostream>

class Dot
{
private:
    int x;
    int y;
public:
    Dot();
    Dot(int newX, int newY);
    Dot(const Dot& newDot);

    ~Dot() = default;

    int getX() const;
    int getY() const;

    void setX(int newX);
    void setY(int newY);

    double distance(const Dot& newDot)const;
    bool isDialOne()const;

    Dot& operator=(const Dot newDot);


    friend std::istream& operator>>(std::istream& is, Dot& newDot);
    friend std::ostream& operator<<(std::ostream& os, const Dot& dot);

};


#endif //LAB_6_DOT_H
