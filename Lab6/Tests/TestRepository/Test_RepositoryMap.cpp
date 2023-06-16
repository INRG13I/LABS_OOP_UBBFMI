//
// Created by Nicolaescu Raoul on 25.04.2023.
//

#include "Test_RepositoryMap.h"
#include "../../Repositories/RepositoryMap.h"
#include <assert.h>

void Test_RepositoryMap::testGetSize(){

RepositoryMap<int> repo;

assert(repo.getSize()==0);

}
void Test_RepositoryMap::testGetList(){


}
void Test_RepositoryMap::testSetList(){


}
void Test_RepositoryMap::testAddElement(){

    RepositoryMap<int> repo;

    repo.addElement(2);

    assert(repo.getElement(0)==2);

}
void Test_RepositoryMap::testDeleteElement(){
    RepositoryMap<int> repo;

    repo.addElement(2);
    repo.deleteElement(0);

    assert(repo.getSize()==0);

}

void Test_RepositoryMap::testUpdateElement(){

    RepositoryMap<int> repo;

    repo.addElement(2);

    repo.updateElement(0,5);

    assert(repo.getElement(0)==5);
}
void Test_RepositoryMap::testGetElement(){

    RepositoryMap<int> repo;

    repo.addElement(2);

    repo.updateElement(0,5);

    assert(repo.getElement(0)==5);

}
void Test_RepositoryMap::testFindElement(){

    RepositoryMap<int> repo;

    repo.addElement(2);

    repo.updateElement(0,5);
    assert(repo.findElement(5)==0);

}

void Test_RepositoryMap::testAll() {

    this->testGetSize();
    this->testGetList();
    this->testSetList();
    this->testAddElement();
    this->testDeleteElement();
    this-> testUpdateElement();
    this->testGetElement();
    this->testFindElement();
}