//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#include "Currency.h"


Currency::Currency()
{
    this->setValue(0);
    this->setQuantity(0);
}

Currency::Currency(int newValue, int newQuantity)
{
    this->setValue(newValue);
    this->setQuantity(newQuantity);
}

Currency::Currency(const Currency& newCurrency)
{
    this->setValue(newCurrency.getValue());
    this->setQuantity(newCurrency.getQuantity());
}

int Currency::getValue() const
{
    return value;
}

int Currency::getQuantity() const
{
    return quantity;
}

void Currency::setValue(int newValue)
{
    value = newValue;
}

void Currency::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

int Currency::getSum() const
{
    return this->getValue()*this->getQuantity();
}

Currency& Currency::operator=(const Currency& rCurrency)
{
    if (this != &rCurrency) {

        this->setValue(rCurrency.getValue());
        this->setQuantity(rCurrency.getQuantity());

    }



    return *this;
}

bool Currency::operator==(const Currency& rCurrency)
{
    return this->getValue()==rCurrency.getValue();
}

bool Currency::operator<(const Currency& rCurrency) const
{
    return this->getValue() < rCurrency.getValue();
}

