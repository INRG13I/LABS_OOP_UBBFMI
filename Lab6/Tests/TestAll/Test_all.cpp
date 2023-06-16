//
// Created by Nicolaescu Raoul on 25.04.2023.
//

#include "Test_all.h"
#include "../TestEntity/Test_Entity.h"
#include "../TestRepository/Test_RepositoryMap.h"
#include "../TestService/Test_Service.h"

void test_all(){
    Test_Entity te;
    te.test_entity();
    Test_Service ts;
    ts.test_service();
    Test_RepositoryMap trm;
    trm.testAll();

}