//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_NODEPERSON_H
#define THEATER_NODEPERSON_H


#include "../../objects/Person/Person.h"

class NodePerson {
public:
    NodePerson();
    Person* getData();
    void setData(Person* data);
    NodePerson* getNext();
    void setNext(NodePerson* next);
private:
    Person* data;
    NodePerson* next;
};


#endif //THEATER_NODEPERSON_H
