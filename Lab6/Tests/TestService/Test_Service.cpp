//
// Created by Nicolaescu Raoul on 25.04.2023.
//

#include "Test_Service.h"
#include "../../Services/Service.h"
#include "../../Repositories/RepositoryMap.h"
#include "../../Rectangle/Rectangle.h"
#include "../../Dot/Dot.h"


void Test_Service::test_CRUD() {
    RepositoryMap<Rectangle> repositoryMap;
    Rectangle r(Dot(1,10),Dot(2,20));
    Rectangle g(Dot(2,2),Dot(3,3));
    Rectangle h(Dot(1,1),Dot(2,2));
    repositoryMap.addElement(r);
    repositoryMap.addElement(g);
    repositoryMap.addElement(h);
    assert(repositoryMap.getElement(0)==r);
    assert(repositoryMap.findElement(r) == 0);
    repositoryMap.updateElement(0,g);
    assert(repositoryMap.getElement(0) == g);
    repositoryMap.deleteElement(1);
    assert(repositoryMap.getElement(1) == h);
    repositoryMap.updateElement(1,g);




}

void Test_Service::test_biggest_rectangle() {
    Rectangle r(Dot(1,10),Dot(2,20));
    Rectangle g(Dot(2,2),Dot(3,3));
    Rectangle h(Dot(1,1),Dot(2,2));
    Service service;
    service.add(r);
    service.add(g);
    service.add(h);


    assert(service.biggestRectangle() == r);

}

void Test_Service::test_longest_sequence_of_equals() {
    Rectangle r(Dot(1,10),Dot(2,20));
    Rectangle g(Dot(2,2),Dot(3,3));
    Rectangle h(Dot(1,1),Dot(2,2));
    Service service;
    service.add(r);
    service.add(g);
    service.add(h);

    assert(service.longestSequenceOfEquals().getElement(1) == g);
}

void Test_Service::test_all_from_dial_one() {
    Rectangle r(Dot(1,10),Dot(2,20));
    Rectangle g(Dot(2,2),Dot(3,3));
    Rectangle h(Dot(1,1),Dot(2,2));
    Service service;
    service.add(r);
    service.add(g);
    service.add(h);

    assert(service.allRectanglesInDialOne().getElement(0) == r);

}

void Test_Service::test_service() {
    test_CRUD();
    test_biggest_rectangle();
    test_longest_sequence_of_equals();
    test_all_from_dial_one();

}
