//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#include "Product.h"

Product::Product()
{
    this->setPrice(0);
    this->setName(str("n/a"));
    this->setId(0);
}

Product::Product(str name, int price, int id)
{
    this->setName(name);
    this->setPrice(price);
    this->setId(id);
}

Product::Product(const Product& product)
{
    this->setId(product.getId());
    this->setName(product.getName());
    this->setPrice(product.getPrice());
}

void Product::setName(str newName)
{
    name = newName;
}

void Product::setId(int newId)
{
    id = newId;
}

void Product::setPrice(int newPrice)
{
    price = newPrice;
}

str Product::getName() const
{
    return name;
}

int Product::getId() const
{
    return id;
}

int Product::getPrice()const
{
    return price;
}

Product& Product::operator=(const Product& rProduct)
{
    if (this != &rProduct) {

        this->setPrice(rProduct.getPrice());
        this->setName(rProduct.getName());
        this->setId(rProduct.getId());
    }


    return *this;
}

bool Product::operator==(const Product& rProduct)
{
    if (this->getId() == rProduct.getId())return true;
    return false;
}

bool Product::operator<(const Product& rProduct)const{
    return this->getId()<rProduct.getId();
}

std::ostream& operator<<(std::ostream& os, const Product& product){
    os << product.getId() << " " << product.getName() << " " << product.getPrice();
    return os;
}

std::istream& operator>>(std::istream& is, const Product& product){

}
