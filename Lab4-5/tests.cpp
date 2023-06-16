//
// Created by Nicolaescu Raoul on 02.04.2023.
//

#include "tests.h"
#include "entity.h"
#include "repository.h"
#include "service.h"

#include "cassert"
#include <iostream>
#include <cmath>


void testEntity(){

    //Default
    Entity entity1;
    assert(entity1.getx1() == 0);
    assert(entity1.gety1() == 0);
    assert(entity1.getx2() == 0);
    assert(entity1.gety2() == 0);
    assert(entity1.getx3() == 0);
    assert(entity1.gety3() == 0);
    assert(entity1.getx4() == 0);
    assert(entity1.gety4() == 0);
    assert(entity1.getlatura() == 0);
    assert(entity1.getarie() == 0);
    assert(entity1.getdiagonala() == 0);

    //Parameter
    Entity entity2(0,10,10,10,10,0,0,0);
    assert(entity2.getx1() == 0);
    assert(entity2.gety1() == 10);
    assert(entity2.getx2() == 10);
    assert(entity2.gety2() == 10);
    assert(entity2.getx3() == 10);
    assert(entity2.gety3() == 0);
    assert(entity2.getx4() == 0);
    assert(entity2.gety4() == 0);
    assert(entity2.getlatura() == 10);
    assert(entity2.getarie() == 100);
    assert(entity2.getdiagonala() == 10*sqrt(2));

    //Copy
    Entity entity3(entity2);
    assert(entity3.getx1() == 0);
    assert(entity3.gety1() == 10);
    assert(entity3.getx2() == 10);
    assert(entity3.gety2() == 10);
    assert(entity3.getx3() == 10);
    assert(entity3.gety3() == 0);
    assert(entity3.getx4() == 0);
    assert(entity3.gety4() == 0);
    assert(entity3.getlatura() == 10);
    assert(entity3.getarie() == 100);
    assert(entity2.getdiagonala() == 10*sqrt(2));

    // = operator
    Entity entity4;
    entity4 = Entity(0,10,10,10,10,0,0,0);
    assert(entity4.getx1() == 0);
    assert(entity4.gety1() == 10);
    assert(entity4.getx2() == 10);
    assert(entity4.gety2() == 10);
    assert(entity4.getx3() == 10);
    assert(entity4.gety3() == 0);
    assert(entity4.getx4() == 0);
    assert(entity4.gety4() == 0);
    assert(entity4.getlatura() == 10);
    assert(entity4.getarie() == 100);
    assert(entity2.getdiagonala() == 10*sqrt(2));

    auto *entity5 = new Entity(0,10,10,10,10,0,0,0);
    assert(entity5->getx1() == 0);
    assert(entity5->gety1() == 10);
    assert(entity5->getx2() == 10);
    assert(entity5->gety2() == 10);
    assert(entity5->getx3() == 10);
    assert(entity5->gety3() == 0);
    assert(entity5->getx4() == 0);
    assert(entity5->gety4() == 0);
    assert(entity5->getlatura() == 10);
    assert(entity5->getarie() == 100);
    assert(entity2.getdiagonala() == 10*sqrt(2));

    std::cout << "********* ENTITY TESTS PASSED SUCCESFULLY *********" << std::endl;

}

void testRepository() {
    Repository repo;

    repo.addEntity(Entity(0,10,10,10,10,0,0,0));
    repo.addEntity(Entity(0,5,5,5,5,0,0,0));
    repo.addEntity(Entity(0,20,20,20,20,0,0,0));

    assert(repo.getEntityByPosition(0).getlatura() == 10);
    assert(repo.getEntityByPosition(1).getlatura()== 5);
    assert(repo.getEntityByPosition(2).getlatura() == 20);

    int repoSize = repo.getCurrentSize();
    assert(repoSize == 3);


    std::cout << "********** REPO TESTS PASSED SUCCESFULLY **********" << std::endl;
}

void testService(){
    Repository r;
    Service s;

    s.add_entity(r,0,10,0,0,10,0,10,10);
    s.add_entity(r,10,20,10,10,20,10,20,20);
    s.add_entity(r,0,10,0,0,10,0,10,10);
    s.add_entity(r,0,20,0,0,20,0,20,20);
    s.add_entity(r,0,30,0,0,30,0,30,30);
    s.add_entity(r,0,10,0,0,10,0,10,10);

    assert(r.getEntityByPosition(0).getx1() == 0);
    assert(r.getEntityByPosition(0).gety1() == 10);
    assert(r.getEntityByPosition(0).getx2() == 0);
    assert(r.getEntityByPosition(0).gety2() == 0);
    assert(r.getEntityByPosition(0).getx3() == 10);
    assert(r.getEntityByPosition(0).gety3() == 0);
    assert(r.getEntityByPosition(0).getx4() == 10);
    assert(r.getEntityByPosition(0).gety4() == 10);

    int p=s.biggest_entity(r);
    assert(p == 4);

    //todo test cadran 1
    Entity *m=s.all_form_dial1(r);

    assert(m[0].getx1() == 10);
    assert(m[0].gety1() == 20);
    assert(m[0].getx2() == 10);
    assert(m[0].gety2() == 10);
    assert(m[0].getx3() == 20);
    assert(m[0].gety3() == 10);
    assert(m[0].getx4() == 20);
    assert(m[0].gety4() == 20);

    Entity* v=s.max_sequence(r);

    assert(v[0].getx1() == 0);
    assert(v[0].gety1() == 10);
    assert(v[0].getx2() == 0);
    assert(v[0].gety2() == 0);
    assert(v[0].getx3() == 10);
    assert(v[0].gety3() == 0);
    assert(v[0].getx4() == 10);
    assert(v[0].gety4() == 10);

    assert(v[1].getx1() == 10);
    assert(v[1].gety1() == 20);
    assert(v[1].getx2() == 10);
    assert(v[1].gety2() == 10);
    assert(v[1].getx3() == 20);
    assert(v[1].gety3() == 10);
    assert(v[1].getx4() == 20);
    assert(v[1].gety4() == 20);

    assert(v[2].getx1() == 0);
    assert(v[2].gety1() == 10);
    assert(v[2].getx2() == 0);
    assert(v[2].gety2() == 0);
    assert(v[2].getx3() == 10);
    assert(v[2].gety3() == 0);
    assert(v[2].getx4() == 10);
    assert(v[2].gety4() == 10);



    std::cout << "********* SERVICE TESTS PASSED SUCCESFULLY ********" << std::endl;
}
