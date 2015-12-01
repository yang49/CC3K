#include <iostream>
#include "board.h"
#include "cell.h"
#include "room.h"
using namespace std;

void Cell::notifyDisplay() {
   int x = this->r;
   int y = this->c;
   char symbol = this->s;
   bd->notify(x, y, symbol);
    }


Cell::Cell():bd(NULL), numNeigh(0), alSet(true), motion(false) {
	for (int i = 0; i < 4; i++)
		neigh[i] = NULL;
}


Cell::Cell(char s, Board *bd): s(s), bd(bd), numNeigh(0), alSet(false), motion(false) {
	for (int i = 0; i < 4; i++)
		neigh[i] = NULL;
}


void Cell::addNeigh(Cell *c) {
	if (numNeigh < 4) {
		neigh[numNeigh] = c;
		numNeigh++;
	}
}


bool Cell::unSet() {
	return !this->alSet;
}


void Cell::arrRoom(Room &rm) {
	if (this->alSet != true) {
		rm.addFloor(this);
		this->alSet = true;
	}
	for (int i = 0; i < numNeigh; i++){
		if (this->neigh[i]->alSet != true) {
			this->neigh[i]->arrRoom(rm);
			this->neigh[i]->alSet = true;
		}
	}
}


char Cell::getSymbol() {
	return s; 
}


int Cell::getR() {
	return this->r;
}
   
   
int Cell::getC() {
	return this->c;
}
   
   
char Cell::getPrev() {
	return this->prev;
}

   
void Cell::setPrev(char c) {
	this->prev = c;
}


void Cell::setCoords(const int r, const int c) {
	this->r = r;
	this->c = c;
	this->notifyDisplay();
}


void Cell::setDisplay(Board * t) {
	this->bd = t;
}
