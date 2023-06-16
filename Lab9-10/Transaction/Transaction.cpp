//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#include "Transaction.h"


Transaction::Transaction()
{
    type = "N/A";
}

Transaction::Transaction(const Transaction& newTransaction)
{
    type = newTransaction.getType();
    currencyList = newTransaction.getCurrency();
}

std::string Transaction::getType() const
{
    return type;
}

std::vector<Currency> Transaction::getCurrency() const
{
    return currencyList;
}

void Transaction::setType(std::string newType)
{
    type = newType;
}

void Transaction::setCurrency(std::vector<Currency> newCurrencyList)
{
    currencyList = newCurrencyList;
}

void Transaction::addCurrency(Currency newCurrency)
{
    currencyList.push_back(newCurrency);
}

int Transaction::getTransactionSum() const
{
    int sum = 0;

    for (Currency currency : currencyList) {

        sum += currency.getSum();

    }
    return sum;
}

Transaction& Transaction::operator=(const Transaction& rTransaction)
{
    if (this != &rTransaction) {

        this->setType(rTransaction.getType());
        this->setCurrency(rTransaction.getCurrency());
    }


    return *this;
}

bool Transaction::operator==(const Transaction& rTransaction)
{
    return false;
}

bool Transaction::operator<(const Transaction &rTransaction) const {
    return this->getTransactionSum() < rTransaction.getTransactionSum();
}

