#include "ally.h"

int Ally::getClass_number() const
{
    return class_number;
}

void Ally::setClass_number(int value)
{
    class_number = value;
}

int Ally::getLife_status() const
{
    return life_status;
}

void Ally::setLife_status(int value)
{
    life_status = value;
}

Ally::Ally(int c, int h, int s){
    classCoefficient = c;
    max_health = h;
    max_stamina = s;
}

