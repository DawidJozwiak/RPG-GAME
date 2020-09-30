#include "character.h"

int Character::getMax_health()
{
    return max_health;
}

void Character::setMax_health(int value)
{
    max_health = value;
}

int Character::getMax_stamina() const
{
    return max_stamina;
}

void Character::setMax_stamina(int value)
{
    max_stamina = value;
}

int Character::getCurrent_health()
{
    return current_health;
}

void Character::setCurrent_health(int value)
{
    current_health = value;
}

int Character::getCurrent_stamina() const
{
    return current_stamina;
}

void Character::setCurrent_stamina(int value)
{
    current_stamina = value;
}


int Character::getWeapon_damage() const
{
    return weapon_damage;
}

void Character::setWeapon_damage(int value)
{
    weapon_damage = value;
}

int Character::getArmor_coefficient() const
{
    return armor_coefficient;
}

void Character::setArmor_coefficient(int value)
{
    armor_coefficient = value;
}

int Character::getClass_number() const
{
    return class_number;
}

void Character::setClass_number(int value)
{
    class_number = value;
}

float Character::getClassCoefficient() const
{
    return classCoefficient;
}

void Character::setClassCoefficient(float value)
{
    classCoefficient = value;
}

bool Character::getStatus() const
{
    return status;
}

void Character::setStatus(bool value)
{
    status = value;
}

int Character::getHealth() const
{
    return health;
}

void Character::setHealth(int value)
{
    health = value;
}

int Character::Damage(int current_health, float coef)
{
    int basic_attack = weapon_damage * coef;
    return current_health - basic_attack;
}
//skill function that operates with ability of user
int Character::Skill(float eh, float yh, int st, float ah, int ls){

    if(class_number == 1){
        setCurrent_health(eh -= 50);
        setCurrent_stamina(st-=50);
    }
   if(class_number == 2){
       if(st < 150)
       {
           //std::cout << "You ran out of stamina" << std::endl;
       }
       else{
       eh -= 100;
       yh += 50;
       st -= 50;
       return eh;
       return yh;
       return st;
       }
   }
    if(class_number == 3){
        eh -= 200;
        st -= 50;
        return eh;
        return st;

    }
    if(class_number == 4){
        if(st < 150)
        {
          //  std::cout << "You ran out of stamina" << std::endl;
        }
        else{
        int healtarget;
        //picking target to heal
     //   std::cout << "Pick a target" << std::endl;
    //   std::cout << "1. Yourself"  << std::endl;
    //    std::cout << "2. Ally "  << std::endl;
    //    std::cin >> healtarget;

        switch( healtarget )
        {
            case 1:
        {
            yh += 200;
            st -= 150;
            return yh;
            return st;
            break;
        }
            case 2:
            {
                if(ls == 0){
                 //   std::cout << "Ally is dead" << std::endl;
                    return 0;
                }
                ah += 200;
                st -= 150;
                return yh;
                return st;
                break;
            }
        }
    }
    }

return 0;
}
