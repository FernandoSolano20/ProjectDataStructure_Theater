//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_NODESEAT_H
#define THEATER_NODESEAT_H


#include "../../objects/Seat/Seat.h"

class NodeSeat {
public:
    NodeSeat();
    Seat* getData();
    void setData(Seat* data);
    NodeSeat* getNext();
    void setNext(NodeSeat* next);
private:
    Seat* data;
    NodeSeat* next;
};


#endif //THEATER_NODESEAT_H
