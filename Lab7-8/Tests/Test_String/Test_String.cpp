//
// Created by Nicolaescu Raoul on 02.05.2023.
//

#include "Test_String.h"
#include "../../String/String.h"

#include <cassert>
#include <iostream>

void Test_String::testDefaultConstructor()
{
    String string;

    assert(string.getString() == nullptr);
}

void Test_String::testParameterConstructor()
{
    String string((char*)"string");

    assert(strcmp(string.getString(), "string") == 0);
}

void Test_String::testCopyConstructor()
{
    String string((char*) "string");

    String newString(string);

    assert(strcmp(newString.getString(), "string") == 0);
}

void Test_String::testAssignmentOperatorString()
{
    String string((char*)"string");
    String newString;

    newString = string;

    assert(strcmp(string.getString(), "string") == 0);
}

void Test_String::testAssignmentOperatorChar()
{
    String string;
    string = (char*)"string";

    assert(strcmp(string.getString(), "string") == 0);
}

void Test_String::testEqualityOperatorString()
{
    String stringOne((char*)"string");
    String stringTwo((char*)"string");
    String stringThree((char*)"char");

    assert(stringOne == stringTwo);
    assert(!(stringOne == stringThree));
}

void Test_String::testEqualityOperatorChar()
{
    String string((char*)"string");

    assert(string == (char*)"string");
    assert(!(string == (char*)"char"));
}

void Test_String::testAll()
{
    this->testDefaultConstructor();
    this->testParameterConstructor();
    this->testCopyConstructor();

    this->testAssignmentOperatorString();
    this->testAssignmentOperatorChar();

    this->testEqualityOperatorString();
    this->testEqualityOperatorChar();

    std::cout<<"********************STRING TESTS PASSED SUCCESFULLY********************"<<std::endl;
}
