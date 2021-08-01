//
// Created by fersolano on 7/31/2021.
//

#include "NodePerson.h"

NodePerson::NodePerson() {
    setNext(nullptr);
}

Person* NodePerson::getData() {
    return data;
}

void NodePerson::setData(Person* data) {
    this->data = data;
}

NodePerson* NodePerson::getNext() {
    return next;
}

void NodePerson::setNext(NodePerson *next) {
    this->next = next;
}