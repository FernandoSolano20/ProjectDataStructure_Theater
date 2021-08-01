//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_SEAT_H
#define THEATER_SEAT_H

#include <xstring>
#include "../../structures/Queue/Queue.h"

using namespace std;

class Seat {
public:
    Seat();
    int getPrice();
    void setPrice(int price);
    bool isReserved();
    void setReserved(bool reserved);
    int getPosition();
    void setPosition(int position);
    Person* getSeatOwner();
    void setSeatOwner(Person* owner);
private:
    int price;
    bool reserved;
    int position;
    Person* seatOwner;
};


#endif //THEATER_SEAT_H
