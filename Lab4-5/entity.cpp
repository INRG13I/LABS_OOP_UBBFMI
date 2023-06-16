//
// Created by Nicolaescu Raoul on 02.04.2023.
//

#include "entity.h"
#include <cmath>
//#include <iostream>

//---------------------------Constructor---------------------------//

Entity::Entity() {

    //std::cout<<"Default constructor entity"<<std::endl;
    x1=0;
    y1=0;
    x2=0;
    y2=0;
    x3=0;
    y3=0;
    x4=0;
    y4=0;
    latura=0;
    arie=0;
    diagonala=0;
}

Entity::Entity(double px1, double py1, double px2, double py2, double px3, double py3, double px4, double py4) {

    //std::cout<<"Parameter constructor entity"<<std::endl;
    this->x1=px1;
    this->y1=py1;
    this->x2=px2;
    this->y2=py2;
    this->x3=px3;
    this->y3=py3;
    this->x4=px4;
    this->y4=py4;
    double lenght = sqrt(pow((this->x2-this->x1),2) + pow((this->y2-this->y1),2));
    latura=lenght;
    arie=latura*latura;
    diagonala=latura*sqrt(2);
}

Entity::Entity(Entity &p) {

    //std::cout<<"Copy constructor entity"<<std::endl;
    if(&p != nullptr)
    {
        this->x1=p.x1;
        this->y1=p.y1;
        this->x2=p.x2;
        this->y2=p.y2;
        this->x3=p.x3;
        this->y3=p.y3;
        this->x4=p.x4;
        this->y4=p.y4;
        latura=p.latura;
        arie=p.arie;
        diagonala=p.diagonala;
    }
}

Entity::~Entity()
= default;

//------------------------Getters & Setters------------------------//

double Entity::getlatura() {
    return this->latura;
}

double Entity::getarie() {
    return this->arie;
}

double Entity::getdiagonala() {
    return this->diagonala;
}

double Entity::getx1() {
    return this->x1;
}

double Entity::gety1() {
    return this->y1;
}

double Entity::getx2() {
    return this->x2;
}

double Entity::gety2() {
    return this->y2;
}

double Entity::getx3() {
    return this->x3;
}

double Entity::gety3() {
    return this->y3;
}

double Entity::getx4() {
    return this->x4;
}

double Entity::gety4() {
    return this->y4;
}

void Entity::setx1(double value) {
    this->x1 = value;
    this->latura = sqrt(pow((this->x2-this->x1),2) + pow((this->y2-this->y1),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x3-this->x1),2) + pow((this->y3-this->y1),2));
}

void Entity::sety1(double value) {
    this->y1 = value;
    this->latura = sqrt(pow((this->x2-this->x1),2) + pow((this->y2-this->y1),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x3-this->x1),2) + pow((this->y3-this->y1),2));
}

void Entity::setx2(double value) {
    this->x2 = value;
    this->latura = sqrt(pow((this->x2-this->x1),2) + pow((this->y2-this->y1),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x4-this->x2),2) + pow((this->y4-this->y2),2));
}

void Entity::sety2(double value) {
    this->y2 = value;
    this->latura = sqrt(pow((this->x2-this->x1),2) + pow((this->y2-this->y1),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x4-this->x2),2) + pow((this->y4-this->y2),2));
}

void Entity::setx3(double value) {
    this->x3 = value;
    this->latura = sqrt(pow((this->x2-this->x3),2) + pow((this->y2-this->y3),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x3-this->x1),2) + pow((this->y3-this->y1),2));
}

void Entity::sety3(double value) {
    this->y3 = value;
    this->latura = sqrt(pow((this->x2-this->x3),2) + pow((this->y2-this->y3),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x3-this->x1),2) + pow((this->y3-this->y1),2));
}

void Entity::setx4(double value) {
    this->x4 = value;
    this->latura = sqrt(pow((this->x4-this->x1),2) + pow((this->y4-this->y1),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x4-this->x2),2) + pow((this->y4-this->y2),2));
}

void Entity::sety4(double value) {
    this->y4 = value;
    this->latura = sqrt(pow((this->x2-this->x1),2) + pow((this->y2-this->y1),2));
    this->arie = pow(this->latura, 2);
    this->diagonala = sqrt(pow((this->x4-this->x2),2) + pow((this->y4-this->y2),2));
}

//----------------------------Overloads----------------------------//

Entity &Entity::operator=(const Entity &otherEntity) {
    //std::cout << "Using = operator" << std::endl;
    if (this == &otherEntity) {
        return *this;
    }

    this->x1=otherEntity.x1;
    this->y1=otherEntity.y1;
    this->x2=otherEntity.x2;
    this->y2=otherEntity.y2;
    this->x3=otherEntity.x3;
    this->y3=otherEntity.y3;
    this->x4=otherEntity.x4;
    this->y4=otherEntity.y4;
    this->latura = otherEntity.latura;
    this->arie=otherEntity.arie;
    this->diagonala=otherEntity.diagonala;

    return *this;
}

bool Entity::operator==(const Entity &s) {
    return ((this->latura == s.latura) && (this->arie == s.arie) && (this->diagonala == s.diagonala));
}

bool Entity::operator<(const Entity &e1) {
    return (this->latura < e1.latura);
}
