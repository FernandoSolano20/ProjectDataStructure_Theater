//
// Created by fersolano on 7/31/2021.
//

#include "SimpleList.h"

SimpleList::SimpleList():List() {

}

void SimpleList::push(Seat* data) {
    setSize(1);
    NodeSeat*aux = getHead();
    NodeSeat* temp = new NodeSeat();
    temp->setData(data);
    if (aux == nullptr) {
        setHead(temp);
    } else{
        while (aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        aux->setNext(temp);
        temp->setNext(nullptr);
    }
}

bool SimpleList::reserveSeat(Person *person, int position) {
    NodeSeat* node = getByPosition(position);
    Seat* seat = node->getData();
    if (!seat->isReserved()) {
        seat->setReserved(true);
        seat->setSeatOwner(person);
        return true;
    }
    return false;
}