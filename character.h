#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include <string>

class Character: public Cell {
  protected:
   int Hp;
   int At;
   int Df;
  public:
   Character() {}
   int getHp();
   int getAt();
   int getDf();
   void setHp(int);
   virtual ~Character() = 0;
   
   
   bool dead();
};

#endif
