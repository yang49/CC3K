#include <iostream>
#include <sstream>
#include <fstream>
#include "grid.h"
#include "board.h"
#include <cstdlib>
#include "character.h"
#include "player.h"
#include "vampire.h"
#include "cell.h"
#include "welcome.h"
#include <ncurses.h>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
 	srand(time(NULL));
	string fileName = "dungeon.txt";
	if (argc == 2) {
		stringstream sin(argv[1]);
		sin >> fileName;
	}
	else if (argc > 2) {
		cerr << "ONLY ONE ARGUMENT REQUIRED!" << endl;
		return -1;
	}
 	Welcome::welcome("welcom.txt");
	char choose;
	cin >> choose;
	if (fileName == "dungeon.txt") {
		if (choose == 'c')
			Grid::commandPlay();
		else if (choose == 'e')
			Grid::easyPlay();
	}
	else {
		if (choose == 'c')
			Grid::commandPlay(fileName);
		else if (choose == 'e')
			Grid::easyPlay(fileName);
	}
}
