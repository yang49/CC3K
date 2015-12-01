CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = welcome.o item.o enemy.o player.o vampire.o shade.o drow.o goblin.o troll.o human.o elf.o halfling.o orcs.o merchant.o dwarf.o dragon.o cell.o grid.o board.o character.o testmain.o porco.o room.o yang.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lcurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
