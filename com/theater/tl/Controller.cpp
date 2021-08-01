//
// Created by fersolano on 7/31/2021.
//

#include "Controller.h"

Controller::Controller() {
    business = new Business();
}

string Controller::reserveSeat(int id, string name, int position) {
    return business->reserveSeat(business->createPerson(id, name), position);
}

string Controller::showTotalReservesByArea(string area) {
    return business->showTotalReservesByArea(area);
}

string Controller::showWaitingListByArea(string area) {
    return business->showWaitingListByArea(area);
}