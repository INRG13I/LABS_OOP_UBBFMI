//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#include "UI.h"
#include "../List/List.h"
#include "../Transaction/Transaction.h"

#include <iostream>
#include <cstring>

using namespace std;

void UI::printMenu()
{
    cout << "1. Add transaction with sum, type and description"<<endl;
    cout << "2. Add transaction with day, sum, type, and dexcription"<<endl;
    cout << "3. Delete transactions from day"<< endl;
    cout << "4. Delete transactions between lday and rday"<<endl;
    cout << "5. Delete transaction by type"<<endl;
    cout << "6. Update transaction from day with type and description with new sum"<<endl;
    cout << "7. Print all"<<endl;
    cout << "8. Print by type"<<endl;
    cout << "9. Print by criteria and sum"<<endl;
    cout << "10. Print sold from day"<<endl;
    cout << "11. Print sum of type"<<endl;
    cout << "12. Print max transaction with type from day"<<endl;
    cout << "13. Filter by type"<<endl;
    cout << "14. Filter by type and sum"<<endl;
    cout << "15. Undo"<<endl;
    cout << "Orice alt numar. Exit"<<endl;
}

void UI::add1()
{
    char type[4];
    char description[30];
    int sum;
    int day = 2;


    std::cout << "Insert type (in/out): ";
    std::cin >> type;
    std::cout << "\n";

    std::cout << "Insert sum: ";
    std::cin >> sum;
    std::cout << "\n";

    std::cout << "Insert description: ";
    std::cin >> description;
    std::cout << "\n";

    String typeStr(type);
    String descriptionStr(description);

    Transaction transaction(day, typeStr, sum, descriptionStr);

    service.add(transaction);
}

void UI::add2() {
    char type[4];
    char description[30];
    int sum;
    int day;

    std::cout << "Insert day: ";
    std::cin >> day;
    std::cout << "\n";
    std::cout << "Insert type (in/out): ";
    std::cin >> type;
    std::cout << "\n";

    std::cout << "Insert sum: ";
    std::cin >> sum;
    std::cout << "\n";

    std::cout << "Insert description: ";
    std::cin >> description;
    std::cout << "\n";

    String typeStr(type);
    String descriptionStr(description);

    Transaction transaction(day, typeStr, sum, descriptionStr);

    service.add(transaction);
}

void UI::del1()
{
    int day;

    std::cout << "Type day of deleted transaction: ";
    std::cin >> day;
    std::cout << "\n";

    service.del(day);
}

void UI::del2() {
    int lday, rday;

    cout << "Type lday of deleted transactions: ";
    cin >> lday;
    cout << endl;
    cout << "Type rday of deleted transactions: ";
    cin >> rday;
    cout << endl;

    service.del(lday, rday);
}

void UI::del3() {
    char temp[30];

    cout << "Type type of deleted transactions: ";
    cin >> temp;

    String type = String(temp);


    service.del(type);
}

void UI::printAll()
{
    List<Transaction> list;

    list = service.getAll();

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << "Position: " << i << "\n";
        std::cout << "Element:\n";
        list.getElement(i).print();
        std::cout << "\n";

    }

}

void UI::print1() {
    List<Transaction> list;

    list = service.getAll();

    char type[4];
    cout<<"Type:";
    cin>>type;
    cout<<endl;


    for (int i = 0; i < list.getSize(); i++)
    {
        if(type == list.getElement(i).getType()){
            std::cout << "Position: " << i << "\n";
            std::cout << "Element:\n";
            list.getElement(i).print();
            std::cout << "\n";
        }


    }
}

void UI::print2() {
    int sum;
    char criteria='=';

    std::cout << "Enter sum: ";
    std::cin >> sum;
    std::cout << "\n";

    char flip='n';

    std::cout << "Do you want any specific fetch criteria? y/n: ";
    std::cin >> flip;
    std::cout << "\n";

    if (flip == 'y') {

        std::cout << "Enter criteria (<,>,=): ";
        std::cin >> criteria;
        std::cout << "\n";
    }

    List<Transaction> list = service.fetch(sum, criteria);

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << "Position: " << i << "\n";
        std::cout << "Element:\n";
        list.getElement(i).print();
        std::cout << "\n";

    }
}

void UI::print3() {

    int day;

    cout << "Enter day: ";
    cin >> day;
    cout << "\n";

    cout << service.dayTotal(day)<<endl;



}

void UI::print4() {
    char temp[30];

    cout << "Type: ";
    cin >> temp;
    cout << endl;

    String type = String(temp);

    cout<< service.sumType(type)<<endl;

}

void UI::print5() {

    char temp[30];

    cout << "Type: ";
    cin >> temp;
    cout << endl;

    String type = String(temp);

    int day;
    cout << "Enter day: ";
    cin >> day;
    cout << "\n";

    Transaction transaction = service.maxTrans(day, type);

    std::cout << "Element:\n";
    transaction.print();
    std::cout << "\n";

}

void UI::update()
{
    String description;
    char descriptionPtr[30];
    int day;
    int newSum;
    char type[30];

    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "\n";

    std::cout << "Description: ";
    std::cin >> descriptionPtr;
    std::cout << "\n";

    std::cout << "Type: ";
    std::cin >> type;
    std::cout << "\n";

    std::cout << "Enter new sum: ";
    std::cin >> newSum;
    std::cout << "\n";

    description = descriptionPtr;

    service.update(day, description, newSum,type);

}

void UI::filter1() {
    char temp[30];

    cout << "Type you want to keep: ";
    cin >> temp;

    if (strcmp(temp, "in") == 0) strcpy(temp,"out");
    else strcpy(temp,"in");

    String type = String(temp);


    service.del(type);
}

void UI::filter2() {
    char temp[30];

    cout << "Type you want to keep: ";
    cin >> temp;

    if (strcmp(temp, "in") == 0) strcpy(temp,"out");
    else strcpy(temp,"in");

    String type = String(temp);

    int sum;
    cout<<"Sum:";
    cin>>sum;
    cout<<endl;



    service.del_sum(sum);

    service.del(type);
}


void UI::run()
{
    while (true)
    {
        int option;

        this->printMenu();

        std::cout << "Choose option: ";
        std::cin >> option;
        std::cout << "\n";


        switch (option)
        {
            case 1:
                this->add1();
                break;
            case 2:
                this->add2();
                break;
            case 3:
                this->del1();
                break;
            case 4:
                this->del2();
                break;
            case 5:
                this->del3();
                break;
            case 6:
                this->update();
                break;
            case 7:
                this->printAll();
                break;
            case 8:
                this->print1();
                break;
            case 9:
                this->print2();
                break;
            case 10:
                this->print3();
                break;
            case 11:
                this->print4();
                break;
            case 12:
                this->print5();
                break;
            case 13:
                this->filter1();
                break;
            case 14:
                this->filter2();
                break;
            case 15:
                cout<<"Nu il am"<<endl;
                break;
            default:
                std::cout << "Goodbye cruel World!\n";
                return;
        }
    }
}
