#include "fight_handler.h"
#include <cstdlib>
#include <thread>
#include <iostream>
#include <QTextStream>
#include <QKeyEvent>
#include <QStateMachine>
#include "player.h"
#include "fighthell.h"
#include "QAction"
Fight * fight;

void fight_handler(){
    Player p;
    p.x = 0;
    Ally a(2, 200, 100);
    Ally b(1, 100, 200);
    Ally c(2, 150, 150);
    srand(time(NULL));
    Enemy x(1, 100, 100);
    Enemy y(3, 300, 200);
    Enemy z(1, 100, 100);
    a.setCurrent_health(a.getMax_health());
    b.setCurrent_health(b.getMax_health());
    c.setCurrent_health(c.getMax_health());
    x.setCurrent_health(x.getMax_health());
    y.setCurrent_health(y.getMax_health());
    z.setCurrent_health(z.getMax_health());
    if(p.sword == false){
        a.setWeapon_damage(50);
    }
    else{
        a.setWeapon_damage(100);
    }
    if(p.staff == false){
        b.setWeapon_damage(50);
    }
    else{
        b.setWeapon_damage(100);
    }
    if(p.bow == false){
        c.setWeapon_damage(50);
    }
    else{
        c.setWeapon_damage(100);
    }
    x.setWeapon_damage(100);
    y.setWeapon_damage(100);
    z.setWeapon_damage(100);

    fight = new Fight();
    fight->show();
    WarriorFight(a , b, c, x, y, z);
  }

void FightHellHandler(){
    Player p;
    p.x = 0;
    Ally a(2, 200, 100);
    Ally b(1, 100, 200);
    Ally c(2, 150, 150);
    srand(time(NULL));
    Enemy x(1, 300, 100);
    Enemy y(3, 500, 200);
    Enemy z(1, 300, 100);
    a.setCurrent_health(a.getMax_health());
    b.setCurrent_health(b.getMax_health());
    c.setCurrent_health(c.getMax_health());
    x.setCurrent_health(x.getMax_health());
    y.setCurrent_health(y.getMax_health());
    z.setCurrent_health(z.getMax_health());
    if(p.sword == false){
        a.setWeapon_damage(50);
    }
    else{
        a.setWeapon_damage(100);
    }
    if(p.staff == false){
        b.setWeapon_damage(50);
    }
    else{
        b.setWeapon_damage(100);
    }
    if(p.bow == false){
        c.setWeapon_damage(50);
    }
    else{
        c.setWeapon_damage(100);
    }
    x.setWeapon_damage(100);
    y.setWeapon_damage(100);
    z.setWeapon_damage(100);
    fight = new Fight();
    fight->setBackgroundBrush(QBrush(QImage(":/images/Hell.png")));
    fight->show();
    WarriorFight(a , b, c, x, y, z);
}

void FightHandlerRuins(){
    Player p;
    p.x = 0;
    Ally a(2, 200, 100);
    Ally b(1, 100, 200);
    Ally c(2, 150, 150);
    srand(time(NULL));
    Enemy x(1, 200, 100);
    Enemy y(3, 400, 200);
    Enemy z(1, 200, 100);
    a.setCurrent_health(a.getMax_health());
    b.setCurrent_health(b.getMax_health());
    c.setCurrent_health(c.getMax_health());
    x.setCurrent_health(x.getMax_health());
    y.setCurrent_health(y.getMax_health());
    z.setCurrent_health(z.getMax_health());
    if(p.sword == false){
        a.setWeapon_damage(50);
    }
    else{
        a.setWeapon_damage(100);
    }
    if(p.staff == false){
        b.setWeapon_damage(50);
    }
    else{
        b.setWeapon_damage(100);
    }
    if(p.bow == false){
        c.setWeapon_damage(50);
    }
    else{
        c.setWeapon_damage(100);
    }
    x.setWeapon_damage(100);
    y.setWeapon_damage(100);
    z.setWeapon_damage(100);
    fight = new Fight();
    fight->setBackgroundBrush(QBrush(QImage(":/images/Ruins.png")));
    fight->show();
    WarriorFight(a , b, c, x, y, z);
}
void lost(){
    Player pl;
    result = false;
    if(pl.x == 0){
    pl.x++;
    pl.gold = (pl.gold - 500);
    if(pl.gold < 0)
        pl.gold = 0;
    fight->Back();
    }
}

void won(){
    Player pl;
    result = false;
    if(pl.x == 0){
    pl.x++;
    pl.gold = (pl.gold + 1000);
    fight->Back();
    }
}

int choice;
int target;
int skill;
bool result;

void WarriorFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z){
fight -> vw -> Variables(a.getCurrent_health(), a.getStatus());
fight -> vd -> Variables(y.getCurrent_health(), y.getStatus());
fight -> vm -> Variables(b.getCurrent_health(), b.getStatus());
fight -> vr -> Variables(c.getCurrent_health(), c.getStatus());
fight -> vg -> Variables(x.getCurrent_health(), x.getStatus());
fight -> vg2 -> Variables(z.getCurrent_health(), z.getStatus());

if(a.getCurrent_health() <= 0 && b.getCurrent_health() <= 0 && c.getCurrent_health() <= 0){
fight -> txt -> Update("You lost the battle and have to pay 500 gold for healers");
fight -> delay();
lost();
}
if(x.getCurrent_health()<=0 && y.getCurrent_health() <= 0 && z.getCurrent_health() <= 0){
    fight -> txt -> Update("You won the battle and gained 1000 gold as a loot");
    fight -> delay();
    won();
}
   if(a.getCurrent_health() > 0){
       if(a.getStatus() == true){
            fight -> delay();
            fight -> txt -> Update("Warrior is stunned!");
              a.setStatus(false);
            MageFight(a , b, c, x, y, z);
        }
        else{
           fight -> txt -> Update("Warrior's turn");
           fight -> delay();
           Character * ch;
           ch = &a;
            choice = rand() % 2 + 1;
            switch(choice){
                  case 1:
                target = rand() % 3 + 1;
                     switch(target){
                        case 1:
                              fight -> txt -> Update("Warrior used attack on Enemy1");
                              fight -> delay();
                              x.setCurrent_health(ch -> Damage(x.getCurrent_health(), a.getClassCoefficient()));
                              MageFight(a , b, c, x, y, z);
                         break;

                        case 2:
                              fight -> txt -> Update("Warrior used attack on Dark Mage");
                              fight -> delay();
                              y.setCurrent_health(ch -> Damage(y.getCurrent_health(), a.getClassCoefficient()));
                              MageFight(a , b, c, x, y, z);
                         break;

                        case 3:
                              fight -> txt -> Update("Warrior used attack on Enemy2");
                              fight -> delay();
                              z.setCurrent_health(ch -> Damage(z.getCurrent_health(), a.getClassCoefficient()));
                              MageFight(a , b, c, x, y, z);
                         break;

              }
                  case 2:
                skill = rand() % 2 + 1;
                switch(skill){
                     case 1:
                    fight -> txt -> Update("Warrior used smash!");
                    fight -> delay();
                      x.setCurrent_health(x.getCurrent_health() - 50);

                      y.setCurrent_health(y.getCurrent_health() - 50);

                      z.setCurrent_health(z.getCurrent_health() - 50);
                      MageFight(a , b, c, x, y, z);

                     case 2:
                    target = rand() % 3 + 1;                 
                        switch(target){

                           case 1:
                            fight -> txt -> Update("Warrior used stun on Enemy 1!");
                            fight -> delay();
                                x.setStatus(true);
                                MageFight(a , b, c, x, y, z);
                            break;

                           case 2:
                            fight -> txt -> Update("Warrior used stun on Dark Mage");
                            fight -> delay();
                                y.setStatus(true);
                                MageFight(a , b, c, x, y, z);
                            break;

                           case 3:
                            fight -> txt -> Update("Warrior used stun on Enemy 2!");
                            fight -> delay();
                                z.setStatus(true);
                                MageFight(a , b, c, x, y, z);
                            break;

                         }
                  }
                 case 3:
                 MageFight(a , b, c, x, y, z);
                break;
        }

      }

     }
   MageFight(a , b, c, x, y, z);
}



void MageFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z){
    fight -> vw -> Variables(a.getCurrent_health(), a.getStatus());
    fight -> vd -> Variables(y.getCurrent_health(), y.getStatus());
    fight -> vm -> Variables(b.getCurrent_health(), b.getStatus());
    fight -> vr -> Variables(c.getCurrent_health(), c.getStatus());
    fight -> vg -> Variables(x.getCurrent_health(), x.getStatus());
    fight -> vg2 -> Variables(z.getCurrent_health(), z.getStatus());
    if(a.getCurrent_health()<=0 && b.getCurrent_health() <= 0 && c.getCurrent_health() <= 0){
        fight -> txt -> Update("You lost the battle and have to pay 500 gold for healers");
        fight -> delay();
        lost();
         }
         if(x.getCurrent_health()<=0 && y.getCurrent_health() <= 0 && z.getCurrent_health() <= 0){
             fight -> txt -> Update("You won the battle and gained 1000 gold as a loot");
             fight -> delay();
             won();
         }
    if(b.getCurrent_health() > 0){
        if(b.getStatus() == true){
              fight -> txt -> Update("Mage is stunned!");
              fight -> delay();
              b.setStatus(false);
              RougeFight(a , b, c, x, y, z);
        }

        else{
            fight -> txt -> Update("Mage's turn!");
            fight -> delay();
            Character *ch;
            ch = &b;
            choice = rand() % 2 + 1;
            switch(choice){
                  case 1:
                target = rand() % 3 + 1;              
                     switch(target){
                     case 1:

                         fight -> txt -> Update("Mage used attack on Enemy 1");
                         fight -> delay();
                           x.setCurrent_health(ch -> Damage(x.getCurrent_health(), b.getClassCoefficient()));
                           RougeFight(a , b, c, x, y, z);
                      break;

                     case 2:
                         fight -> txt -> Update("Mage used attack on Dark Mage");
                         fight -> delay();
                           y.setCurrent_health(ch -> Damage(y.getCurrent_health(), b.getClassCoefficient()));
                           RougeFight(a , b, c, x, y, z);
                      break;

                     case 3:
                         fight -> txt -> Update("Mage used attack on Enemy 2");
                         fight -> delay();
                           z.setCurrent_health(ch -> Damage(z.getCurrent_health(), b.getClassCoefficient()));
                           RougeFight(a , b, c, x, y, z);
                      break;

              }
                   
                  case 2:
                    skill = rand() % 2 + 1;
                      switch(skill){
                        case 1:
                          target = rand() % 3 + 1;

                      switch(target){

                          case 1:
                             fight -> txt -> Update("Mage used  Lightning on Enemy 1");
                             fight -> delay();
                             x.setStatus(true);
                             x.setCurrent_health(x.getCurrent_health() - 50);
                             RougeFight(a , b, c, x, y, z);
                          case 2:
                             fight -> txt -> Update("Mage Lightning on Dark Mage");
                             fight -> delay();
                             y.setStatus(true);
                             y.setCurrent_health(y.getCurrent_health() - 50);
                             RougeFight(a , b, c, x, y, z);
                          case 3:
                              fight -> txt -> Update("Mage used  Lightning on Enemy 2");
                              fight -> delay();
                             z.setStatus(true);
                             z.setCurrent_health(z.getCurrent_health() - 50);
                             RougeFight(a , b, c, x, y, z);
                          }
                         case 2:
                          target = rand() % 3 + 1;

                          switch(target){
                          case 1:
                              fight -> txt -> Update("Mage used Heal on Warrior");
                              fight -> delay();
                             a.setCurrent_health(a.getCurrent_health() + 100);
                             RougeFight(a , b, c, x, y, z);
                          case 2:
                              fight -> txt -> Update("Mage used Heal on Himself");
                              fight -> delay();
                             b.setCurrent_health(b.getCurrent_health() + 100);
                             RougeFight(a , b, c, x, y, z);
                          case 3:
                              fight -> txt -> Update("Mage used Heal on Rouge");
                              fight -> delay();
                             c.setCurrent_health(c.getCurrent_health() + 100);
                             RougeFight(a , b, c, x, y, z);
                          }
                     }
        }

      }
     }
    RougeFight(a , b, c, x, y, z);

}

void RougeFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z){
    fight -> vw -> Variables(a.getCurrent_health(), a.getStatus());
    fight -> vd -> Variables(y.getCurrent_health(), y.getStatus());
    fight -> vm -> Variables(b.getCurrent_health(), b.getStatus());
    fight -> vr -> Variables(c.getCurrent_health(), c.getStatus());
    fight -> vg -> Variables(x.getCurrent_health(), x.getStatus());
    fight -> vg2 -> Variables(z.getCurrent_health(), z.getStatus());
    skill = rand() % 2 + 1;
    target = rand() % 3 + 1;
    choice = rand() % 2 + 1;
    if(a.getCurrent_health()<=0 && b.getCurrent_health() <= 0 && c.getCurrent_health() <= 0){
   fight -> txt -> Update("You lost the battle and have to pay 500 gold for healers");
   fight -> delay();
   lost();
    }
    if(x.getCurrent_health()<=0 && y.getCurrent_health() <= 0 && z.getCurrent_health() <= 0){
        fight -> txt -> Update("You won the battle and gained 1000 gold as a loot");
        fight -> delay();
        won();
    }
    if(c.getCurrent_health() > 0){

        if(c.getStatus() == true){
            fight -> txt -> Update("Rouge's stunned!");
            fight -> delay();
              c.setStatus(false);
              EnemyFight(a , b, c, x, y, z);
        }
        else{
            fight -> txt -> Update("Rouge's turn!");
            fight -> delay();
            Character *ch;
            ch = &c;
            switch(choice){
                  case 1:                
                target = rand() % 3 + 1;
                     switch(target){
                     case 1:
                           fight -> txt -> Update("Rouge's attacked Enemy 1");
                           fight -> delay();
                           x.setCurrent_health(ch -> Damage(x.getCurrent_health(), c.getClassCoefficient()));
                           EnemyFight(a , b, c, x, y, z);
                      break;

                     case 2:
                          fight -> txt -> Update("Rouge's attacked Dark Mage");
                          fight -> delay();
                           y.setCurrent_health(ch -> Damage(y.getCurrent_health(), c.getClassCoefficient()));
                           EnemyFight(a , b, c, x, y, z);
                      break;

                     case 3:
                           fight -> txt -> Update("Rouge's attacked Enemy 2");
                           fight -> delay();
                           z.setCurrent_health(ch -> Damage(z.getCurrent_health(), c.getClassCoefficient()));
                           EnemyFight(a , b, c, x, y, z);
                      break;
              }
                   case 2:
                     switch(skill){
                     case 1:
                         target = rand() % 3 + 1;

                     switch(target){
                     case 1:
                         fight -> txt -> Update("Rouge's used double attack on Enemy 1");
                         fight -> delay();
                         x.setCurrent_health(ch -> Damage(x.getCurrent_health(), c.getClassCoefficient()));
                         x.setCurrent_health(ch -> Damage(x.getCurrent_health(), c.getClassCoefficient()));
                         EnemyFight(a , b, c, x, y, z);
                     case 2:
                         fight -> txt -> Update("Rouge's used double attack on Dark Mage");
                         fight -> delay();
                         y.setCurrent_health(ch -> Damage(y.getCurrent_health(), c.getClassCoefficient()));
                         y.setCurrent_health(ch -> Damage(y.getCurrent_health(), c.getClassCoefficient()));
                         EnemyFight(a , b, c, x, y, z);
                     case 3:
                         fight -> txt -> Update("Rouge's used double attack on Enemy 2");
                         fight -> delay();
                         z.setCurrent_health(ch -> Damage(z.getCurrent_health(), c.getClassCoefficient()));
                         z.setCurrent_health(ch -> Damage(z.getCurrent_health(), c.getClassCoefficient()));
                         EnemyFight(a , b, c, x, y, z);
                     }
                     case 2:

                         switch(target){
                         case 1:
                             fight -> txt -> Update("Rouge's used distance shot on Enemy 1");
                             fight -> delay();
                             x.setCurrent_health(z.getCurrent_health() - 50);
                             EnemyFight(a , b, c, x, y, z);
                         case 2:
                             fight -> txt -> Update("Rouge's used distance shot on Dark Mage");
                             fight -> delay();
                             y.setCurrent_health(y.getCurrent_health() - 100);
                             EnemyFight(a , b, c, x, y, z);
                         case 3:
                             fight -> txt -> Update("Rouge's used distance shot on Enemy 2");
                             fight -> delay();
                             z.setCurrent_health(z.getCurrent_health() - (150));
                             EnemyFight(a , b, c, x, y, z);
                      }
                   }

        }

      }

     }
    EnemyFight(a , b, c, x, y, z);
}


void EnemyFight(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z){
    fight -> vw -> Variables(a.getCurrent_health(), a.getStatus());
    fight -> vd -> Variables(y.getCurrent_health(), y.getStatus());
    fight -> vm -> Variables(b.getCurrent_health(), b.getStatus());
    fight -> vr -> Variables(c.getCurrent_health(), c.getStatus());
    fight -> vg -> Variables(x.getCurrent_health(), x.getStatus());
    fight -> vg2 -> Variables(z.getCurrent_health(), z.getStatus());
    skill = rand() % 2 + 1;
    target = rand() % 3 + 1;
    choice = rand() % 2 + 1;
    if(a.getCurrent_health() <= 0 && b.getCurrent_health() <= 0 && c.getCurrent_health() <= 0){
   fight -> txt -> Update("You lost the battle and have to pay 500 gold for healers");
   fight -> delay();
   lost();
    }
    if(x.getCurrent_health()<=0 && y.getCurrent_health() <= 0 && z.getCurrent_health() <= 0){;
        fight -> txt -> Update("You won the battle and gained 1000 gold as a loot");
        fight -> delay();
        won();
    }
    if(x.getCurrent_health() > 0){

        if(x.getStatus() == true){
            fight -> txt -> Update("Enemy 1 is stunned!");
            fight -> delay();
              x.setStatus(false);
              EnemyFight1(a , b, c, x, y, z);
        }
        else{
            fight -> txt -> Update("Enemy 1's turn!");
            fight -> delay();
            Character *ch;
            ch = &x;
            choice = rand() % 1 + 1;
            switch(choice){
                  case 1:                
                     switch(target){
                     case 1:
                         fight -> txt -> Update("Enemy 1 attacked Warrior");
                           a.setCurrent_health(ch -> Damage(a.getCurrent_health(), x.getClassCoefficient()));
                           EnemyFight1(a , b, c, x, y, z);
                           fight -> delay();
                      break;

                     case 2:
                         fight -> txt -> Update("Enemy 1 attacked Mage");
                         fight -> delay();
                           b.setCurrent_health(ch -> Damage(b.getCurrent_health(), x.getClassCoefficient()));
                           EnemyFight1(a , b, c, x, y, z);
                      break;

                     case 3:
                         fight -> txt -> Update("Enemy 1 attacked Rouge");
                         fight -> delay();
                           c.setCurrent_health(ch -> Damage(c.getCurrent_health(), x.getClassCoefficient()));
                           EnemyFight1(a , b, c, x, y, z);
                      break;
                     }
                   case 2:
                fight -> txt -> Update("Enemy 1 used Smash");
                fight -> delay();
                         a.setCurrent_health(a.getCurrent_health() - 50);
                         b.setCurrent_health(b.getCurrent_health() - 50);
                         c.setCurrent_health(c.getCurrent_health() - 50);
                         EnemyFight1(a , b, c, x, y, z);
              }

        }

      }
    EnemyFight1(a , b, c, x, y, z);
     }



void EnemyFight1(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z){
    fight -> vw -> Variables(a.getCurrent_health(), a.getStatus());
    fight -> vd -> Variables(y.getCurrent_health(), y.getStatus());
    fight -> vm -> Variables(b.getCurrent_health(), b.getStatus());
    fight -> vr -> Variables(c.getCurrent_health(), c.getStatus());
    fight -> vg -> Variables(x.getCurrent_health(), x.getStatus());
    fight -> vg2 -> Variables(z.getCurrent_health(), z.getStatus());
    skill = rand() % 2 + 1;
    target = rand() % 3 + 1;
    choice = rand() % 2 + 1;
    fight -> delay();
         if(a.getCurrent_health() <= 0 && b.getCurrent_health() <= 0 && c.getCurrent_health() <= 0){
           fight -> txt -> Update("You lost the battle and have to pay 500 gold for healers");
           fight -> delay();
           lost();
           }
           if(x.getCurrent_health()<=0 && y.getCurrent_health() <= 0 && z.getCurrent_health() <= 0){
           fight -> txt -> Update("You won the battle and gained 1000 gold as a loot");
           fight -> delay();
            won();
           }
    if(y.getCurrent_health() > 0){
        if(y.getStatus() == true){
            fight -> txt -> Update("Dark Mage is stunned!");
            fight -> delay();
              y.setStatus(false);
              EnemyFight2(a , b, c, x, y, z);
        }
        else{
            fight -> txt -> Update("Dark Mage's turn");
            Character *ch;
            ch = &y;
            switch(choice){
                  case 1:
                     switch(target){
                     case 1:
                         fight -> txt -> Update("Dark Mage attacked Warrior");
                           a.setCurrent_health(ch -> Damage(a.getCurrent_health(), y.getClassCoefficient()));
                           EnemyFight2(a , b, c, x, y, z);
                           fight -> delay();
                      break;

                     case 2:
                         fight -> txt -> Update("Dark Mage attacked Mage");
                         fight -> delay();
                           b.setCurrent_health(ch -> Damage(b.getCurrent_health(), y.getClassCoefficient()));
                           EnemyFight2(a , b, c, x, y, z);
                      break;

                     case 3:
                         fight -> txt -> Update("Dark Mage attacked Rouge");
                         fight -> delay();
                           c.setCurrent_health(ch -> Damage(c.getCurrent_health(), y.getClassCoefficient()));
                           EnemyFight2(a , b, c, x, y, z);
                      break;
                     }
                 case 2:
                     switch(skill){
                     case 1:
                         switch(target){
                     case 1:
                             fight -> txt -> Update("Dark Mage used Dark Transaction on Warrior");
                             fight -> delay();
                           a.setCurrent_health(ch -> Damage(a.getCurrent_health(), y.getClassCoefficient()));
                           y.setCurrent_health(y.getCurrent_health() + 100);
                           EnemyFight2(a , b, c, x, y, z);
                      break;

                     case 2:
                             fight -> txt -> Update("Dark Mage used Dark Transaction on Mage");
                             fight -> delay();
                           b.setCurrent_health(ch -> Damage(b.getCurrent_health(), y.getClassCoefficient()));
                           y.setCurrent_health(y.getCurrent_health() + 100);
                           EnemyFight2(a , b, c, x, y, z);
                      break;

                     case 3:
                             fight -> txt -> Update("Dark Mage used Dark Transaction on Rouge");
                             fight -> delay();
                           c.setCurrent_health(ch -> Damage(c.getCurrent_health(), y.getClassCoefficient()));
                           y.setCurrent_health(y.getCurrent_health() + 100);
                           EnemyFight2(a , b, c, x, y, z);
                      break;
                     }
                     case 2:
                         fight -> txt -> Update("Dark Mage used Blood ties\nHim and your team are stunned!");
                         fight -> delay();
                         y.setStatus(true);
                         a.setStatus(true);
                         b.setStatus(true);
                         c.setStatus(true);
                         EnemyFight2(a , b, c, x, y, z);
            }

        }

      }
     }
    EnemyFight2(a , b, c, x, y, z);

}

void EnemyFight2(Ally &a, Ally &b, Ally &c, Enemy &x, Enemy &y, Enemy &z){
    if(a.getCurrent_health() <= 0 && b.getCurrent_health() <= 0 && c.getCurrent_health() <= 0){
   fight -> txt -> Update("You lost the battle and have to pay 500 gold for healers");
   fight -> delay();
   lost();
    }
    if(x.getCurrent_health()<=0 && y.getCurrent_health() <= 0 && z.getCurrent_health() <= 0){;
        fight -> txt -> Update("You won the battle and gained 1000 gold as a loot");
        fight -> delay();
        won();
    }
    fight -> vw -> Variables(a.getCurrent_health(), a.getStatus());
    fight -> vd -> Variables(y.getCurrent_health(), y.getStatus());
    fight -> vm -> Variables(b.getCurrent_health(), b.getStatus());
    fight -> vr -> Variables(c.getCurrent_health(), c.getStatus());
    fight -> vg -> Variables(x.getCurrent_health(), x.getStatus());
    fight -> vg2 -> Variables(z.getCurrent_health(), z.getStatus());
    skill = rand() % 2 + 1;
    target = rand() % 3 + 1;
    choice = rand() % 2 + 1;

    if(z.getCurrent_health() > 0){

        if(z.getStatus() == true){
            fight -> txt -> Update("Enemy 2 is stunned!");
            fight -> delay();
            z.setStatus(false);
            WarriorFight(a , b, c, x, y, z);
        }
        else{
            Character *ch;
            ch = &z;
            fight -> txt -> Update("Enemy 2's turn!");
            fight -> delay();
            switch(choice){
                  case 1:

                switch(target){             
                case 1:
                    fight -> txt -> Update("Enemy 2 attacked Warrior");
                    fight -> delay();
                      a.setCurrent_health(ch -> Damage(a.getCurrent_health(), z.getClassCoefficient()));
                     WarriorFight(a , b, c, x, y, z);
                 break;

                case 2:
                    fight -> txt -> Update("Enemy 2 attacked Mage");
                    fight -> delay();
                      b.setCurrent_health(ch -> Damage(b.getCurrent_health(), z.getClassCoefficient()));
                      WarriorFight(a , b, c, x, y, z);
                 break;

                case 3:
                    fight -> txt -> Update("Enemy 2 attacked Rouge");
                    fight -> delay();
                      c.setCurrent_health(ch -> Damage(c.getCurrent_health(), z.getClassCoefficient()));
                      WarriorFight(a , b, c, x, y, z);
                 break;
                 }
            case 2:
                fight -> txt -> Update("Enemy 2 used Smash");
                fight -> delay();
                  a.setCurrent_health(a.getCurrent_health() - 50);
                  b.setCurrent_health(b.getCurrent_health() - 50);
                  c.setCurrent_health(c.getCurrent_health() - 50);
                  WarriorFight(a , b, c, x, y, z);
        }

      }
     }
    WarriorFight(a , b, c, x, y, z);
    }




