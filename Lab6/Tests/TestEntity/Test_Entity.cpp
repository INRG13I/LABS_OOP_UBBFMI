//
// Created by Nicolaescu Raoul on 25.04.2023.
//

#include "Test_Entity.h"
#include "../../Rectangle/Rectangle.h"
#include "../../Dot/Dot.h"

void Test_Entity::test_constructors() {

    Rectangle g;
    assert(g.getDotOne().getX() == 0);
    assert(g.getPerimeter() == 0);
    assert(g.getArea() == 0);
    assert(g.getDiagonal() == sqrt(0));

    Rectangle r(Dot(1,1),Dot(2,2));
    assert(r.getDotOne().getX() == 1);
    assert(r.getPerimeter() == 4);
    assert(r.getArea() == 1);
    assert(r.getDiagonal() == sqrt(2));

}

void Test_Entity::test_getters() {
    Rectangle r(Dot(1,1),Dot(2,2));
    assert(r.getDotOne().getX() == 1);
    assert(r.getPerimeter() == 4);
    assert(r.getArea() == 1);
    assert(r.getDiagonal() == sqrt(2));
    assert(r.getDepth() == 1);
    assert(r.getLength() == 1);
}

void Test_Entity::test_operators() {
    Rectangle r(Dot(1,10),Dot(2,20));
    Rectangle g(Dot(2,2),Dot(3,3));
    assert((r>g) == true);
    Rectangle h(Dot(1,1),Dot(2,2));
    assert((g==h) == true);

}

void Test_Entity::test_entity() {
    test_constructors();
    test_getters();
    test_operators();


}


