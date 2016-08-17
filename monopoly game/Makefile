CXX = g++
CXXFLAGS = -Wall -MMD -g -DBONUS
EXEC = bb7k
OBJECTS = main.o board.o player.o square.o textdisplay.o ownableproperty.o residence.o gym.o academicbuilding.o unownableproperty.o slc.o tuition.o needleshall.o goosenesting.o dctims.o gototims.o coopfee.o collectosap.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

