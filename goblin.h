#ifndef __GIBLIN_H__
#define __GIBLIN_H__
#include "player.h"

class Enemy;
class Dwarf;

class Goblin: public Player {
   public:
      Goblin();
      ~Goblin();
		void attack(Enemy &);
      void useOn(Enemy &);
      void useOn(Dwarf &);
};

#endif
