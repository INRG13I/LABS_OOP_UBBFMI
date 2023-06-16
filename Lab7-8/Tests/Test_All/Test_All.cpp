//
// Created by Nicolaescu Raoul on 02.05.2023.
//

#include "Test_All.h"
#include "../Test_String/Test_String.h"
#include "../Test_Service/Test_Service.h"

void Test_All::test_all() {
    Test_String testString;
    TestService testService;

    testString.testAll();
    testService.testAll();
}
