#include "welcome.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void Welcome::welcome(string file){
	fstream wel(file.c_str());
   string s;
   while(true) {
      for(int i = 0; i < 30; i++) {
         getline(wel,s);
         if(wel.eof()) break;
         for(int j = 0; j < 79; j++) {
            cout << s.at(j);
         }
	 cout << endl;
      }
      break;
   }
}

void Welcome::welcome_win(string file){
	fstream wel(file.c_str());
   string s;
      for(int i = 0; i < 30; i++) {
         getline(wel,s);
         if(wel.eof()) break;
         for(int j = 0; j < 79; j++) {
            mvaddch(i, j, s.at(j));
         }
      }
	refresh();
}

void Welcome::end(string file, int height){
	fstream wel(file.c_str());
   string s;
   while(true) {
      for(int i = 0; i < height; i++) {
         getline(wel,s);
         if(wel.eof()) break;
         for(int j = 0; j < 79; j++) {
            cout << s.at(j);
         }
	 cout << endl;
      }
      break;
   }
}
