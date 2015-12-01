#ifndef __ITEM_H__
#define __ITEM_H__

#include "cell.h"
#include <string>

class Player;

class Item: public Cell {
//   protected:
      int value;
      std::string name;
      bool isTaken;
   public:
      Item(std::string);
      bool getTaken();
      std::string getName();
      void setTaken();  //
      void useOn(Player &);
      ~Item() {}
};

#endif
   
