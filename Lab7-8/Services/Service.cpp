//
// Created by Nicolaescu Raoul on 01.05.2023.
//

#include "Service.h"

void Service::add(Transaction transaction)
{
    repo.add(transaction);
}

void Service::del(int day)
{
    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        if(repo.getAll().getElement(i).getDay() == day) {
            repo.del(i);
            i--;
        }
    }
}

void Service::del(int lDay, int rDay)
{
    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        if (repo.getAll().getElement(i).getDay() >= lDay &&
            repo.getAll().getElement(i).getDay() <= rDay) {
            repo.del(i);
            i--;
        }
    }
}

void Service::del(String type)
{
    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        if (repo.getAll().getElement(i).getType() == type) {
            repo.del(i);
            i--;
        }
    }
}

void Service::del_sum(int sum) {
    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        if(repo.getAll().getElement(i).getSum() > sum) {
            repo.del(i);
            i--;
        }
    }
}

void Service::update(int position, Transaction transaction)
{
    repo.update(position, transaction);
}

void Service::update(int day, String description, int newSum, String type)
{

    List<Transaction> list = repo.getAll();

    for (int i = 0; i < list.getSize(); i++)
    {
        Transaction element=list.getElement(i);

        if (element.getDay() == day &&
            element.getDescription() == description && element.getType() == type) {

            element.setSum(newSum);

            repo.update(i, element);
        }

    }

}



Transaction Service::get(int position)const
{
    return repo.get(position);
}

List<Transaction> Service::getAll() const
{
    return repo.getAll();
}

int Service::dayTotal(int day)
{
    int total = 0;

    for (int i = 0; i < repo.getAll().getSize() ;i++)
    {
        if (repo.getAll().getElement(i).getDay() == day) {

            if (repo.getAll().getElement(i).getType() == (char*)"in")
            {
                total += repo.getAll().getElement(i).getSum();
            }

            if (repo.getAll().getElement(i).getType() == (char*)"out")
            {
                total -= repo.getAll().getElement(i).getSum();
            }

        }
    }


    return total;
}

int Service::sumType(String type)
{
    int total = 0;

    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        if (repo.getAll().getElement(i).getType() == type) {
            total += repo.getAll().getElement(i).getSum();
        }
    }


    return total;
}

Transaction Service::maxTrans(int day, String type)
{
    Transaction max;

    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        if (repo.getAll().getElement(i).getDay() == day &&
            repo.getAll().getElement(i).getType() == type) {

            if (repo.getAll().getElement(i).getSum() > max.getSum()) {

                max = repo.getAll().getElement(i);
            }

        }
    }
    return max;
}

List<Transaction> Service::fetch(int sum, char criteria)
{
    List<Transaction> list;

    for (int i = 0; i < repo.getAll().getSize(); i++)
    {
        switch (criteria) {
            case'=':
                if (repo.getAll().getElement(i).getSum() == sum) {
                    list.add(repo.getAll().getElement(i));
                }
                break;
            case'<':
                if (repo.getAll().getElement(i).getSum() < sum) {
                    list.add(repo.getAll().getElement(i));
                }
                break;
            case'>':
                if (repo.getAll().getElement(i).getSum() > sum) {
                    list.add(repo.getAll().getElement(i));
                }
                break;

        }
    }

    return list;
}



