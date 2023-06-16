//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#include "Transaction.h"

Transaction::Transaction()
{
    sum = 0;
    day = 0;
}

Transaction::Transaction(int newDay,String newType, int newSum, String newDescription)
{
    this->setDay(newDay);
    this->setType(newType);
    this->setSum(newSum);
    this->setDescription(newDescription);
}

Transaction::Transaction(const Transaction& newTransaction)
{
    this->setDay(newTransaction.getDay());
    this->setType(newTransaction.getType());
    this->setSum(newTransaction.getSum());
    this->setDescription(newTransaction.getDescription());
}

void Transaction::setType(String newType)
{
    type = newType;
}

void Transaction::setDescription(String newDescription)
{
    description = newDescription;
}

void Transaction::setSum(int newSum)
{
    sum = newSum;
}

void Transaction::setDay(int newDay)
{
    day = newDay;
}

String Transaction::getType() const
{
    return type;
}

String Transaction::getDescription() const
{
    return description;
}

int Transaction::getSum() const
{
    return sum;
}

int Transaction::getDay() const
{
    return day;
}



Transaction& Transaction::operator=(const Transaction& newTransaction)
{
    if (this != &newTransaction) {

        this->setType(newTransaction.getType());
        this->setSum(newTransaction.getSum());
        this->setDescription(newTransaction.getDescription());
        this->setDay(newTransaction.getDay());
    }
    return *this;
}

void Transaction::print()
{
    std::cout << "Day: " << this->getDay() << "\n";
    std::cout << "Type: " << this->getType() << "\n";
    std::cout << "Sum: " << this->getSum() << "\n";
    std::cout << "Description: " << this->getDescription() << "\n";
}

