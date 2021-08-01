//
// Created by fersolano on 7/31/2021.
//

#include "Seat.h"

Seat::Seat() {
    setPrice(0);
    setReserved(false);
    setPosition(0);
    seatOwner = new Person();
}

int Seat::getPrice() {
    return price;
}

void Seat::setPrice(int price) {
    this->price = price;
}

bool Seat::isReserved() {
    return reserved;
}

void Seat::setReserved(bool reserved) {
    this->reserved = reserved;
}

int Seat::getPosition() {
    return position;
}

void Seat::setPosition(int position) {
    this->position = position;
}

Person * Seat::getSeatOwner() {
    return seatOwner;
}

void Seat::setSeatOwner(Person* owner) {
    this->seatOwner = owner;
}