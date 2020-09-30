#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include "character.h"

class Player : public Character
{
public:
   Player();
   Player(int, bool, bool, bool);
   void staminaPotion(int);
   void healthPotion(int);
   static int gold;
   static bool sword;
   static bool staff;
   static bool bow;
   static int x;
};


#endif // PLAYER_H
