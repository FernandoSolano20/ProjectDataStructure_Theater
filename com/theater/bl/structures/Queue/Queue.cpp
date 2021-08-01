//
// Created by fersolano on 7/31/2021.
//

#include <string>
#include "Queue.h"

Queue::Queue() {
    head= nullptr;
    size = 0;
}

bool Queue::isEmpty() {
    if (getSize() == 0){
        return true;
    }
    return false;
}

int Queue::getSize() {
    return size;
}

Person* Queue::pop() {
    NodePerson* aux = getHead();
    if (aux == nullptr) {
        return NULL;
    }
    setSize(-1);
    Person* data = aux->getData();
    setHead(aux->getNext());
    return data;
}

string Queue::showList() {
    NodePerson* aux = head;
    string result = "Lista: ";
    int count = 0;
    while (aux != nullptr) {
        count++;
        Person* person = aux->getData();
        result += "\n   Persona " + to_string(count) + ": \n      Id: " + to_string(person->getId())
                + "\n      Nombre: "  +  person->getName();
        aux = aux->getNext();
    }
    return result;
}

void Queue::push(Person* data) {
    setSize(1);
    NodePerson*aux = getHead();
    NodePerson* temp = new NodePerson();
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

NodePerson* Queue::getHead() {
    return head;
}

void Queue::setHead(NodePerson *node) {
    head = node;
}

void Queue::setSize(int num) {
    size = size + num;
}