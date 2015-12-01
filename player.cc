#include "player.h"
#include "enemy.h"
#include "dwarf.h"
#include <string>

Player::Player():gold(0), neutral(true){
   this->s = '@';
}

int Player::getGold() {
   return this->gold;
}
   
char Player::getRole() {
   return this->role;
}

bool Player::ifNeu() {
   return this->neutral;
}

void Player::setNeu() {
   this->neutral = !(this->ifNeu());
}

//======================
void Player::attack(Enemy &em) {
   em.useOn(*this);
}

void Player::useOn(Enemy &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
}

void Player::useOn(Dwarf &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
}

//======================
void Player::addGold(int n) {
   gold = gold + n;
}


bool Player::isItOver() {
	return (this->Hp <= 0);
}


void Player::reset() {
   At = defAt;
   Df = defDf;
}

void Player::addHp(int value) {// need to be changed
   Hp += value;
   if (Hp > this->maxHp)
      Hp = maxHp;
}


void Player::addAt(int value) {
   At += value;
}

void Player::addDf(int value) {
   Df += value;
}

Player::~Player() {}
