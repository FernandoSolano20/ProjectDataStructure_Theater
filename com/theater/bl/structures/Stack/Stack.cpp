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
        aux = aux->getNext();
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
    NodeSeat* next = getHead()->getNext();
    while (next != nullptr && !next->getData()->isReserved()) {
        node = node->getNext();
        next = next->getNext();
    }

    Seat* seat = node->getData();
    if (!seat->isReserved()){
        seat->setSeatOwner(person);
        seat->setReserved(true);
        return true;
    }
    return false;
}