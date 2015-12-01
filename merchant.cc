#include "merchant.h"
#include "player.h"
//#include "goblin.h"
//#include "drow.h"


Merchant::Merchant() {
   this->s = 'M';
   this->hostile = false;
   this->Hp = 30;
   this->At = 70;
   this->Df = 5;
}

void Merchant::attack(Player &pl) {
   pl.useOn(*this);
   if (pl.ifNeu()) pl.setNeu();
}
