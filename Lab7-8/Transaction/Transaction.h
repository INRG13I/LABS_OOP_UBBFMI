//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#ifndef LAB_8_TRANSACTION_H
#define LAB_8_TRANSACTION_H


#include "../String/String.h"
#include <iostream>

class Transaction
{
private:
    int day;
    String type;
    String description;
    int sum;

public:

    Transaction();
    Transaction(int newDay,String newType, int newSum, String newDescription);
    Transaction(const Transaction& newTransaction);

    void setType(String newType);
    void setDescription(String newDescription);
    void setSum(int newSum);
    void setDay(int newDay);

    String getType()const;
    String getDescription()const;
    int getSum()const;
    int getDay()const;



    Transaction& operator=(const Transaction& newTransaction);

    void print();

};


#endif //LAB_8_TRANSACTION_H
