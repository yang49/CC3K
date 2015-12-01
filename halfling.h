#ifndef __HALFLING_H__
#define __HALFLING_H__
#include "enemy.h"

class Player;
//class Goblin;
//class Drow;

class Halfling: public Enemy {
  public:
   Halfling();
   ~Halfling() {}
   void attack(Player &);  // if hp = 0, 50% no damage
};

#endif
