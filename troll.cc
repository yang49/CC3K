#include "troll.h"
#include "dwarf.h"
#include "enemy.h"

//constructor
Troll::Troll() {
   this->role = 't';
   this->Hp = 120;
   this->At = 25;
   this->Df = 15;
   this->maxHp = 120;
   this->defAt = 25;
   this->defDf = 15;
}

void Troll::useOn(Enemy &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
   this->setHp(-5);
      if (this->Hp > this->maxHp) {
         this->Hp = this->maxHp;
      }
}

void Troll::useOn(Dwarf &em) {
	Enemy *tem = static_cast<Enemy*>(&em);
   this->useOn(*tem);
}

//destructor
Troll::~Troll() {}

