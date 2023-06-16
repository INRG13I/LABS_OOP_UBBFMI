 //
// Created by Nicolaescu Raoul on 06.05.2023.
//

#ifndef LAB_9_10_CURRENCY_H
#define LAB_9_10_CURRENCY_H

#include <iostream>

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

     bool operator<(const Currency& rCurrency)const;

     friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
     friend std::istream& operator>>(std::istream& is, const Currency& currency);
 };



#endif //LAB_9_10_CURRENCY_H
