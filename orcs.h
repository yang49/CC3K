#ifndef __ORCS_H__
#define __ORCS_H__
#include "enemy.h"

class Player;
class Goblin;

class Orcs: public Enemy {
   public:
      Orcs();
      ~Orcs() {};
      void useOn(Goblin &);
};

#endif
