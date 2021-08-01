//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_QUEUE_H
#define THEATER_QUEUE_H


#include "../../objects/Person/Person.h"
#include "../Node/NodePerson.h"

class Queue {
public:
    Queue();
    bool isEmpty();
    int getSize();
    Person* pop();
    string showList();
    void push(Person* data);
private:
    NodePerson* head;
    int size;
    NodePerson* getHead();
    void setHead(NodePerson* node);
    void setSize(int num);
};


#endif //THEATER_QUEUE_H
