#include "halfling.h"
#include "player.h"
//#include "goblin.h"
//#include "drow.h"
#include <cstdlib>

Halfling::Halfling() {
   this->s = 'L';
   this->Hp = 100;
   this->At = 15;
   this->Df = 20;
}

void Halfling::attack(Player &pl) {
   srand(time(NULL));
   int chance = rand() % 2;
   if (chance == 0) pl.useOn(*this);
   else return;
}
