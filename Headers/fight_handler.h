#ifndef FIGHT_HANDLER_H
#define FIGHT_HANDLER_H

#include "character.h"
#include "charactercreation.h"
#include "player.h"
#include "ally.h"
#include "enemy.h"
#include "time.h"
#include <cstdlib>
#include "fight.h"
#include "text.h"
#include <chrono>
#include <thread>

extern int choice;
extern int target;
extern int skill;
extern bool result;

void fight_handler();

void FightHellHandler();

void FightHandlerRuins();

void WarriorFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z);

void MageFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z);

void RougeFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z);

void EnemyFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z);

void EnemyFight1(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z);

void EnemyFight2(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z);
#endif // FIGHT_HANDLER_H
