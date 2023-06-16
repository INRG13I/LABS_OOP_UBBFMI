//
// Created by Nicolaescu Raoul on 02.05.2023.
//

#ifndef LAB_8_TEST_STRING_H
#define LAB_8_TEST_STRING_H


class Test_String
{
private:

    void testDefaultConstructor();
    void testParameterConstructor();
    void testCopyConstructor();

    void testAssignmentOperatorString();
    void testAssignmentOperatorChar();

    void testEqualityOperatorString();
    void testEqualityOperatorChar();

public:

    void testAll();
};


#endif //LAB_8_TEST_STRING_H
