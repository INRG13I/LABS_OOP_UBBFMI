#include <string>
#include <iostream>
#include "UI.h"

void Console::add()
{
    int sum;
    std::string name;
    int id;
    std::cout << "Name:";
    std::cin >> name;
    std::cout << "Sum:";
    std::cin >> sum;
    std::cout << "ID:";
    std::cin >> id;

    service.addProduct(Product(name,sum,id));

}

void Console::del()
{
    int position;

    std::cout << "Position:";
    std::cin >> position;

    service.delProduct(position);
}

void Console::update()
{
    int position;

    int sum;
    std::string name;
    int id;

    std::cout << "Position:";
    std::cin >> position;
    std::cout << "Name:";
    std::cin >> name;
    std::cout << "Sum:";
    std::cin >> sum;
    std::cout << "ID:";
    std::cin >> id;

    service.updateProduct(position, Product(name, sum, id));

}

void Console::printAll()
{
    std::vector<Product> list;

    list = service.getAllProduct();

    for (auto product : list) {
        std::cout << "Id: " << product.getId() << " ";
        std::cout << "Nume: " << product.getName() << " ";
        std::cout << "Pret: " << product.getPrice()<<"\n";
    }
    std::cout << "\n";
}

void Console::help()
{
    std::cout << "addProduct \n";
    std::cout << "addTransaction \n";
    std::cout << "updatePrdouct \n";
    std::cout << "deleteProduct \n";
    std::cout << "buyProduct\n";
    std::cout << "showProducts \n";
    std::cout << "showCash \n";
    std::cout << "showTransactions \n";
    std::cout << "exit \n";
    std::cout << "\n";
}

void Console::buyProduct()
{
    int idProduct,nrOfBills;

    Transaction newTransaction;
    newTransaction.setType((std::string)"in");

    std::vector<Currency> currency;

    std::cout << "ID of product you winat to buy:";
    std::cin >> idProduct;
    std::cout << "With how many types of bills you want to pay:";
    std::cin >> nrOfBills;

    for (int i = 0; i < nrOfBills; i++)
    {
        int value;
        int quantity;
        std::cout << "Value:";
        std::cin >> value;
        std::cout << "Quantity:";
        std::cin>> quantity;

        currency.push_back(Currency(value, quantity));

    }

    newTransaction.setCurrency(currency);

    service.buyProduct(idProduct, newTransaction);
}

void Console::showCurrency()
{
    std::vector<Currency> currencyList;

    currencyList = service.getCurrency();

    for (Currency currency : currencyList) {

        std::cout << "Value: " << currency.getValue() << " ";
        std::cout << "Quantity: " << currency.getQuantity() << " \n";
    }
    std::cout << "\n";
}

void Console::showTransactions()
{
    std::vector<Transaction> transactionList;

    transactionList = service.getTransactions();

    for (Transaction transaction : transactionList) {


        std::cout << "Type: " << transaction.getType() << "\n";

        std::vector<Currency> currencyList = transaction.getCurrency();

        for (Currency currency : currencyList)
        {
            std::cout << "	";
            std::cout << "Value: " << currency.getValue() << " ";
            std::cout << "Quantity: " << currency.getQuantity() << " \n";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Console::addTransaction()
{

    Transaction transaction;
    std::vector<Currency> currency;
    std::string type;
    int nrOfBills;

    std::cout << "Type:";
    std::cin >> type;
    std::cout << "Number of type of bills you want to add:";
    std::cin >> nrOfBills;

    for (int i = 0; i < nrOfBills; i++)
    {
        int value;
        int quantity;
        std::cout << "Value:";
        std::cin >> value;
        std::cout << "Quantity:";
        std::cin >> quantity;

        currency.push_back(Currency(value, quantity));

    }
    transaction.setType(type);
    transaction.setCurrency(currency);

    service.addTransaction(transaction);

}

void Console::run()
{
    std::string option;

    while (true) {
        help();
        std::cin >> option;

        std::cout << "\n";

        if (option == "addProduct") {
            this->add();
        }

        if (option == "updateProduct") {
            this->update();
        }

        if (option == "deleteProduct") {
            this->del();
        }

        if (option == "showProducts") {
            this->printAll();
        }

        if (option == "buyProduct") {
            this->buyProduct();
        }

        if (option == "showCash") {
            this->showCurrency();
        }

        if (option == "showTransactions") {
            this->showTransactions();
        }

        if (option == "addTransaction") {
            this->addTransaction();
        }

        if (option == "exit") {
            std::cout<<"Goodbye cruel world"<<std::endl;
            return;
        }



    }
}