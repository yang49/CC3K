//include for other header files
#include <string>
#include <iostream>

using namespace std;

/* there should be a method which determine if the player reach the stair or
 * not. If the player reaches a stair, the the numFloor increase by one(this
 * is optional). Once the player reaches a stair, the "dungeon" and "enemies"
 * should be destoried. And at the same time, a new dungeon is created and so
 * are the "enemies". The positions of the player and "enemy" should be generated
 * automaticly
 *
 *
 */

int main(void) {
   int numFloor = 0;
   string cmd;    //string which stores the command
   Player *thePlayer = NULL;
   bool restart = false;
   string dirc;
   //alloc the "Grid" on the stack, once the player reaches the stair
   //all enemy get "freed". The "Grid" remains unchanged
   while(cin >> cmd) {
      if((thePlayer != NULL) && (thePlayer->dead)) break;
      if(cmd == "s") {
         //create the player which is a "shade"
         /*
         if(restart == true) {
            delete thePlayer;
            restart = false;
         }
         */
         //thePlayer = ...
      }
      if(cmd == "d") {
         //create the player which is a "drow"
         //thePlayer = ...
      }
      if(cmd == "v") {
         //create the player which is a "vampire"
         //thePlayer = ...
      }
      if(cmd == "g") {
         //create the player which is a "goblin"
         //thePlayer = ...
      }
      if(cmd == "t") {
         //create the player which is a troll
         //thePlayer = ...
      }
      if(cmd == "r") {
         restart = true;
      }
      if(cmd == "u") {
         cin >> dirc;   //reads the direction for moving
         //player.move(dirc)
      }
      if(cmd == "a") {
         cin >> dirc;   //reads the direction for attacking
         //player.attack(dirc)
      }
      
   }//ends the while loop
   delete thePlayer;
}
