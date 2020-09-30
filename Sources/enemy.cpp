#include "enemy.h"

Enemy::Enemy(int a, int b, int c){

    classCoefficient = a;
    max_health = b;
    max_stamina = c;
}

int Enemy::getEnemy_status() const
{
    return enemy_status;
}

void Enemy::setEnemy_status(int value)
{
    enemy_status = value;
}
