
#include "Tests/TestAll/TestAll.h"
#include "UI/UI.h"


int main() {
    TestAll testAll;
    Console ui;

    testAll.testAll();
    ui.run();

    return 0;
}
