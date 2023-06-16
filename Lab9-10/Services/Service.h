//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#ifndef LAB_9_10_SERVICE_H
#define LAB_9_10_SERVICE_H


#include "../Product/Product.h"
#include "../Transaction/Transaction.h"
#include "../Currency/Currency.h"
#include "../Repositories/Repository.h"


class Service
{
private:

    Repository<Product> productsList;
    Repository<Transaction> transactionList;
    Repository<Currency> currencyList;

public:

    Service() = default;
    ~Service() = default;

    void addProduct(Product product);
    void delProduct(int position);
    void updateProduct(int position, Product newProduct);

    int findProduct(Product product)const;

    Product getProductFromPosition(int position);
    std::vector<Product> getAllProduct()const;
    std::vector<Currency>getCurrency()const;
    std::vector<Transaction>getTransactions()const;


    void addTransaction(Transaction transaction);
    void buyProduct(int idProduct, Transaction transaction);


};


#endif //LAB_9_10_SERVICE_H
