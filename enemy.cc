#include "enemy.h"
#include "player.h"
#include <cstdlib>

#include "drow.h"
#include "goblin.h"

Enemy::Enemy(): hostile(true) {}

Enemy::~Enemy(){}

void Enemy::attack(Player &pl) {
   pl.useOn(*this);
}


void Enemy::useOn(Player &pl) {
   int dmg = this->At; 
   int def = pl.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   pl.setHp(tot);
}

void Enemy::useOn(Drow &pl) {
   int dmg = this->At; 
   int def = pl.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   pl.setHp(tot);
}


void Enemy::useOn(Goblin &pl) {
   int dmg = this->At; 
   int def = pl.getDf();
   double total = ((100.0 / (100.0 + def)) * dmg);
   int tot = (int)total;
   pl.setHp(tot);
}



bool Enemy::ifHost() {
   return this->hostile;
}


void Enemy::autoMove(int &newr, int &newc) {
//   srand(time(NULL));
   newr = r + rand() % 3 - 1;
   newc = c + rand() % 3 - 1;
}

// it replace

         /*
         dr = rand() % 3 - 1;
         dc = rand() % 3 - 1;
         */
