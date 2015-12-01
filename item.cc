#include "item.h"
#include "player.h"
using namespace std;

Item::Item(string desc):isTaken(true) {
   this->name = desc;
   if (desc == "RH") {
      value = 10;      // These two special
      s = 'P';
   }
   else if (desc == "BA") {
      value = 5;
      s = 'P';
   }
   else if (desc == "BD") {
      value = 5;
      s = 'P';
   }
   else if (desc == "PH") {
      value = -10;       // These two special
      s = 'P';
   }
   else if (desc == "WA") {
      value = -5;
      s = 'P';
   }
   else if (desc == "WD") {
      value = -5;
      s = 'P';
   }
   else if (desc == "small") {
      value = 1;
      s = 'G';
   }
   else if (desc == "normal") {
      value = 2;
      s = 'G';
   }
   else if (desc == "merchant hoard") {
      value = 4;
      s = 'G';
   }
   else if (desc == "dragon hoard") {
      value = 6;
      s = 'G';
      isTaken = false;
   }
}

string Item::getName() {
   return name;
}

void Item::setTaken() {
   this->isTaken = true;
}

bool Item::getTaken() {
   return isTaken;
}


      
void Item::useOn(Player &pl) {
   switch (this->s) {
      case 'G':
         pl.addGold(value); break;
      case 'P':
         if ((name == "RH") or (name == "PH")) {
            pl.addHp(value);
         }
         else if ((name == "BA") or (name == "WA")) {
            pl.addAt(value);
         }
         else if ((name == "BD") or (name == "WD")) {
            pl.addDf(value);
         } break;
   }
}


