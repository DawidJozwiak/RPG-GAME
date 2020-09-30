#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

class Enemy : public Character
{
public:
    Enemy(int, int, int);
        int enemy_status = 1;
        void randomName();
        int getEnemy_status() const;
        void setEnemy_status(int value);
};

#endif // ENEMY_H
