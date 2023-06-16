//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#ifndef LAB_8_SERVICE_H
#define LAB_8_SERVICE_H


#include "../Repositories/Repository.h"
#include "../List/List.h"
#include "../Transaction/Transaction.h"

class Service
{
private:

    Repository repo;

public:

    Service() = default;

    ~Service() = default;


    void add(Transaction transaction);
    void del(int day);
    void del(int lDay, int rDay);
    void del(String type);
    void del_sum(int sum);
    void update(int position, Transaction transaction);
    void update(int day, String description, int newSum, String type);
    Transaction get(int position)const;
    List<Transaction> getAll()const;
    int dayTotal(int day);
    int sumType(String type);
    Transaction maxTrans(int day, String type);


    List<Transaction> fetch(int sum, char criteria='=');
};


#endif //LAB_8_SERVICE_H
