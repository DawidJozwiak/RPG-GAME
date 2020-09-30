#include "player.h"

void Player::healthPotion(int potion){
    current_health = current_health + potion;
    }

void Player::staminaPotion(int potion){
        current_stamina = current_stamina + potion;
    }

Player::Player(){

}

Player::Player(int i, bool b, bool c, bool d){
    gold = i;
    sword = b;
    staff = c;
    bow = d;
}

int Player::gold = 2000;
bool Player::sword = false;
bool Player::staff = false;
bool Player::bow = false;
int Player::x = 0;
