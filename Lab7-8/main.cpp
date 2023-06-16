#include "UI/UI.h"
#include "Tests/Test_All/Test_All.h"


int main() {

    UI ui;
    Test_All testAll;

    testAll.test_all();

    ui.run();


    return 0;
}
