//
// Created by Nicolaescu Raoul on 08.05.2023.
//

#include <iostream>
#include <cassert>

#include "TestCurrency.h"

void TestCurrency::testDefaultConstructor() {

}

void TestCurrency::testCopyConstructor() {

}

void TestCurrency::testConstructors() {
    testDefaultConstructor();
    testCopyConstructor();
}

void TestCurrency::testGettersAndSetters() {

}

void TestCurrency::testOperators() {

}

void TestCurrency::testAll() {
    testConstructors();
    testGettersAndSetters();
    testOperators();

    std::cout<<"**************** TRANSACTION TESTS PASSED SUCCESFULLY ****************"<<std::endl;


}
