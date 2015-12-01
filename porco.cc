#include "porco.h"
#include "dwarf.h"
#include "enemy.h"

Porco::Porco() {
   this->role = 'x';
   this->Hp = 999;
   this->At = 60;
   this->Df = 75;
   this->maxHp = 1200;
   this->defAt = 60;
   this->defDf = 75;
}

void Porco::useOn(Enemy &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
   if (em.dead()) this->Hp += 50;
}

void Porco::useOn(Dwarf &em) {
	Enemy *tem = static_cast<Enemy*>(&em);
   this->useOn(*tem);
}

Porco::~Porco() {}
