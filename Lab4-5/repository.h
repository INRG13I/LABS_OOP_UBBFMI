//
// Created by Nicolaescu Raoul on 02.04.2023.
//

#ifndef LAB5_REPOSITORY_H
#define LAB5_REPOSITORY_H

#include "entity.h"


class Repository {
private:
    Entity *entities;
    int currentsize = 0;
    int maxsize = 1;
    int size=0;
public:
    Repository();
    ~Repository();

    void addEntity(const Entity &entity);
    Entity &getEntityByPosition(int position);
    Entity *getAllEntities();

    int getCurrentSize();
    int getMaxSize();
    int getSize();

    void setsize(int value);
};


#endif //LAB5_REPOSITORY_H
