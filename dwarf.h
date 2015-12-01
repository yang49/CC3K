#ifndef __DWARF_H__
#define __DWARF_H__
#include "enemy.h"

class Player;
//class Goblin;
//class Drow;

class Dwarf: public Enemy {
   public:
      Dwarf();
      ~Dwarf() {}
      void attack(Player &);
};

#endif
