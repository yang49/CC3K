#include "room.h"
#include <iostream>
using namespace std;

int Room::giveCoords(int &r, int &c) {
	int randNum = rand() % rm.size();
	while (1) {
		if (rm[randNum]->getSymbol() == '.') {
			r = rm[randNum]->getR();
			c = rm[randNum]->getC();
			return randNum;
		}
		else randNum = rand() % rm.size();
	}
	return -1;
}


bool Room::isFilled() {
	for (unsigned int i = 0; i < rm.size(); i++) {
		if (rm[i]->getSymbol() == '.') return false;
		else continue;
	}
	return true;
}


void Room::changePos(const int &pos, Cell *c) {
	rm[pos] = c;
}


void Room::addFloor(Cell *c) {
//	cout << c->getSymbol() << endl;
	rm.push_back(c);
}

void Room::cleanRoom() {
	rm.clear();
}
