//
// Created by Nicolaescu Raoul on 03.04.2023.
//

#ifndef LAB5_SERVICE_H
#define LAB5_SERVICE_H

#include "repository.h"

class Service{

public:
    void add_entity(Repository &r, double px1, double py1, double px2, double py2, double px3, double py3, double px4, double py4);
    static void print_by_position(Repository &r, int position);
    static void print_all_entities(Repository &r);

    int biggest_entity(Repository &r);
    Entity* all_form_dial1(Repository &r);
    Entity* max_sequence(Repository &r);

    void menu_options();
    void menu();


};


#endif //LAB5_SERVICE_H
