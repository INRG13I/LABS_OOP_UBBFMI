//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#ifndef LAB_6_REPOSITORY_H
#define LAB_6_REPOSITORY_H


#include <iostream>


template <class Class>
class Repository
{

private:
    Class* list;
    int size;
public:
    Repository();
    Repository(const Repository<Class>& other);


    ~Repository();


    Class* getList()const;
    int getSize()const;


    void setList(Class* newList);
    void setSize(int newSize);

    void addElement(Class newElement);
    void deleteElement(int position);
    void updateElement(int position, Class newElement);
    Class getElement(int position);
    int findElement(Class element);
    void printAll();
    void bubbleSort();

    Repository<Class>& operator=(const Repository<Class>& newRepo);

};

template<class Class>
inline Repository<Class>::Repository()
{
    this->setList(nullptr);
    this->setSize(0);

}

template<class Class>
inline Repository<Class>::~Repository()
{
    delete[] list;
    list = nullptr;


}

template<class Class>
inline Class* Repository<Class>::getList()const
{
    return list;
}

template<class Class>
inline int Repository<Class>::getSize()const
{
    return size;
}

template<class Class>
inline void Repository<Class>::setList(Class* newList)
{
    this->list = newList;
}

template<class Class>
inline void Repository<Class>::setSize(int newSize)
{
    size = newSize;
}

template<class Class>
inline void Repository<Class>::addElement(Class newElement)
{
    Class* temp;
    temp = new Class[this->getSize() + 1];

    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = this->getElement(i);
    }

    temp[this->getSize()] = newElement;
    delete[] this->list;
    this->setList(temp);
    this->setSize(this->getSize() + 1);

}


template<class Class>
inline void Repository<Class>::deleteElement(int position)
{
    Class* temp;
    temp = new Class[this->getSize() - 1];
    for (int i = 0; i < this->getSize() - 1; i++) {

        if (i == position) {
            temp[i] = this->getElement(this->getSize() - 1);
        }
        else {
            temp[i] = this->getElement(i);
        }
    }

    this->setSize(this->getSize() - 1);
    this->setList(temp);

}

template<class Class>
inline void Repository<Class>::updateElement(int position, Class newElement)
{
    this->list[position] = newElement;
}

template<class Class>
inline Class Repository<Class>::getElement(int position)
{
    return list[position];
}

template<class Class>
inline int Repository<Class>::findElement(Class element)
{
    int i = 0;
    if (this->getSize() == 0)return -1;
    while (this->getElement(i) != element && i != this->getSize()) i++;
    if (i == this->getSize()) return -1;
    return i;

}

template<class Class>
inline void Repository<Class>::printAll()
{
    for (int i = 0; i < this->getSize(); i++)
    {
        std::cout << this->getElement(i) << "\n";
    }
}

template<class Class>
inline void Repository<Class>::bubbleSort()
{
    for (int i = 0; i < this->getSize() - 1; i++) {
        for (int j = 0; j < this->getSize() - i - 1; j++) {
            if (this->getElement(j) > this->getElement(j + 1)) {
                Class temp = this->getElement(j);
                this->updateElement(j, this->getElement(j + 1));
                this->updateElement(j + 1, temp);
            }
        }
    }
}

template<class Class>
inline Repository<Class>& Repository<Class>::operator=(const Repository<Class>& other)
{

    if (this != &other)
    {
        delete[] this->list;
        this->setSize(other.getSize());
        this->list = new Class[other.getSize()];

        for (int i = 0; i < other.getSize(); i++)
        {
            this->list[i] = other.list[i];
        }
    }

    return *this;

}


template<class Class>
Repository<Class>::Repository(const Repository<Class>& other) {
    this->setSize(other.getSize());
    this->list = new Class[other.getSize()];

    for (int i = 0; i < other.getSize(); i++) {
        this->list[i] = other.list[i];
    }
}


#endif //LAB_6_REPOSITORY_H
