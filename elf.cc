#include "elf.h"
#include "player.h"
#include "drow.h"

Elf::Elf() {
   this->s = 'E';
   this->Hp = 140;
   this->At = 30;
   this->Df = 10;
}


void Elf::useOn(Player &pl) {
   int dmg = this->At; 
   int def = pl.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   pl.setHp(tot);
   pl.setHp(tot);
}


void Elf::useOn(Drow &pl) {
   int dmg = this->At; 
   int def = pl.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   pl.setHp(tot);
}
