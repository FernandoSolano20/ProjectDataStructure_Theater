//
// Created by fersolano on 7/31/2021.
//

#include "Person.h"

Person::Person() {
    setName("");
    setId(0);
}

string Person::getName() {
    return this->name;
}

void Person::setName(string name) {
    this->name = name;
}

int Person::getId() {
    return id;
}

void Person::setId(int id) {
    this->id = id;
}