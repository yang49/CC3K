#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"

class Item;

class Dragon: public Enemy {
   Item *theH;
   public:
      Dragon();
      ~Dragon();
		bool hasEgg();
      void setH(Item *);
      void setTaken();
      void autoMove(int &, int &);
};

#endif
