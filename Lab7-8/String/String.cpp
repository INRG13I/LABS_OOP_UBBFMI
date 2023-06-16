//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#include "String.h"
#include <cstring>
String::String()
{

    string = nullptr;
}

String::String(char* newString)
{

    if (newString != nullptr) {

        size_t strLen = strlen(newString)+1;
        string = new char[strLen];

        strncpy(string , newString , strLen -1);
        // strncpy_s(string, strLen, newString, strLen - 1);

    }
    else
    {
        string = nullptr;
    }

}

String::String(const String& newString)
{

    if (newString.getString() != nullptr) {

        size_t strLen = strlen(newString.getString()) + 1;
        string = new char[strLen];

        strncpy(string, newString.getString(), strLen - 1);
        //strncpy_s(string, strLen, newString.getString(), strLen - 1);

    }
    else
    {
        string = nullptr;
    }

}

String::~String()
{
    delete[] string;
    string = nullptr;
}


char* String::getString() const
{
    return string;
}

size_t String::len() const
{
    return strlen(string);
}

String& String::operator=(const String& rString)
{

    if (this != &rString) {
        if (string != nullptr) {
            delete[] string;
        }

        if (rString.getString() != nullptr) {

            size_t strLen = strlen(rString.getString()) + 1;
            string = new char[strLen];

            strncpy(string, rString.getString(), strLen - 1);
            //strncpy_s(string, strLen, rString.getString(), strLen - 1);

        }
        else
        {
            string = nullptr;
        }

    }

    return *this;
}

String& String::operator=(char* rString)
{

    if (string != nullptr) {
        delete[] string;
    }

    if (rString!= nullptr) {

        size_t strLen = strlen(rString) + 1;
        string = new char[strLen];

        strncpy(string, rString, strLen - 1);
        //strncpy_s(string, strLen, rString, strLen - 1);

    }
    else
    {
        string = nullptr;
    }
    return *this;
}

bool String::operator==(const String& rString)
{
    if (strcmp(this->getString(), rString.getString()) == 0) {
        return true;
    }
    return false;
}

bool String::operator==(char* rString)
{
    if (strcmp(this->getString(), rString) == 0) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, String string)
{
    os << string.string;
    return os;
}
