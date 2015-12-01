#ifndef __TROLL_H__
#define __TROLL_H__
#include "player.h"

class Enemy;
class Dwarf;

class Troll: public Player {
   public:
      Troll();
      ~Troll();
      void useOn(Enemy &);
      void useOn(Dwarf &);
};

#endif
