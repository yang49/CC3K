#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"

class Treasure: public Item {
   int amount;
   public:
      Treasure();
      ~Treasure();
      int getAmount();
};

#endif
