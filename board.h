#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <ncurses.h>

extern int WIDTH;
extern int HEIGH;

class Board {
  char **theDisplay;

 public:
  Board();
  ~Board();

  void notify(int r, int c, char ch);

  friend std::ostream &operator<<(std::ostream &out, const Board &td);
  friend std::ostream &operator<<(std::ostream &out, const Board *td);
};

#endif
