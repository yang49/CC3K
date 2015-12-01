#ifndef __DROW_H__
#define __DROW_H__
#include "player.h"

class Enemy;

class Drow: public Player {
   public:
      Drow();
      ~Drow();
		void attack(Enemy &em);
      void addHp(int value);
      void addAt(int value);
      void addDf(int value);
};

#endif
