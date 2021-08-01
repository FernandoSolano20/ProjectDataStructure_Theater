//
// Created by fersolano on 7/31/2021.
//

#ifndef THEATER_PERSON_H
#define THEATER_PERSON_H

#include <xstring>
using namespace std;

class Person {
public:
    Person();
    string getName();
    void setName(string name);
    int getId();
    void setId(int id);
private:
    string name;
    int id;
};


#endif //THEATER_PERSON_H
