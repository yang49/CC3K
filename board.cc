#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "board.h"
using namespace std;

int WIDTH = 79;
int HEIGH = 25;

Board::Board() {
  theDisplay = new char*[HEIGH];
  for (int i = 0; i < HEIGH; i++) 
   theDisplay[i] = new char[WIDTH];
  for (int x = 0; x < HEIGH; x++) { 
   for (int y = 0; y < WIDTH; y++) {
    theDisplay[x][y] = ' ';    
      } 		
    }			
 }

Board::~Board() {
   for(int i = 0; i < HEIGH; i++) {
      delete [] theDisplay[i];
   }
   delete [] theDisplay;
}

//getChar
/*
char Board::getChar(int r, int c) {
   return theDisplay[r][c];
}
*/

void Board::notify(int r, int c, char ch) {
  theDisplay[r][c] = ch;
 }

ostream &operator<<(ostream &out, const Board &td) {
   for (int x = 0; x < HEIGH; x++) {
      if (x != 0) out << endl; // condition that add newline
         for (int y = 0; y < WIDTH; y++) {
            out << td.theDisplay[x][y];
         }
      }
  return out;
 }

ostream &operator<<(ostream &out, const Board *td) {
	refresh();
	for (int i = 0; i < HEIGH; ++i){
		for (int j = 0; j < WIDTH; ++j){
			char c = td->theDisplay[i][j];
			if (c == '@')	attron(A_BOLD);
			if (c == 'G')	attron(COLOR_PAIR(1));
			if (c == 'P')  attron(COLOR_PAIR(2));
			if (c == '\\')	{
			attron(A_BOLD);
			attron(COLOR_PAIR(3));
			}
			mvaddch(i,j,c);
			refresh();
			if (c == '@')	attroff(A_BOLD);
			if (c == 'G')  attroff(COLOR_PAIR(1));
			if (c == 'P')	attroff(COLOR_PAIR(2));			
			if (c == '\\')	{
			attroff(A_BOLD);
			attroff(COLOR_PAIR(3));
			}
		}
	}
	return out;
}
