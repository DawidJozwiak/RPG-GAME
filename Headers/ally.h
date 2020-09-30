#ifndef ALLY_H
#define ALLY_H
#include "character.h"

class Ally : public Character
{
    public:
    //variable that checks if ally is still alive
        int life_status = 1;
        int class_number;
        Ally(int, int, int);      
        int getClass_number() const;
        void setClass_number(int value);
        int getLife_status() const;
        void setLife_status(int value);
};

#endif // ALLY_H
