//
// Created by fersolano on 6/28/2021.
//

#include <iostream>
#include "List.h"

List::List() {
    head= nullptr;
    size = 0;
    waitingList = new Queue();
    setArea("");
}

bool List::isEmpty() {
    if (getSize() == 0){
        return true;
    }
    return false;
}

int List::getSize() {
    return size;
}

Seat* List::pop() {
    NodeSeat* aux = getHead();
    if (aux == nullptr) {
        return NULL;
    }
    setSize(-1);
    Seat* data = aux->getData();
    setHead(aux->getNext());
    return data;
}

NodeSeat* List::getByPosition(int position) {
    NodeSeat* aux = getHead();
    while (aux != nullptr) {
        if (aux->getData()->getPosition() == position) {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

int List::totalReserves() {
    int count = 0;
    NodeSeat* aux = getHead();
    while (aux != nullptr) {
        Seat* seat = aux->getData();
        if (seat->isReserved()) {
            count++;
        }
        aux = aux->getNext();
    }
    return count;
}

Queue* List::getWaitingList() {
    return waitingList;
}

string List::getArea() {
    return area;
}

void List::setArea(string area) {
    this->area = area;
}

void List::setPersonToWaitList(Person *person) {
    waitingList->push(person);
}

NodeSeat* List::getHead() {
    return head;
}

void List::setHead(NodeSeat *node) {
    head = node;
}

void List::setSize(int num) {
    size = size + num;
}