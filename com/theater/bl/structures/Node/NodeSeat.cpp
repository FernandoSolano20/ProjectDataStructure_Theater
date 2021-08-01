//
// Created by fersolano on 6/28/2021.
//

#include "NodeSeat.h"
#include "../../objects/Seat/Seat.h"

NodeSeat::NodeSeat() {
    setNext(nullptr);
}

Seat* NodeSeat::getData() {
    return data;
}

void NodeSeat::setData(Seat* data) {
    this->data = data;
}

NodeSeat* NodeSeat::getNext() {
    return next;
}

void NodeSeat::setNext(NodeSeat *next) {
    this->next = next;
}