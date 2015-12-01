#include "dragon.h"
#include <cstdlib>
#include "item.h"

using namespace std;

int tempr, tempc;

Dragon::Dragon():theH(NULL) {
   this->s = 'D';
   this->Hp = 150;
   this->At = 20;
   this->Df = 20;
}

Dragon::~Dragon() {}


bool Dragon::hasEgg() {
	return (theH != NULL);
}


void Dragon::setH(Item *p) {
   this->theH = p;
}


void Dragon::setTaken() {
   this->theH->setTaken();
}


void Dragon::autoMove(int &newr, int &newc) {
   tempr = 0; tempc = 0;
   tempr = r + rand() % 3 - 1;
   tempc = c + rand() % 3 - 1;
   while (1) {
   if ((tempr > theH->getR()+1) or (tempc > theH->getC()+1) or
       (tempr < theH->getR()-1) or (tempc < theH->getC()-1) or
       ((tempr == r) and (tempc == c))) {
       tempr = r + rand() % 3 - 1;
       tempc = c + rand() % 3 - 1;
   }
   else break;
   }
   newr = tempr;
   newc = tempc;
}
