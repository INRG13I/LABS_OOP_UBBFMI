//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#ifndef LAB_8_REPOSITORY_H
#define LAB_8_REPOSITORY_H


#include"../Transaction/Transaction.h"
#include "../List/List.h"


class Repository
{
private:
    List<Transaction> list;

public:

    Repository() = default;

    ~Repository() = default;


    void add(Transaction transaction);
    void del(int position);
    void update(int position, Transaction transaction);
    Transaction get(int position)const;

    List<Transaction> getAll()const;

};

#endif //LAB_8_REPOSITORY_H
