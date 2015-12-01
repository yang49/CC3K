#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "board.h"

class Room;

class Cell {
   protected:
   char s;
   char prev;    
   int r, c;  
   Board * bd; 
	int numNeigh;
	Cell *neigh[4];
	bool alSet;					// whether this Cell has been set in a room
   bool motion;
   void notifyDisplay();

   public:
   Cell();                                   // Default constructor
   virtual ~Cell() {}
   Cell(char, Board *);
	void addNeigh(Cell *);
	bool unSet();										// Whether the cell is set in a room
	void arrRoom(Room &);
   char getSymbol();                          //getter for private state
   int getR();
   int getC();
   char getPrev();
   void setPrev(char);
   void setCoords(const int r, const int c);				//setter for private co-ordinates of cell
   void setDisplay(Board * t);         //setter for TextDisplay
};
#endif
