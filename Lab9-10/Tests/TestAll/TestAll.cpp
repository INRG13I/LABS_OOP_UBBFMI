//
// Created by Nicolaescu Raoul on 08.05.2023.
//

#include "TestAll.h"
#include "../TestProduct/TestProduct.h"
#include "../TestCurrency/TestCurrency.h"
#include "../TestTransaction/TestTransaction.h"
#include "../TestRepository/TestRepository.h"
#include "../TestService/TestService.h"

void TestAll::testAll() {
    TestProduct testProduct;
    TestCurrency testCurrency;
    TestTransaction testTransaction;

    TestRepository testRepository;
    TestService testService;

    testCurrency.testAll();
    testTransaction.testAll();
    testProduct.testAll();
    testRepository.testAll();
    testService.testAll();
}
