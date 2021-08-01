//
// Created by fersolano on 7/31/2021.
//

#include "Stack.h"

Stack::Stack():List() {

}

bool Stack::isAllReserved() {
    NodeSeat* aux = getHead();
    for (int i = 0; i < getSize(); i++) {
        if (!aux->getData()->isReserved()){
            return false;
        }
    }
    return true;
}

void Stack::push(Seat* data) {
    setSize(1);
    NodeSeat* temp = new NodeSeat();
    temp->setData(data);
    if(getHead() == nullptr) {
        setHead(temp);
    } else {
        temp->setNext(getHead());
        setHead(temp);
    }
}

bool Stack::reserveSeat(Person *person, int position) {
    NodeSeat* node = getHead();
    bool addIt = false;
    while (addIt == false) {
        Seat* seat = node->getData();
        if (!seat->isReserved()){
            seat->setSeatOwner(person);
            seat->setReserved(true);
            addIt = true;
            return addIt;
        }
        if (node->getNext() == nullptr) {
            addIt = false;
            return addIt;
        }
        node = node->getNext();
    }
    return addIt;
}