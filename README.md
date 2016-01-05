ChamberCrawler3000 (CC3K)

The Game of ChamberCrawler3000 is  a simplified rogue-like (a genre of video game based upon the game
Rogue1-http://en.wikipedia.org/wiki/Rogue_(video_game)). 

A game of CC3k, consists of a board 79 columns wide and 30 rows high (5 rows are reserved for displaying
information). Game play is as follows: The player character moves through a dungeon and slays enemies and
collects treasure until reaching the end of the dungeon (where the end of the dungeon is the 10th floor). A
dungeon consists of different floors which consist of chambers connected with passages. In our simplification,
each floor will always consist of the same 5 chambers connected in the exact same way.

CC3k differs from other rogue-likes in a significant way: it is does not update the terminal/window in
real-time but rather redraws all elements every turn (e.g. after every command). Although, many early
rogue-likes were programmed in a similar fashion to CC3k.

However, in our enhanced version of CC3K. My partner and I used a curses6 library to make this like 
an actual game with WASD controls. By doing this, it allows the program to update the terminal in real time.
