//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_SIMPLELIST_H
#define THEATER_SIMPLELIST_H


#include "../List.h"

class SimpleList : public List{
public:
    SimpleList();
    void push(Seat* data);
    bool reserveSeat(Person* person, int position);
};


#endif //THEATER_SIMPLELIST_H
