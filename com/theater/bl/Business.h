//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_BUSINESS_H
#define THEATER_BUSINESS_H


#include "structures/Simple/SimpleList.h"
#include "structures/Stack/Stack.h"

class Business {
public:
    Business();
    Person* createPerson(int id, string name);
    string reserveSeat(Person* person, int position);
    string showTotalReservesByArea(string area);
    string showWaitingListByArea(string area);
    string showAllTheater();
private:
    void initSeats();
    List* getArea(int position);
    List* getAreaByKey(string area);
    SimpleList* preferentialArea;
    Stack* preferentialGrandstandRow1;
    Stack* preferentialGrandstandRow2;
    Stack* preferentialGrandstandRow3;
    Stack* preferentialGrandstandRow4;
    Stack* preferentialGrandstandRow5;
    SimpleList* generalGrandstand;
};


#endif //THEATER_BUSINESS_H
