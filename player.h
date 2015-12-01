#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"
#include <string>

class Enemy;
class Dwarf;

class Player: public Character {
   protected:
   char role;
   int gold;
   int maxHp;
   int defAt;
   int defDf;
   bool neutral;
   public:
   Player();
   virtual ~Player() = 0;
   int getGold();
   char getRole();
   bool ifNeu();
   void setNeu();
   void addGold(int);
	bool isItOver();
   
   virtual void attack(Enemy &);
   virtual void useOn(Enemy &);
   virtual void useOn(Dwarf &);
   void reset();
   virtual void addHp(int value);
   virtual void addAt(int value);
   virtual void addDf(int value);
};

#endif
