//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_LIST_H
#define THEATER_LIST_H


#include "Node/NodeSeat.h"

class List {
public:
    List();
    bool isEmpty();
    int getSize();
    Seat* pop();
    NodeSeat* getByPosition(int position);
    int totalReserves();
    Queue* getWaitingList();
    void setPersonToWaitList(Person* person);
    string getArea();
    void setArea(string area);
    string showArea();
    virtual void push(Seat* data) = 0;
    virtual bool reserveSeat(Person* person, int position) = false;
protected:
    NodeSeat* getHead();
    void setHead(NodeSeat* node);
    void setSize(int num);
private:
    NodeSeat* head;
    int size;
    Queue* waitingList;
    string area;
};


#endif //THEATER_LIST_H
