#include "dwarf.h"
#include "player.h"
//#include "drow.h"
//#include "goblin.h"

Dwarf::Dwarf() {
   this->s = 'F';
   this->Hp = 100;
   this->At = 20;
   this->Df = 30;
}

void Dwarf::attack(Player &pl) {
   pl.useOn(*this);
}
