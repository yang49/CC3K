#ifndef __WELCOME_H__
#define __WELCOME_H__

#include <fstream>
#include <iostream>
#include <string>
#include <ncurses.h>

class Welcome {
	public:
		static void welcome(std::string);
		static void welcome_win(std::string);
		static void end(std::string file, int height);
};
#endif
