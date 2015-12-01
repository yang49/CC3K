#ifndef __ELF_H__
#define __ELF_H__

#include "enemy.h"
class Player;
class Drow;

class Elf: public Enemy {
   public:
      Elf();
      ~Elf() {}
      void useOn(Player &);
      void useOn(Drow &);
};
#endif
