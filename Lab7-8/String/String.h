//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#ifndef LAB_8_STRING_H
#define LAB_8_STRING_H

#include <iostream>

class String
{
private:

    char* string;

public:

    String();
    String(char* newString);
    String(const String& newString);
    ~String();

    char* getString()const;
    size_t len()const;

    String& operator= (const String& rString);
    String& operator= (char* rString);

    bool operator==(const String& rString);
    bool operator==(char* rString);

    friend std::ostream& operator<<(std::ostream& os, String string);
};


#endif //LAB_8_STRING_H
