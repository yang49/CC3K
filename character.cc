#include "character.h"

int Character::getHp() {
   return this->Hp;
}

int Character::getAt() {
   return this->At;
}

int Character::getDf() {
   return this->Df;
}


void Character::setHp(int damage) {
   this->Hp = this->Hp - damage;
}

bool Character::dead() {
   if(Hp <= 0) {
      Hp = 0;
      return true;
   }
   else {
      return false;
   }
}


Character::~Character() {}
