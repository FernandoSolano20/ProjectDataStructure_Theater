//
// Created by fersolano on 7/31/2021.
//

#include <string>
#include "Business.h"
#include "../const/Constant.h"

Business::Business() {
    preferentialArea = new SimpleList();
    preferentialArea->setArea("A");
    preferentialGrandstandRow1 = new Stack();
    preferentialGrandstandRow1->setArea("B");
    preferentialGrandstandRow2 = new Stack();
    preferentialGrandstandRow2->setArea("B");
    preferentialGrandstandRow3 = new Stack();
    preferentialGrandstandRow3->setArea("B");
    preferentialGrandstandRow4 = new Stack();
    preferentialGrandstandRow4->setArea("B");
    preferentialGrandstandRow5 = new Stack();
    preferentialGrandstandRow5->setArea("B");
    generalGrandstand = new SimpleList();
    generalGrandstand->setArea("C");
    initSeats();
}

Person* Business::createPerson(int id, string name) {
    Person* person = new Person();
    person->setName(name);
    person->setId(id);
    return person;
}

string Business::reserveSeat(Person *person, int position) {
    List* area = getArea(position);
    if (area == nullptr) {
        return "No existe este campo";
    }

    bool result = area->reserveSeat(person, position);
    if(result){
        return "Ha podido reservar un espacio.";
    }

    area->setPersonToWaitList(person);
    return "Se a agregado a la cola de espera.";
}

string Business::showTotalReservesByArea(string area) {
    List* currentArea = getAreaByKey(area);
    if (currentArea != nullptr){
        return "El total de espacio reservado es: " + to_string(currentArea->totalReserves());
    }

    if (area == "B") {
        int reservedBArea = preferentialGrandstandRow1->totalReserves() +
                preferentialGrandstandRow2->totalReserves() +
                preferentialGrandstandRow3->totalReserves() +
                preferentialGrandstandRow4->totalReserves() +
                preferentialGrandstandRow5->totalReserves();
        return "El total de espacio reservado es: " + to_string(reservedBArea);
    }

    return "No existe esa seccion.";
}

string Business::showWaitingListByArea(string area) {
    List* currentArea = getAreaByKey(area);
    if (currentArea != nullptr){
        Queue* reservedList = currentArea->getWaitingList();
        return reservedList->showList();
    }

    if (area == "B") {
        Queue* reservedList1 = preferentialGrandstandRow1->getWaitingList();
        Queue* reservedList2 = preferentialGrandstandRow2->getWaitingList();
        Queue* reservedList3 = preferentialGrandstandRow3->getWaitingList();
        Queue* reservedList4 = preferentialGrandstandRow4->getWaitingList();
        Queue* reservedList5 = preferentialGrandstandRow5->getWaitingList();
        return reservedList1->showList() + "\n" +
                reservedList2->showList() + "\n" +
                reservedList3->showList() + "\n" +
                reservedList4->showList() + "\n" +
                reservedList5->showList() + "\n";
    }

    return "No existe esa seccion.";
}


void Business::initSeats() {;
    for (int i = 1; i <= Constant::FinalGeneralGrandstand; ++i) {
        Seat* seat = new Seat();
        seat->setPosition(i);
        if (!(i > Constant::FinalPreferentialArea)) {
            seat->setPrice(7000);
            preferentialArea->push(seat);
            continue;
        }

        if (!(i > Constant::FinalPreferentialGrandstand1)) {
            seat->setPrice(5500);
            preferentialGrandstandRow1->push(seat);
            continue;
        }

        if (!(i > Constant::FinalPreferentialGrandstand2)) {
            seat->setPrice(5500);
            preferentialGrandstandRow2->push(seat);
            continue;
        }

        if (!(i > Constant::FinalPreferentialGrandstand3)) {
            seat->setPrice(5500);
            preferentialGrandstandRow3->push(seat);
            continue;
        }

        if (!(i > Constant::FinalPreferentialGrandstand4)) {
            seat->setPrice(5500);
            preferentialGrandstandRow4->push(seat);
            continue;
        }

        if (!(i > Constant::FinalPreferentialGrandstand5)) {
            seat->setPrice(5500);
            preferentialGrandstandRow5->push(seat);
            continue;
        }

        if (!(i > Constant::FinalGeneralGrandstand)) {
            seat->setPrice(4000);
            generalGrandstand->push(seat);
            continue;
        }
    }
}

List* Business::getArea(int position) {
    if (position >= Constant::BeginPreferentialArea && position <= Constant::FinalPreferentialArea){
        return preferentialArea;
    } else if (position >= Constant::BeginPreferentialGrandstand1 && position <= Constant::FinalPreferentialGrandstand5){
        if (!preferentialGrandstandRow1->isAllReserved()) {
            return preferentialGrandstandRow1;
        }
        if (!preferentialGrandstandRow2->isAllReserved()) {
            return preferentialGrandstandRow2;
        }
        if (!preferentialGrandstandRow3->isAllReserved()) {
            return preferentialGrandstandRow3;
        }
        if (!preferentialGrandstandRow4->isAllReserved()) {
            return preferentialGrandstandRow4;
        }
        if (!preferentialGrandstandRow5->isAllReserved()) {
            return preferentialGrandstandRow5;
        }
        return preferentialGrandstandRow5;
    }
    else if (position >= Constant::BeginGeneralGrandstand && position <= Constant::FinalGeneralGrandstand) {
        return generalGrandstand;
    }
    return nullptr;
}

List* Business::getAreaByKey(string area) {
    if (area == "A") {
        return preferentialArea;
    }

    if (area == "C") {
        return generalGrandstand;
    }

    return nullptr;
}