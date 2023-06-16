//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#ifndef LAB_9_10_PRODUCT_H
#define LAB_9_10_PRODUCT_H


#include<string>

typedef std::string  str;

class Product
{
private:

    str name;
    int id;
    int price;

public:

    Product();
    Product(str name, int price, int id);
    Product(const Product& product);

    ~Product() = default;

    void setName(str newName);
    void setId(int newId);
    void setPrice(int newPrice);

    str getName()const;
    int getId()const;
    int getPrice()const;

    Product& operator=(const Product& rProduct);

    bool operator==(const Product& rProduct);

    bool operator< (const Product& rProduct)const;

    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    friend std::istream& operator>>(std::istream& is, const Product& product);
};





#endif //LAB_9_10_PRODUCT_H
