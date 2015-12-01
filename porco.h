#ifndef __PORCO_H__
#define __PORCO_H__
#include "player.h"

class Enemy;
class Dwarf;

class Porco: public Player {
   public:
      Porco();
      ~Porco();
      void useOn(Enemy &);
		void useOn(Dwarf &);
};

#endif
