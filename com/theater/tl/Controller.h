//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_CONTROLLER_H
#define THEATER_CONTROLLER_H

#include <xstring>
#include "../bl/Business.h"

using namespace std;

class Controller {
public:
    Controller();
    string reserveSeat(int id, string name, int position);
    string showTotalReservesByArea(string Area);
    string showWaitingListByArea(string Area);
private:
    Business* business;
};


#endif //THEATER_CONTROLLER_H
