#include "goblin.h"
#include "dwarf.h"
#include "enemy.h"

Goblin::Goblin() {
   this->role = 'g';
   this->Hp = 110;
   this->At = 15;
   this->Df = 20;
   this->maxHp = 110;
   this->defAt = 15;
   this->defDf = 20;
}

void Goblin::attack(Enemy &em) {
   em.useOn(*this);
}

void Goblin::useOn(Enemy &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
   if (em.dead()) this->gold += 5;
}

void Goblin::useOn(Dwarf &em) {
	Enemy *tem = static_cast<Enemy*>(&em);
   this->useOn(*tem);
}

Goblin::~Goblin() {}
