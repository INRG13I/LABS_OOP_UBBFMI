//
// Created by Nicolaescu Raoul on 24.04.2023.
//

#ifndef LAB_6_REPOSITORYMAP_H
#define LAB_6_REPOSITORYMAP_H


#include <iostream>
#include <map>

template <class Class>
class RepositoryMap
{
private:
    std::map<int, Class> list;
public:
    RepositoryMap() = default;

    ~RepositoryMap() = default;

    std::map<int, Class> getList()const;
    int getSize()const;

    void setList(std::map<int, Class> newList);

    void addElement(Class newElement);
    void deleteElement(int position);
    void updateElement(int position, Class newElement);
    Class getElement(int position);
    int findElement(Class element);
    void printAll();
};

template<class Class>
inline int RepositoryMap<Class>::getSize() const
{
    return list.size();
}

template<class Class>
inline void RepositoryMap<Class>::setList(std::map<int, Class> newList)
{
    list = newList;
}

template<class Class>
inline void RepositoryMap<Class>::addElement(Class newElement)
{
    list[list.size()] = newElement;
}


template<class Class>
inline void RepositoryMap<Class>::deleteElement(int position)
{
    for (int i = position; i < list.size() - 1; i++)
    {
        list[i] = list[i + 1];
    }

    list.erase(list.size() - 1);
}

template<class Class>
inline void RepositoryMap<Class>::updateElement(int position, Class newElement)
{
    list[position] = newElement;
}

template<class Class>
inline Class RepositoryMap<Class>::getElement(int position)
{
    return list[position];
}

template<class Class>
inline int RepositoryMap<Class>::findElement(Class element)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == element) {
            return i;
        }
    }
    return -1;
}

template<class Class>
inline void RepositoryMap<Class>::printAll()
{
    for (const auto& pair : list)
    {
        std::cout << pair.second << "\n";
    }
}


#endif //LAB_6_REPOSITORYMAP_H
