//
// Created by Nicolaescu Raoul on 02.04.2023.
//

#ifndef LAB5_ENTITY_H
#define LAB5_ENTITY_H

/*
 *      x1,y1            x4,y4
 *
 *
 *      x2,y2            x3,y3
 */

class Entity {

private:

    double x1=-1;
    double y1=-1;
    double x2=-1;
    double y2=-1;
    double x3=-1;
    double y3=-1;
    double x4=-1;
    double y4=-1;
    double latura;
    double arie;
    double diagonala;

public:
    Entity();
    Entity(double x1,double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    Entity(Entity &p);
    ~Entity();

    double getlatura();
    double getdiagonala();
    double getarie();
    double getx1();
    double gety1();
    double getx2();
    double gety2();
    double getx3();
    double gety3();
    double getx4();
    double gety4();

    void setx1(double value);
    void sety1(double value);
    void setx2(double value);
    void sety2(double value);
    void setx3(double value);
    void sety3(double value);
    void setx4(double value);
    void sety4(double value);

    // Overloads
    Entity &operator=(const Entity &otherEntity);
    bool operator<(const Entity &e1);
    bool operator==(const Entity &s);

};


#endif //LAB5_ENTITY_H
