#include "orcs.h"
#include "player.h"
#include "goblin.h"

Orcs::Orcs() {
   this->s = 'O';
   this->Hp = 180;
   this->At = 30;
   this->Df = 25;
}




void Orcs::useOn(Goblin &pl) {
   int dmg = this->At + (this->At / 2); 
   int def = pl.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   pl.setHp(tot);
}
