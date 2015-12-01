#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "character.h"

class Player;
class Drow;
class Goblin;

class Enemy: public Character {
  protected:
   bool hostile;
  public:
   Enemy();
   virtual ~Enemy() = 0;
   bool ifHost();
   virtual void autoMove(int &, int &);
   virtual void attack(Player &);
   virtual void useOn(Player &);
   virtual void useOn(Drow &);
   virtual void useOn(Goblin &);
 };

#endif
