#include "drow.h"
#include "enemy.h"

Drow::Drow() {
   this->role = 'd';
   this->Hp = 150;
   this->At = 25;
   this->Df = 15;
   this->maxHp = 150;
   this->defAt = 25;
   this->defDf = 15;
}

void Drow::addHp(int value) {
   Hp += (int)(value * 1.5);
   if (Hp > this->maxHp)
      Hp = maxHp;
}


void Drow::attack(Enemy &em) {
   em.useOn(*this);
}

void Drow::addAt(int value) {
   At += (int)(value * 1.5);
}

void Drow::addDf(int value) {
   Df += (int)(value * 1.5);
}

Drow::~Drow() {}
