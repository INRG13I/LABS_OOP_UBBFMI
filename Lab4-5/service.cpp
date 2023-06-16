//
// Created by Nicolaescu Raoul on 03.04.2023.
//

#include "service.h"
#include "repository.h"
#include "entity.h"
#include "tests.h"

#include <iostream>


void
Service::add_entity(Repository &r, double px1, double py1, double px2, double py2, double px3, double py3, double px4, double py4) {

    r.addEntity(Entity(px1, py1, px2, py2, px3, py3, px4, py4));

}
void Service::print_by_position(Repository &r, int position) {

    Entity entity=r.getEntityByPosition(position);
    std::cout<<"***************************************************"<<std::endl;
    std::cout<<"Point1:"<<entity.getx1()<<" "<<entity.gety1()<<std::endl;
    std::cout<<"Point2:"<<entity.getx2()<<" "<<entity.gety2()<<std::endl;
    std::cout<<"Point3:"<<entity.getx3()<<" "<<entity.gety3()<<std::endl;
    std::cout<<"Point4:"<<entity.getx4()<<" "<<entity.gety4()<<std::endl;
    std::cout<<"Lenght:"<<entity.getlatura()<<std::endl;
    std::cout<<"Area:"<<entity.getarie()<<std::endl;
    std::cout<<"Diagonal:"<<entity.getdiagonala()<<std::endl;
}

void Service::print_all_entities(Repository &r) {
    for(int i=0;i<r.getCurrentSize();i++){
        Entity entity=r.getEntityByPosition(i);
        print_by_position(r,i);
    }
    std::cout<<"***************************************************"<<std::endl;
}

int Service::biggest_entity(Repository &r) {
    Entity max_entity = Entity();
    int j=-1;
    for (int i = 0;i < r.getCurrentSize() ; i++){
        Entity e = r.getEntityByPosition(i);
        if(max_entity < e){
            max_entity = e;
            j=i;
        }
    }
    return j;
}

Entity* Service::all_form_dial1(Repository &r) {
    Entity *array = new Entity[r.getCurrentSize()];
    int j=0;
    r.setsize(0);
    //todo(daca pun in for ++i nu imi ia pe cel de dupa daca pun i++ nu mi-l ia pe cel care e inainte
    for (int i = 0; i < r.getCurrentSize(); i++) {
        Entity e = r.getEntityByPosition(i);
        if (e.getx1() > 0 && e.gety1() > 0 && e.getx2() > 0 && e.gety2() > 0 && e.getx3() > 0 && e.gety3() > 0 &&
            e.getx4() > 0 && e.gety4() > 0) {
            array[j] = r.getEntityByPosition(i);
            j++;
        }
    }
//    if (r.getCurrentSize() == 1)
//        array[j++] = r.getEntityByPosition(0);
    r.setsize(--j);
    return array;
}

Entity *Service::max_sequence(Repository &r) {
    int start = 0, stop = 0, len = 0, maxlen = 0, k = 0;
    r.setsize(0);
    Entity* c = new Entity[r.getMaxSize()];
    for (int i = 0; i < r.getCurrentSize(); ++i) {
        if (r.getEntityByPosition(i) == r.getEntityByPosition(i+1))
            len++;
        else {
            if (len > maxlen) {
                maxlen = len;
                stop = i + 1;
                start = stop - maxlen - 1;
            }
            len = 0;
        }
    }
    if (r.getCurrentSize() == 1)
        c[k++] = r.getEntityByPosition(0);
    else
        for (int i = start; i < stop; ++i)
            c[k++] = r.getEntityByPosition(i);
    r.setsize(k);
    return c;
}

void Service::menu_options() {
    std::cout << "1. Add entity." << std::endl;
    std::cout << "2. Show entities." << std::endl;
    std::cout << "3. Show biggest entity." << std::endl;
    std::cout << "4. Show first quadran squares." << std::endl;
    std::cout << "5. Max sequence of equal squares." << std::endl;
    std::cout << "6. Exit." << std::endl;
}

void Service::menu() {

    testEntity();
    testRepository();
    testService();
    Repository r;
    this->add_entity(r,0,10,0,0,10,0,10,10);
    this->add_entity(r,10,20,10,10,20,10,20,20);
   this->add_entity(r,0,10,0,0,10,0,10,10);
    this->add_entity(r,0,20,0,0,20,0,20,20);
    this->add_entity(r,0,30,0,0,30,0,30,30);
    this->add_entity(r,0,10,0,0,10,0,10,10);
    this->add_entity(r,20,30,20,20,30,20,30,30);
    while(true) {
        std::cout << "*********************  Menu  *********************" << std::endl;
        menu_options();
        int option = 0;
        std::cout << "Give option: ";
        std::cin >> option;
        std::cout << std::endl;
        int x1 = 0, x2 = 0, x3 = 0, x4 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
        Entity* v=this->all_form_dial1(r);
        Entity* l=this->max_sequence(r);

        switch (option) {
            case 1:
                std::cout << "********** ADD SQUARE   **********" << std::endl;
                std::cout << "Square is structured like this:" << std::endl;
                std::cout << "    Point 1(x1,y1)       Point 4(x4,y4)  " << std::endl;
                std::cout << "           X------------X         " << std::endl;
                std::cout << "           |            |         " << std::endl;
                std::cout << "           |            |         " << std::endl;
                std::cout << "           |            |         " << std::endl;
                std::cout << "           X------------X         " << std::endl;
                std::cout << "    Point 2(x2,y2)       Point 3(x3,y3)  " << std::endl << std::endl;
                std::cout << "Point 1 " << std::endl;
                std::cout << "X1=";
                std::cin >> x1;
                std::cout << "Y1=";
                std::cin >> y1;
                std::cout << std::endl;

                std::cout << "Point 2 " << std::endl;
                std::cout << "X2=";
                std::cin >> x2;
                std::cout << "Y2=";
                std::cin >> y2;
                std::cout << std::endl;

                std::cout << "Point 3 " << std::endl;
                std::cout << "X3=";
                std::cin >> x3;
                std::cout << "Y3=";
                std::cin >> y3;
                std::cout << std::endl;

                std::cout << "Point 4 " << std::endl;
                std::cout << "X4=";
                std::cin >> x4;
                std::cout << "Y4=";
                std::cin >> y4;
                std::cout << std::endl;

                this->add_entity(r,x1,y1,x2,y2,x3,y3,x4,y4);
                break;

            case 2:
                std::cout << "********** SHOW ALL SQUARES **********" << std::endl;
                this->print_all_entities(r);
                break;

            case 3:
                std::cout << "********** SHOW BIGGEST SQUARE **********" << std::endl;
                this->print_by_position(r,this->biggest_entity(r));
                break;

            case 4:
                std::cout << "********** FIRST QUADRANT SQUARES **********" << std::endl;
                std::cout<<r.getSize()<<std::endl;
                if(r.getSize()==-1)std::cout<<"None"<<std::endl;
                else {
                    for(int i=0;i<r.getSize()-1;i++) {
                        std::cout << "***************************************************" << std::endl;
                        std::cout << "Point1:" << v[i].getx1() << " " << v[i].gety1() << std::endl;
                        std::cout << "Point2:" << v[i].getx2() << " " << v[i].gety2() << std::endl;
                        std::cout << "Point3:" << v[i].getx3() << " " << v[i].gety3() << std::endl;
                        std::cout << "Point4:" << v[i].getx4() << " " << v[i].gety4() << std::endl;
                        std::cout << "Lenght:" << v[i].getlatura() << std::endl;
                        std::cout << "Area:" << v[i].getarie() << std::endl;
                        std::cout << "Diagonal:" << v[i].getdiagonala() << std::endl;
                    }
                }
                break;

            case 5:
                std::cout << "********** LONGEST SEQUENCE OF EQUAL SQUARES **********" << std::endl;
                for (int i = 0; i < r.getSize(); ++i) {
                    std::cout << "***************************************************" << std::endl;
                    std::cout << "Point1:" << l[i].getx1() << " " << l[i].gety1() << std::endl;
                    std::cout << "Point2:" << l[i].getx2() << " " << l[i].gety2() << std::endl;
                    std::cout << "Point3:" << l[i].getx3() << " " << l[i].gety3() << std::endl;
                    std::cout << "Point4:" << l[i].getx4() << " " << l[i].gety4() << std::endl;
                    std::cout << "Lenght:" << l[i].getlatura() << std::endl;
                    std::cout << "Area:" << l[i].getarie() << std::endl;
                    std::cout << "Diagonal:" << l[i].getdiagonala() << std::endl;
                }
                break;
            case 6:
                std::cout << "Thanks for using this app!" << std::endl;
                exit(0);
                break;
        }
    }
}