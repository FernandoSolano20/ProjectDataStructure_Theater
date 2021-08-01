//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_STACK_H
#define THEATER_STACK_H


#include "../List.h"

class Stack: public List{
public:
    Stack();
    bool isAllReserved();
    void push(Seat* data);
    bool reserveSeat(Person* person, int position);
};


#endif //THEATER_STACK_H
