#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include "player.h"

class Dwarf;
class Enemy;

class Vampire: public Player {
   public:
      Vampire();
      ~Vampire();
      void useOn(Enemy &);
      void useOn(Dwarf &);
};

#endif
