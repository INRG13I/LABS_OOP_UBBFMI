//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#ifndef LAB_9_10_TRANSACTION_H
#define LAB_9_10_TRANSACTION_H

#include"../Currency/Currency.h"
#include <string>
#include <vector>

class Transaction
{
private:

    std::string type;
    std::vector<Currency> currencyList;

public:

    Transaction();
    Transaction(const Transaction& newTransaction);

    ~Transaction() = default;

    std::string getType()const;
    std::vector<Currency> getCurrency()const;

    void setType(std::string newType);
    void setCurrency(std::vector<Currency> newCurrencyList);

    void addCurrency(Currency newCurrency);

    int getTransactionSum()const;

    Transaction& operator=(const Transaction& rTransaction);

    bool operator==(const Transaction& rTransaction);

    bool operator<(const Transaction& rTransaction)const;
};


#endif //LAB_9_10_TRANSACTION_H
