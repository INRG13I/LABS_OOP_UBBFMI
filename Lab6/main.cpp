#include "UI/Console.h"
#include "Tests/TestAll/Test_all.h"

int main() {

    Console console;
    test_all();


    console.run();

    return 0;

}