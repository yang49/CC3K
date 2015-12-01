#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <ncurses.h>
#include <string>
#include "cell.h"
#include "board.h"
#include "character.h"
#include "player.h"
#include "vampire.h"
#include "shade.h"
#include "goblin.h"
#include "drow.h"
#include "troll.h"
#include "porco.h"
#include "enemy.h"
#include "human.h"
#include "halfling.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "yang.h"
#include "item.h"
#include "room.h"


class Grid {
	Cell ***theGrid;
	Board *td;
	Player *thePC;
	Room theCha[5];
	int level;
	int dra; // determine the number of dragon
  
	std::string desc;
	std::string file;
	Enemy *myEn[20];
	Item *myPo[20];
	Item *myTr[10];

 public:
   Grid();
   ~Grid();
  
	static Grid *game;
	static Grid *getInstance();
	static void cleanUp();
	static void easyPlay(std::string fname = "dungeon.txt");
	static void commandPlay(std::string fname = "dungeon.txt");
	void setFile(std::string);
	int getScore();
	bool isItOver();
	bool isItWin();
	int getLevel();
	void clearStuff();
	void newFloor(std::string fname = "dungeon.txt");
	void newArrange(std::string fname);
	void restart();
	void addPlayer(char pl = 's');
	bool nearPotion();                // determine to change action description
	void genePotion();
	void geneTrea();
	void geneEnemy();
	void start();
	void startArg();
	bool ifRange(int &r, int &c);
	void emAction();                   // ifAtmpt(), attack or move
	void pcMove(std::string m);
	void eatPotion(std::string);       // player eat potions
	void pcAttack(std::string m);      // attack for player character


  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
  friend std::ostream &operator<<(std::ostream &out, const Grid *g);
};

#endif
