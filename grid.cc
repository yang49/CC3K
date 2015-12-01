#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "grid.h"
#include "welcome.h"
using namespace std;

Grid *Grid::game = 0;

Grid *Grid::getInstance() {
	if (!game) {
		game = new Grid;
		atexit(cleanUp);
	}
	return game;
}


void Grid::cleanUp() {
	delete game;
}


bool Grid::isItOver() {
	return this->thePC->isItOver();
}


bool Grid::isItWin() {
	if (level < 6) return false;
	return true;
}


void Grid::setFile(string fname) {
	this->file = fname;
}


void Grid::commandPlay(string fname) {
	 Welcome::welcome("choose.txt");
 	Grid *game = Grid::getInstance();
	if (fname == "dungeon.txt")
 		game->newFloor();
	else
		game->newArrange(fname);
 	char start;
 	cin >> start;
 	if (start == 'q') return;
 	if ((start != 'v') && (start != 't') &&
     	(start != 'd') && (start != 's') &&
     	(start != 'g') && (start != 'x')) {
     	game->addPlayer();
   }
 	else {game->addPlayer(start);}
	if (fname == "dungeon.txt") {
 		game->start();
	}
	else {
		game->startArg();
		game->setFile(fname);
	}
 	cout << *game << endl;
 	string cmd;
 	while (cin >> cmd) {
		if (cmd == "r") {
			game->restart();
	   	Welcome::welcome("choose.txt");
			if (fname == "dungeon.txt")
 				game->newFloor();
			else
				game->newArrange(fname);
 			cin >> start;
			if (start == 'q') return;
 			if ((start != 'v') && (start != 't') &&
     			(start != 'd') && (start != 's') &&
     			(start != 'g') && (start != 'x')) {
     			game->addPlayer();
     		}
 			else {game->addPlayer(start);}	
			if (fname == "dungeon.txt") {
		 		game->start();
			}
			else {
				game->startArg();
				game->setFile(fname);
			}
 			cout << *game << endl;
			continue;
		}
   	else if (cmd.at(0) == 'a') {
			if ((cmd.substr(1,2) == "no") or (cmd.substr(1,2) == "so") or
				 (cmd.substr(1,2) == "we") or (cmd.substr(1,2) == "ea") or
				 (cmd.substr(1,2) == "ne") or (cmd.substr(1,2) == "nw") or
				 (cmd.substr(1,2) == "se") or (cmd.substr(1,2) == "sw")) {
	      	game->pcAttack(cmd.substr(1,2));
				game->emAction();
			}
			else {
				cout << "ERROR: WRONG COMMAND!" << endl;
				continue;
			}
   	}
   	else if (cmd == "whosyourdaddy") {	// cheating case
      	game->thePC->setHp(-100000);
   	}
   	else if (cmd.at(0) == 'u') {
			if ((cmd.substr(1,2) == "no") or (cmd.substr(1,2) == "so") or
				 (cmd.substr(1,2) == "we") or (cmd.substr(1,2) == "ea") or
				 (cmd.substr(1,2) == "ne") or (cmd.substr(1,2) == "nw") or
				 (cmd.substr(1,2) == "se") or (cmd.substr(1,2) == "sw")) {
	      	game->eatPotion(cmd.substr(1,2));
				game->emAction();
			}
			else {
				cout << "ERROR: WRONG COMMAND!" << endl;
				continue;
			}
   	}
		else if (cmd.at(0) == 'q') break;
   	else if ((cmd == "no") or (cmd == "so") or
					(cmd == "we") or (cmd == "ea") or
					(cmd == "ne") or (cmd == "nw") or
					(cmd == "se") or (cmd == "sw")) {
				game->pcMove(cmd);
				if (game->isItWin()) {
				Welcome::end("wonc.txt", 25);
				cout << "	Your Score: " << game->getScore() << endl;
				if (game->getScore() < 10)
				cout << "   You need to improve your gaming talent :)" << endl;
				else if (game->getScore() < 20)
				cout << "   You exactly know how to play this game :)" << endl;
				else if (game->getScore() < 40)
				cout << "   You just beat 80 percent player in the WORLD!" << endl;
				else if (game->getScore() >= 40)
				cout << "   You are GODLIKE! Brilliant!" << endl;
				cout << "	 CONGRATULATION!" << endl;
				cout << "Copyright@ Junda Kong" << endl;
				cout << "Copyright@ Yang  Li" << endl;
				break;
				}
		}
		else {
			cout << "ERROR: WRONG COMMAND!" << endl;
			continue;
		}
		if (game->isItOver()) {
			Welcome::end("losec.txt", 27);
			cout << "!!!AHAHAHAHAHAHAHAHAHAH~~~~~!!!!" << endl;
			cout << "   SORRY! You're been KILLED!" << endl;
			cout << "        GAME OVER :(" << endl;
			break;
		}
   	cout << *game << endl;
    }
}


void Grid::easyPlay(string fname) {
	const char NO = 'w';
	const char SO = 's';
	const char WE = 'a';
	const char EA = 'd';
	const char NW = '1';
	const char NE = '3';
	const char SW = 'z';
	const char SE = 'c';
	 initscr();
    clear();
    noecho();
    cbreak();
	 curs_set(0);
    start_color();
   init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);	
	init_pair(3, COLOR_RED, COLOR_BLACK);
	 Welcome::welcome_win("choose1.txt");
	Grid *game = Grid::getInstance();
	if (fname == "dungeon.txt")
 		game->newFloor();
	else
		game->newArrange(fname);
	char start;
	cin >> start;
 	if (start == 'q'){
				clear();
				endwin();
				exit(0);
	}
 	if ((start != 'v') && (start != 't') &&
     	(start != 'd') && (start != 's') &&
     	(start != 'g') && (start != 'x')) {
     	game->addPlayer();
   }
 	else {game->addPlayer(start);}
	clear();
	if (fname == "dungeon.txt") {
 		game->start();
	}
	else {
		game->startArg();
		game->setFile(fname);
	}
	cout << game << endl;
	char cmd;
	while (cin >> cmd) {
	switch (cmd) {
		case 'r':
			game->restart();
	   	Welcome::welcome_win("choose1.txt");
			if (fname == "dungeon.txt")
 				game->newFloor();
			else
				game->newArrange(fname);
 			cin >> start;
 			if (start == 'q') {
				clear();
				endwin();
				exit(0);
			}
 			if ((start != 'v') && (start != 't') &&
     			(start != 'd') && (start != 's') &&
     			(start != 'g') && (start != 'x')) {
     			game->addPlayer();
   		}
 			else {game->addPlayer(start);}
 			clear();
 			if (fname == "dungeon.txt") {
 				game->start();
			}
			else {
				game->startArg();
				game->setFile(fname);
			}
 			cout << game << endl;
			continue; break;
		case 'P':		// cheating case
		   game->thePC->setHp(-100000);break;
		case 'q':
		clear();
		endwin();
		exit(0); break;
   	case NO:case SO:case WE:case EA:
		case NW:case NE:case SW:case SE:
			switch(cmd) {
				case NO:		game->pcMove("no");break;
				case SO:		game->pcMove("so");break;
				case WE:		game->pcMove("we");break;
				case EA:		game->pcMove("ea");break;
				case NW:		game->pcMove("nw");break;
				case NE:		game->pcMove("ne");break;
				case SW:		game->pcMove("sw");break;
				case SE:		game->pcMove("se");break;
			}
			if (game->isItWin()) {
				Welcome::welcome_win("won.txt");
				string win;
				stringstream winScore;
				winScore << "Your Score: " << game->getScore();
				getline(winScore, win);
				mvaddstr(24, 6, win.c_str());
				if (game->getScore() < 10)
				mvaddstr(25, 7, "You need to improve your gaming talent :)");
				else if (game->getScore() < 20)
				mvaddstr(25, 7, "You exactly know how to play this game :)");
				else if (game->getScore() < 40)
				mvaddstr(25, 7, "You just beat 80 percent player in the WORLD!");
				else if (game->getScore() >= 40)
				mvaddstr(25, 7, "You are GODLIKE! Brilliant!");
				mvaddstr(26, 7, "	Thank you for PLAYING! Press any key to quit.");
				mvaddstr(27, WIDTH-25, "Copyright@ Junda Kong");
				mvaddstr(28, WIDTH-25, "Copyright@ Yang  Li");
				refresh();
				cin >> cmd;
				clear();
				endwin();
				exit(0);
			} break;
		case 'j':
			cin >> cmd;
			switch (cmd) {
				case NO: game->pcAttack("no");break;
				case SO: game->pcAttack("so");break;
				case WE: game->pcAttack("we");break;
				case EA: game->pcAttack("ea");break;
				case NW: game->pcAttack("nw");break;
				case NE: game->pcAttack("ne");break;
				case SW: game->pcAttack("sw");break;
				case SE: game->pcAttack("se");break;
			} 
			game->emAction();
			break;
		case 'k':
			cin >> cmd;
			switch (cmd) {
   			case NO: game->eatPotion("no");break;
				case SO: game->eatPotion("so");break;
				case WE: game->eatPotion("we");break;
				case EA: game->eatPotion("ea");break;
				case NW: game->eatPotion("nw");break;
				case NE: game->eatPotion("ne");break;
				case SW: game->eatPotion("sw");break;
				case SE: game->eatPotion("se");break;
			}
			game->emAction();
			break;
		default:
			continue;
		}
		if (game->isItOver()) {
			Welcome::welcome_win("lose.txt");
			mvaddstr(26, 5, "   Press any Botton to quit :(");
			mvaddstr(25, 6, "   SORRY! You're been KILLED!");
			refresh();
			cin >> cmd;
			break;
		}
   cout << game;
    }
 endwin(); 
}


int Grid::getScore() {
	if (thePC->getRole() == 's')
		return (int)(this->thePC->getGold() * 1.5);
	else
		return this->thePC->getGold();
}



Grid::Grid(): theGrid(NULL), td(NULL), thePC(NULL), level(0), dra(0), file("default"){}
         
Grid::~Grid() {
	delete td;
   for (int i = 0; i < HEIGH; i++) {
      for (int j = 0; j < WIDTH; j++) {
         delete theGrid[i][j];
      }
      delete [] theGrid[i];
   }
   delete [] theGrid;
}   

int Grid::getLevel() {
   return level;
}

void Grid::clearStuff() {
   delete td;
   theGrid[thePC->getR()][thePC->getC()] = NULL;
   for (int i = 0; i < HEIGH; i++) {
      for (int j = 0; j < WIDTH; j++) {
         if (theGrid[i][j] != NULL)
         delete theGrid[i][j];
      }
      delete [] theGrid[i];
   }
   delete [] theGrid;
}


void Grid::newFloor(string fname) {    //string
	for (int nr = 0; nr < 5; nr++)
		theCha[nr].cleanRoom();
	if (++level != 1) this->clearStuff();
	dra = 0;
   td = new Board();
   fstream f(fname.c_str());
   string s;
	int det_H = HEIGH * (level - 1);
	if (level >= 6) det_H = 0;
   while(true) {
      theGrid = new Cell**[HEIGH];
      for(int i = 0; i < det_H+HEIGH; i++) {
         getline(f,s);
         if(f.eof()) break;			
			if (i >= det_H) {
	         theGrid[i-det_H] = new Cell*[WIDTH];
   	      for(int j = 0; j < WIDTH; j++) {
   	         theGrid[i-det_H][j] = new Cell(s.at(j), td);
   	         theGrid[i-det_H][j]->setCoords(i-det_H, j);
   	      }
			}
      }
      break;
   }
	for (int x = 0; x < HEIGH; x++) {
		for (int y = 0; y < WIDTH; y++) {
			if (theGrid[x][y]->getSymbol() == '.') {
				if ((x - 1 >= 0) && (theGrid[x-1][y]->getSymbol() == '.'))
					theGrid[x][y]->addNeigh(theGrid[x-1][y]);
				if ((y - 1 >= 0) && (theGrid[x][y-1]->getSymbol() == '.'))
					theGrid[x][y]->addNeigh(theGrid[x][y-1]);
				if ((x + 1 >= 0) && (theGrid[x+1][y]->getSymbol() == '.'))
					theGrid[x][y]->addNeigh(theGrid[x+1][y]);
				if ((y + 1 >= 0) && (theGrid[x][y+1]->getSymbol() == '.'))
					theGrid[x][y]->addNeigh(theGrid[x][y+1]);
			}
		}
	}
	int numRoom = 0;
	for (int x = 0; x < HEIGH; x++) {
		for (int y = 0; y < WIDTH; y++) {
			if ((theGrid[x][y]->getSymbol() == '.') and
				 (theGrid[x][y]->unSet())) {
				theGrid[x][y]->arrRoom(theCha[numRoom]);
				numRoom++;
			}
		}
	}
}

	
void Grid::newArrange(string fname) {
	if (++level != 1) this->clearStuff();
	dra = 0;
   td = new Board();
   fstream f(fname.c_str());
   string s;
	vector<Item *> dragonH;
	vector<Dragon *> dragon;
	int potNum = 0;
	int treaNum = 0;
	int eneNum = 0;
	int det_H = HEIGH * (level - 1);
	if (level >= 6) det_H = 0;
   while(true) {
      theGrid = new Cell**[HEIGH];
      for(int i = 0; i < det_H+HEIGH; i++) {
         getline(f,s);
         if(f.eof()) break;			
			if (i >= det_H) {
	         theGrid[i-det_H] = new Cell*[WIDTH];
   	      for(int j = 0; j < WIDTH; j++) {
					switch (s.at(j)) {
						case '0':	theGrid[i-det_H][j] = new Item("RH");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myPo[potNum] = static_cast<Item*>(theGrid[i-det_H][j]); 
										potNum++;	break;
						case '1':	theGrid[i-det_H][j] = new Item("BA");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myPo[potNum] = static_cast<Item*>(theGrid[i-det_H][j]); ; 
										potNum++;	break;
						case '2':	theGrid[i-det_H][j] = new Item("BD");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myPo[potNum] = static_cast<Item*>(theGrid[i-det_H][j]); ; 
										potNum++;	break;
						case '3':	theGrid[i-det_H][j] = new Item("PH");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myPo[potNum] = static_cast<Item*>(theGrid[i-det_H][j]); ; 
										potNum++;	break;
						case '4':	theGrid[i-det_H][j] = new Item("WA");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myPo[potNum] = static_cast<Item*>(theGrid[i-det_H][j]); ; 
										potNum++;	break;
						case '5':	theGrid[i-det_H][j] = new Item("WD");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myPo[potNum] = static_cast<Item*>(theGrid[i-det_H][j]); ; 
										potNum++;	break;
						case '6':	theGrid[i-det_H][j] = new Item("small");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myTr[treaNum] = static_cast<Item*>(theGrid[i-det_H][j]); 
										treaNum++;	break;
						case '7':	theGrid[i-det_H][j] = new Item("normal");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myTr[treaNum] = static_cast<Item*>(theGrid[i-det_H][j]); 
										treaNum++;	break;
						case '8':	theGrid[i-det_H][j] = new Item("merchant hoard");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myTr[treaNum] = static_cast<Item*>(theGrid[i-det_H][j]); 
										treaNum++;	break;
						case '9':	theGrid[i-det_H][j] = new Item("dragon hoard");
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myTr[treaNum] = static_cast<Item*>(theGrid[i-det_H][j]); 
										treaNum++;
										dragonH.push_back(static_cast<Item *>(theGrid[i-det_H][j])); 
										break;
						case 'O':	theGrid[i-det_H][j] = new Orcs();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'F':	theGrid[i-det_H][j] = new Dwarf();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'L':	theGrid[i-det_H][j] = new Halfling();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'H':	theGrid[i-det_H][j] = new Human();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'E':	theGrid[i-det_H][j] = new Elf();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'M':	theGrid[i-det_H][j] = new Merchant();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'Y':	theGrid[i-det_H][j] = new Yang();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										eneNum++;	break;
						case 'D':	theGrid[i-det_H][j] = new Dragon();
										theGrid[i-det_H][j]->setDisplay(td);
										theGrid[i-det_H][j]->setCoords(i-det_H, j);
										theGrid[i-det_H][j]->setPrev('.'); 
										myEn[eneNum] = static_cast<Enemy*>(theGrid[i-det_H][j]); 
										dra++; 
										eneNum++;
										dragon.push_back(static_cast<Dragon *>(theGrid[i-det_H][j])); 
										break;
						default:	theGrid[i-det_H][j] = new Cell(s.at(j), td);
   	         				theGrid[i-det_H][j]->setCoords(i-det_H, j);
					}
   	      }
			}
      }
		for (unsigned int x = 0; x < dragonH.size(); x++) {
			for (unsigned int y = 0; y < dragon.size(); y++) {
				if (dragon[y]->hasEgg()) continue;
				for (int dr = -1; dr <= 1; dr++) {
      			for (int dc = -1; dc <= 1; dc++) {
         			if (dr == 0 && dc == 0) continue;
         			if ((dragonH[x]->getR()+dr == dragon[y]->getR()) and
							 (dragonH[x]->getC()+dc == dragon[y]->getC())) {
								dragon[y]->setH(dragonH[x]);
								break;
						}
					}
				}
			}
		}
      break;
   }
}


void Grid::restart() {
	level = 0;
	this->clearStuff();
	delete thePC;
}


//ifRange: if in enemy range
bool Grid::ifRange(int &r, int &c) {
   for (int i = r - 1; i <= r + 1; i++) {
      for (int j = c - 1; j <= c + 1; j++) {
         //if ((i == r) && (j == c)) continue;
         if (theGrid[i][j]->getSymbol() == '@') {
            r = i;
            c = j;
            return true;
         }
      }
   }
   return false;
}



//emAction
void Grid::emAction() {
   int newr, newc;
   int r, c;
   int oldHp, newHp;
   int aim_r, aim_c; // attacking aiming coords
   for (int i = 0; i < 20; i++) {
    if (myEn[i] == NULL) continue;
    else if (myEn[i]->dead()) { delete myEn[i]; myEn[i] = NULL; continue; }
      aim_r = myEn[i]->getR();
      aim_c = myEn[i]->getC();
      if(this->ifRange(aim_r, aim_c)) {
         if (((!myEn[i]->ifHost()) && (!thePC->ifNeu())) ||
              (myEn[i]->ifHost())) {
              oldHp = thePC->getHp();
              thePC->attack(*myEn[i]);
              newHp = thePC->getHp();
              stringstream sout;
              string temp;   // used to add description
              sout << myEn[i]->getSymbol() << " deals ";
              sout << oldHp - newHp << " damage to PC. ";
              getline(sout, temp);
              desc = desc + temp;
         }
      }
      else {
         r = myEn[i]->getR();
         c = myEn[i]->getC();
         newr = r;
         newc = c;
         myEn[i]->autoMove(newr, newc);
         if (theGrid[newr][newc]->getSymbol() == '.') {
            delete theGrid[newr][newc];
            theGrid[r][c] = new Cell('.', td);
            theGrid[r][c]->setCoords(r, c);
            theGrid[newr][newc] = myEn[i];
            myEn[i]->setCoords(newr, newc);
         }
     }
   }
}

bool Grid::nearPotion() {
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) continue;
         if (theGrid[thePC->getR()+i][thePC->getC()+j]->getSymbol() == 'P') {
            desc = desc + " and sees an unknown potion. ";
            return true;
          }
      }
   }
   desc = desc + ". ";
   return false;
}

void Grid::eatPotion(string m) {
   int newr, newc;
   int r = thePC->getR();
   int c = thePC->getC();
   if(m == "no") {
      newr = r - 1;
      newc = c;
   }
   if(m == "so") {
      newr = r + 1;
      newc = c;
   }
   if(m == "ea") {
      newr = r;
      newc = c + 1;
   }
   if(m == "we") {
      newr = r;
      newc = c - 1;
   }
   if(m == "ne") {
      newr = r - 1;
      newc = c + 1;
   }
   if(m == "nw") {
      newr = r - 1;
      newc = c - 1;
   }
   if(m == "se") {
      newr = r + 1;
      newc = c + 1;
   }
   if(m == "sw") {
      newr = r + 1;
      newc = c - 1;
   }
   if (theGrid[newr][newc]->getSymbol() == 'P') {
         Item *temp = static_cast<Item*>(theGrid[newr][newc]);
         temp->useOn(*thePC);
            theGrid[newr][newc] = new Cell('.', td);
            theGrid[newr][newc]->setCoords(newr,newc);
         desc = "PC uses " + temp->getName() + ". ";
         delete temp;
   }
   else { desc = "NOTHING CAN BE USED IN THAT DIRECTION!! "; }
       
}


//pcAttack
void Grid::pcAttack(string m) {
   int newr, newc, oldHp, newHp;
   stringstream sout;
   int r = thePC->getR();
   int c = thePC->getC();
   if(m == "no") {
      newr = r - 1;
      newc = c;
   }
   if(m == "so") {
      newr = r + 1;
      newc = c;
   }
   if(m == "ea") {
      newr = r;
      newc = c + 1;
   }
   if(m == "we") {
      newr = r;
      newc = c - 1;
   }
   if(m == "ne") {
      newr = r - 1;
      newc = c + 1;
   }
   if(m == "nw") {
      newr = r - 1;
      newc = c - 1;
   }
   if(m == "se") {
      newr = r + 1;
      newc = c + 1;
   }
   if(m == "sw") {
      newr = r + 1;
      newc = c - 1;
   }
   if	(dynamic_cast<Enemy *>(theGrid[newr][newc]) != NULL) {
         Enemy *theEn = static_cast<Enemy*>(theGrid[newr][newc]);
         oldHp = theEn->getHp();
         theEn->attack(*thePC);
         newHp = theEn->getHp();
         if(theEn->dead()) {         	//check if the enemy is dead
            newHp = theEn->getHp();   	// reassign
            if(theEn->getSymbol() == 'H') {
               thePC->addGold(4);
	       		theGrid[newr][newc] = new Cell('.', td);     //death delete determine in emAction()
               theGrid[newr][newc]->setCoords(newr,newc);
            }
				else if(theEn->getSymbol() == 'Y') {
               thePC->addGold(50);
	       		theGrid[newr][newc] = new Cell('.', td);     //death delete determine in emAction()
               theGrid[newr][newc]->setCoords(newr,newc);
            }
            else if (theEn->getSymbol() == 'D') {
               static_cast<Dragon*>(theEn)->setTaken();
	       		theGrid[newr][newc] = new Cell('.', td);
               theGrid[newr][newc]->setCoords(newr,newc);
            }
	    		else if (theEn->getSymbol() == 'M') {
	       		theGrid[newr][newc] = new Item("merchant hoard");
	       		theGrid[newr][newc]->setDisplay(td);
	       		theGrid[newr][newc]->setCoords(newr, newc);
	    		}
	    		else {
	       		int g = rand() % 2 + 1;
	       		thePC->addGold(g);
	       		theGrid[newr][newc] = new Cell('.', td);
               theGrid[newr][newc]->setCoords(newr,newc);
	    		}
         }
         sout << "PC deals ";
         sout << oldHp - newHp << " damage ";
         sout << "to " << theEn->getSymbol() << " (";
         sout << newHp << " HP). ";
         getline(sout, desc);
   }
   else { desc = "NO ENEMY IN THAT DIRECTION!! "; }
       
}
 
//pcMove
void Grid::pcMove(string m) {
   int newr, newc;
   int r = thePC->getR();
   int c = thePC->getC();
   desc = "PC moves ";
   if(m == "no") {
      newr = r - 1;
      newc = c;
      desc = desc + "North"; // consider see a potion
   }
   if(m == "so") {
      newr = r + 1;
      newc = c;
      desc = desc + "South";
   }
   if(m == "ea") {
      newr = r;
      newc = c + 1;
      desc = desc + "East";
   }
   if(m == "we") {
      newr = r;
      newc = c - 1;
      desc = desc + "West";
   }
   if(m == "ne") {
      newr = r - 1;
      newc = c + 1;
      desc = desc + "North-East";
   }
   if(m == "nw") {
      newr = r - 1;
      newc = c - 1;
      desc = desc + "North-West";
   }
   if(m == "se") {
      newr = r + 1;  
      newc = c + 1;
      desc = desc + "South-East";
   }
   if(m == "sw") {
      newr = r + 1;
      newc = c - 1;
      desc = desc + "South-West";
   }
   if((theGrid[newr][newc]->getSymbol() == '.') or
       (theGrid[newr][newc]->getSymbol() == '+') or
       (theGrid[newr][newc]->getSymbol() == '#')) {
       char temp = theGrid[newr][newc]->getSymbol();
       delete theGrid[newr][newc];
       theGrid[r][c] = new Cell(thePC->getPrev(), td);
       theGrid[r][c]->setCoords(r, c);
       theGrid[newr][newc] = thePC;
       thePC->setCoords(newr,newc);
       thePC->setPrev(temp);
   	 nearPotion();
		 game->emAction();
   }
   else if ((theGrid[newr][newc]->getSymbol() == 'G') and
            (static_cast<Item*>(theGrid[newr][newc])->getTaken())) {
      Item *temp = static_cast<Item*>(theGrid[newr][newc]);
      temp->useOn(*thePC);
      desc = desc + " and pick up a " + temp->getName();
      delete theGrid[newr][newc];
      theGrid[r][c] = new Cell(thePC->getPrev(), td);
      theGrid[r][c]->setCoords(r, c);
      theGrid[newr][newc] = thePC;
      thePC->setCoords(newr,newc);
      thePC->setPrev('.');
   	nearPotion();
		game->emAction();
   }
   else if ((theGrid[newr][newc]->getSymbol() == 'G') and
            !(static_cast<Item*>(theGrid[newr][newc])->getTaken())) {
      desc = "This item cannot be taken yet!";
   }
   else if (theGrid[newr][newc]->getSymbol() == '\\') {
      thePC->reset();
		for (int i = 0; i < 20; i++) {
    		if (myEn[i] == NULL) continue;
    		else if (myEn[i]->dead()) {
				delete myEn[i]; myEn[i] = NULL; continue;
			}
		}
		// clean enemy leaks before get upstairs in case
		if (this->file == "default") {
      	this->newFloor();
      	this->start();
		}
		else {
			this->newArrange(file);
			this->startArg();
		}
   }
   else {
      desc = "INVALID, CANNOT MOVE! ";
      return;
   }
}



void Grid::addPlayer(char pl) {
   switch (pl) {
      case 'v': thePC = new Vampire();break;
      case 's': thePC = new Shade();break;
      case 'g': thePC = new Goblin();break;
      case 'd': thePC = new Drow();break;
      case 't': thePC = new Troll();break;
      case 'x': thePC = new Porco();break;
   }
}

void Grid::genePotion() {
   int r = 0;
	int c = 0;
	int room, pos;   // random
   int typ;
   for(int i = 0; i < 10; i++) {
      myPo[i] = NULL;
   }
   //create potions
   for(int i = 0; i < 10; i++) {
		while (true) {
      	room = rand() % 5;
			if (theCha[room].isFilled()) continue;
			else {
				pos = theCha[room].giveCoords(r, c);
				break;
			}
      }
      typ = rand() % 6;
      if (typ == 0) {
         myPo[i] = new Item("RH");
         myPo[i]->setDisplay(td);
         myPo[i]->setPrev('.');
         myPo[i]->setCoords(r, c);
			theCha[room].changePos(pos, myPo[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myPo[i];   
      }
      if (typ == 1) {
         myPo[i] = new Item("PH");
         myPo[i]->setDisplay(td);
         myPo[i]->setPrev('.');
         myPo[i]->setCoords(r, c);
			theCha[room].changePos(pos, myPo[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myPo[i];   
      }
      if (typ == 2) {
         myPo[i] = new Item("BA");
         myPo[i]->setDisplay(td);
         myPo[i]->setPrev('.');
         myPo[i]->setCoords(r, c);
			theCha[room].changePos(pos, myPo[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myPo[i];   
      }
      if (typ == 3) {
         myPo[i] = new Item("WA");
         myPo[i]->setDisplay(td);
         myPo[i]->setPrev('.');
         myPo[i]->setCoords(r, c);
			theCha[room].changePos(pos, myPo[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myPo[i];   
      }
      if (typ == 4) {
         myPo[i] = new Item("BD");
         myPo[i]->setDisplay(td);
         myPo[i]->setPrev('.');
         myPo[i]->setCoords(r, c);
			theCha[room].changePos(pos, myPo[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myPo[i];   
      }
      if (typ == 5) {
         myPo[i] = new Item("WD");
         myPo[i]->setDisplay(td);
         myPo[i]->setPrev('.');
         myPo[i]->setCoords(r, c);
			theCha[room].changePos(pos, myPo[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myPo[i];   
      }
   }
}


void Grid::geneTrea() {
   int r = 0;
	int c = 0;
	int room, pos;   // random
   int typ;
   for(int i = 0; i < 10; i++) {
      myTr[i] = NULL;
   }
   //create treasures
   for(int i = 0; i < 10; i++) {
		while (true) {
      	room = rand() % 5;
			if (theCha[room].isFilled()) continue;
			else {
				pos = theCha[room].giveCoords(r, c);
				break;
			}
      }
      typ = rand() % 10;
      if (typ <= 5) {
         myTr[i] = new Item("small");
         myTr[i]->setDisplay(td);
         myTr[i]->setPrev('.');
         myTr[i]->setCoords(r, c);
			theCha[room].changePos(pos, myTr[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myTr[i];   
      }
      if ((typ <= 8) and (typ > 5)) {
         myTr[i] = new Item("normal");
         myTr[i]->setDisplay(td);
         myTr[i]->setPrev('.');
         myTr[i]->setCoords(r, c);
			theCha[room].changePos(pos, myTr[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myTr[i];   
      }
      if (typ == 9) {
         myTr[i] = new Item("dragon hoard");
         myTr[i]->setDisplay(td);
         myTr[i]->setPrev('.');
         myTr[i]->setCoords(r, c);
			theCha[room].changePos(pos, myTr[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myTr[i]; 
         // dragon appear=======
         myEn[dra] = new Dragon;
         myEn[dra]->setDisplay(td);
         static_cast<Dragon*>(myEn[dra])->setH(myTr[i]);
         myEn[dra]->setPrev('.');
         int d_r, d_c;
         while (true) {
            d_r = rand() % 3 - 1 + r;
            d_c = rand() % 3 - 1 + c;   
            if (theGrid[d_r][d_c]->getSymbol() == '.') break;
         }
         myEn[dra]->setCoords(d_r, d_c);
         delete theGrid[d_r][d_c];
         theGrid[d_r][d_c] = myEn[dra];
         dra++;
         //=====================  
      }
   }
}


void Grid::geneEnemy() {
   int r = 0;
	int c = 0;
	int room, pos;   // random
   int typ;
   for(int i = dra; i < 20; i++) {
      myEn[i] = NULL;
   }
	if (level == 5) {
		while (true) {
      	room = rand() % 5;
			if (theCha[room].isFilled()) continue;
			else {
				pos = theCha[room].giveCoords(r, c);
				break;
			}
      }
		myEn[dra] = new Yang;			// BOSS YANG generated
      myEn[dra]->setDisplay(td);
      myEn[dra]->setPrev('.');
      myEn[dra]->setCoords(r, c);
		theCha[room].changePos(pos, myEn[dra]);
      delete theGrid[r][c];
      theGrid[r][c] = myEn[dra]; 
		dra++;
	} 
   for(int i = dra; i < 20; i++) {
		while (true) {
      	room = rand() % 5;
			if (theCha[room].isFilled()) continue;
			else {
				pos = theCha[room].giveCoords(r, c);
				break;
			}
      }
      typ = rand() % 18;
      if((typ == 0) || (typ == 1)) {
         myEn[i] = new Merchant;
         myEn[i]->setDisplay(td);
         myEn[i]->setPrev('.');
         myEn[i]->setCoords(r, c);
			theCha[room].changePos(pos, myEn[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myEn[i];   
      }
      if((typ == 2) || (typ == 3)) {
         myEn[i] = new Orcs;
         myEn[i]->setDisplay(td);
         myEn[i]->setPrev('.');
         myEn[i]->setCoords(r, c);
			theCha[room].changePos(pos, myEn[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myEn[i];   
      }
      if((typ == 4) || (typ == 5)) {
         myEn[i] = new Elf;
         myEn[i]->setDisplay(td);
         myEn[i]->setPrev('.');
         myEn[i]->setCoords(r, c);
			theCha[room].changePos(pos, myEn[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myEn[i];   
      }
      if((typ >= 6) && (typ <= 10)) {
         myEn[i] = new Halfling;
         myEn[i]->setDisplay(td);
         myEn[i]->setPrev('.');
         myEn[i]->setCoords(r, c);
			theCha[room].changePos(pos, myEn[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myEn[i];   
      }
      if((typ >= 11) && (typ <= 13)) {
         myEn[i] = new Dwarf;
         myEn[i]->setDisplay(td);
         myEn[i]->setPrev('.');
         myEn[i]->setCoords(r, c);
			theCha[room].changePos(pos, myEn[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myEn[i];   
      }
      if((typ >= 14) && (typ <= 17)) {
         myEn[i] = new Human;
         myEn[i]->setDisplay(td);
         myEn[i]->setPrev('.');
         myEn[i]->setCoords(r, c);
			theCha[room].changePos(pos, myEn[i]);
         delete theGrid[r][c];
         theGrid[r][c] = myEn[i];   
      }
   }
}



void Grid::start() {
   int r = 0; 
	int c = 0;
	int room, pos;
   desc = "Player character has spawned.";
	if (level == 5) desc += "BOSS Yang has been spawned!";
   while (true) {
      	room = rand() % 5;
			if (theCha[room].isFilled()) continue;
			else {
				pos = theCha[room].giveCoords(r, c);
				break;
			}
   } 
   thePC->setDisplay(td);
   thePC->setCoords(r, c);
	theCha[room].changePos(pos, thePC);
   delete theGrid[r][c];
   theGrid[r][c] = thePC;
   thePC->setPrev('.');
   //============ Create Stair ====================
   while (true) {
      	room = rand() % 5;
			if (theCha[room].isFilled()) continue;
			else {
				pos = theCha[room].giveCoords(r, c);
				break;
			}
   }
   delete theGrid[r][c];
   theGrid[r][c] = new Cell('\\', td);
	theCha[room].changePos(pos, theGrid[r][c]);
   theGrid[r][c]->setCoords(r, c);
   //==============================================
   
   //============= Create Enemy P, G===================
   this->genePotion();
   this->geneTrea();
   this->geneEnemy();
   //==================================================
}


void Grid::startArg() {
	int r = 0; 
	int c = 0;
   desc = "Player character has spawned.";
	if (level == 5) desc += "BOSS Yang has been spawned!";
   while (true) {
      r = rand() % HEIGH;
      c = rand() % WIDTH;
      if (theGrid[r][c]->getSymbol() == '.') break;
   }
   thePC->setDisplay(td);
   thePC->setCoords(r, c);
   delete theGrid[r][c];
   theGrid[r][c] = thePC;
   thePC->setPrev('.');
}


//++++++++++++ operator<< +++++++++++++
// *Purpose: overwrite the << inorder to read the Grid
// *return:  ostream
//===================================== 
ostream &operator<<(ostream &out, const Grid &g) {
   out << *(g.td) << endl;
   out << "Race: ";
   switch (g.thePC->getRole()) {
      case 'v': out << "Vampire ";break;
      case 'g': out << "Goblin ";break;
      case 'd': out << "Drow ";break;
      case 't': out << "Troll ";break;
      case 's': out << "Shade ";break;
		case 'x': out << "KingPorco! ";break;
   }
   out << "Gold: " << g.thePC->getGold(); 
   out << "                                              Floor " <<  g.level << endl;
   out << "HP: " << g.thePC->getHp() << endl;     // getHP
   out << "Atk: " << g.thePC->getAt() << endl;    // getAt
   out << "Def: " << g.thePC->getDf() << endl;    // getDf
   out << "Action: " << g.desc;            // LATER
   //g.desc = " "; 
 return out;
}
//-------------------------------------


ostream &operator<<(ostream &out, const Grid *g) {
//	clear();	// this will be modified
   out << g->td;
	string first = "Race: ";
   switch (g->thePC->getRole()) {
      case 'v': first = first + "Vampire ";break;
      case 'g': first = first + "Goblin ";break;
      case 'd': first = first + "Drow ";break;
      case 't': first = first + "Troll ";break;
      case 's': first = first + "Shade ";break;
		case 'x': first = first + "KingPorco! ";break;
   }
	first = first + "Gold: ";
	ostringstream convG;
	convG << g->thePC->getGold();
	first = first + convG.str();
	ostringstream convF;
	convF << g->level;
   string floor = "Floor: " + convF.str();
	ostringstream convH;
	convH << "HP: " << g->thePC->getHp();
	string heal = convH.str();
	ostringstream convA;
	convA << "Atk: " << g->thePC->getAt();
	string attack = convA.str();
	ostringstream convD;
	convD << "Def: " << g->thePC->getDf() << endl;
	string defen = convD.str();
	ostringstream convC;
	convC << "Action: " << g->desc;
	string action = convC.str();

	clrtoeol();
	mvaddstr(HEIGH, 0, first.c_str());
   mvaddstr(HEIGH, WIDTH-10, floor.c_str());
	clrtoeol();
	mvaddstr(HEIGH+1, 0, heal.c_str());
	clrtoeol();
	mvaddstr(HEIGH+2, 0, attack.c_str());
	clrtoeol();
	mvaddstr(HEIGH+3, 0, defen.c_str());
	clrtoeol();
	mvaddstr(HEIGH+4, 0, action.c_str());
	refresh();
	return out;
}
