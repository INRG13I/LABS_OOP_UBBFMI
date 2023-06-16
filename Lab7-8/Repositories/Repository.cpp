//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#include "Repository.h"

void Repository::add(Transaction transaction)
{
    list.add(transaction);
}

void Repository::del(int position)
{
    list.del(position);
}

void Repository::update(int position, Transaction transaction)
{
    list.update(position, transaction);
}

Transaction Repository::get(int position)const
{
    return list.getElement(position);
}

List<Transaction> Repository::getAll() const
{
    return list;
}
