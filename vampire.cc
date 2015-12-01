#include "vampire.h"
#include "enemy.h"
#include "dwarf.h"
#include <iostream>

//constructor
Vampire::Vampire() {
   this->role = 'v';
   this->Hp = 50;    // 50
   this->At = 25;    // 25
   this->Df = 25;    // 25
   this->maxHp = 99999999;
   this->defAt = 25;
   this->defDf = 25;
}

void Vampire::useOn(Enemy &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
   this->setHp(-5);
}

void Vampire::useOn(Dwarf &em) {
   int dmg = this->At; 
   int def = em.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   em.setHp(tot);
   this->setHp(5);
}

//destructor
Vampire::~Vampire() {}

