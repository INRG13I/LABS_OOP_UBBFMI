//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_CURRENCY_H
#define LAB_FINAL_CURRENCY_H


#include<iostream>
#include<string>

class Currency
{
private:

    int value;
    int quantity;

public:

    Currency();
    Currency(int newValue, int newQuantity);
    Currency(const Currency& newCurrency);

    ~Currency()=default;

    int getValue()const;
    int getQuantity()const;

    void setValue(int newValue);
    void setQuantity(int newQuantity);

    int getSum()const;

    Currency& operator=(const Currency& rCurrency);
    bool operator==(const Currency& rCurrency);

    bool operator<(const Currency& rCurrency) const;

    friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
    friend std::istream& operator>>(std::istream& is, Currency& currency);


};


#endif //LAB_FINAL_CURRENCY_H
