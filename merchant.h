#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "enemy.h"

class Player;
//class Goblin;
//class Drow;

class Merchant: public Enemy {
   public:
      Merchant();
      ~Merchant() {}
      void attack(Player &);
//      void useOn(Player &);
};

#endif
