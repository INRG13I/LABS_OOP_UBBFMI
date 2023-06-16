//
// Created by Nicolaescu Raoul on 06.05.2023.
//

#ifndef LAB_9_10_REPOSITORY_H
#define LAB_9_10_REPOSITORY_H


#include <vector>



template<class Class>
class Repository
{

private:
    std::vector<Class> entityList;

public:

    Repository() = default;
    ~Repository() = default;

    void add(Class entity);
    void del(int position);
    void update(int position, Class newEntity);

    int find(Class entity)const;

    Class getFromPosition(int position);
    std::vector<Class> getAll()const;

    void sort();


};

template<class Class>
inline void Repository<Class>::sort() {
    std::sort(entityList.begin(), entityList.end());
}

template<class Class>
inline void Repository<Class>::add(Class entity)
{
    if (this->find(entity)!= -1) {
        return;
    }
    entityList.push_back(entity);
}

template<class Class>
inline void Repository<Class>::del(int position)
{
    entityList.erase(entityList.begin()+position);
}

template<class Class>
inline void Repository<Class>::update(int position, Class newEntity)
{
    entityList.at(position) = newEntity;
}

template<class Class>
inline int Repository<Class>::find(Class entity) const
{
    int position = 0;

    for (Class currentEntity : entityList)
    {
        if (currentEntity == entity) {
            return position;
        }
        position++;
    }


    return -1;
}

template<class Class>
inline Class Repository<Class>::getFromPosition(int position)
{
    return entityList.at(position);
}

template<class Class>
inline std::vector<Class> Repository<Class>::getAll() const
{
    return entityList;
}


#endif //LAB_9_10_REPOSITORY_H
