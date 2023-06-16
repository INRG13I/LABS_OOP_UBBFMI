//
// Created by Nicolaescu Raoul on 02.04.2023.
//

#include "repository.h"
#include <iostream>

Repository::Repository() {
    this->entities= new Entity[this->maxsize];
}

Repository::~Repository() {
    delete[]this->entities;

}

void Repository::addEntity(const Entity &entity) {
    if (this->currentsize + 1 > this->maxsize) {
        Entity *newentities = new Entity[this->maxsize * 2 + 1];
        this->maxsize = this->maxsize * 2 + 1;

        for (int i = 0; i < this->currentsize; i++) {
            newentities[i] = this->entities[i];
        }

        delete[] this->entities;

        // set newObject as the correct array
        this->entities = newentities;
    }

    this->entities[this->currentsize++] = entity;
}

Entity &Repository::getEntityByPosition(int position) {
    if (position > this->currentsize) {
        std::cout << "Position bigger than current size." << std::endl;
        throw std::out_of_range("Position is out of range");
    }

    return this->entities[position];
}

Entity *Repository::getAllEntities() {
    return this->entities;
}

int Repository::getCurrentSize() {
    return this->currentsize;
}

int Repository::getSize() {
    return this->size;
}

void Repository::setsize(int value) {
    this->size = value;
}

int Repository::getMaxSize() {
    return this->maxsize;
}
