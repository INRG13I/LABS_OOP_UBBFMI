#include "String.h"
#include "Test_Service.h"
#include "../../Services/Service.h"
#include <assert.h>

void TestService::testAdd()
{
    Service service;

    String type((char*)"in");
    String description((char*)"salar");

    Transaction transaction(10, type, 100, description);

    service.add(transaction);

    assert(service.getAll().getSize() == 1);

}

void TestService::testDel()
{
    Service service;

    String type((char*)"in");
    String description((char*)"salar");

    Transaction transaction(10, type, 100, description);

    service.add(transaction);

    service.del(11, 20);

    assert(service.getAll().getSize() == 1);

    service.del(5, 11);

    assert(service.getAll().getSize() == 0);

}

void TestService::testUpdate()
{
    Service service;

    String type((char*)"in");
    String description((char*)"salar");

    Transaction transaction(10, type, 100, description);

    service.add(transaction);


   // service.update(10, description, 20);

    //assert(service.get(0).getSum() == 20);
}

void TestService::testGetAll()
{
    Service service;

    String type((char*)"in");
    String description((char*)"salar");

    Transaction transaction(10, type, 100, description);

    service.add(transaction);

    assert(service.getAll().getSize() == 1);
}

void TestService::testFetch()
{
    Service service;

    String type((char*)"in");
    String description((char*)"salar");

    Transaction transaction(10, type, 100, description);

    service.add(transaction);


    assert(service.fetch(100, '=').getSize() == 1);
    assert(service.fetch(9, '<').getSize() == 0);
    assert(service.fetch(101, '>').getSize() == 0);
}

void TestService::testAll()
{
    this->testAdd();
    this->testDel();
    this->testUpdate();
    this->testGetAll();
    this->testFetch();

    std::cout<<"SERVICE TESTS PASSED SUCCESFULLY"<<std::endl;
}