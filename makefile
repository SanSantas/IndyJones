
TheGame: main.o menu.o game.o space.o spaceBlank.o spaceTrap.o spaceRock.o spaceHole.o indiana.o item.o link.o
	g++ -std=c++11 main.o menu.o game.o space.o spaceBlank.o spaceTrap.o spaceRock.o spaceHole.o indiana.o item.o link.o -o IndianaJones

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

game.o: game.cpp game.hpp	
	g++ -std=c++11 -c game.cpp

space.o: space.cpp space.hpp
	g++ -std=c++11 -c space.cpp

spaceBlank.o: spaceBlank.cpp spaceBlank.hpp
	g++	-std=c++11 -c spaceBlank.cpp

spaceTrap.o: spaceTrap.cpp spaceTrap.hpp
	g++ -std=c++11 -c spaceTrap.cpp

spaceRock.o: spaceRock.cpp spaceRock.hpp
	g++ -std=c++11 -c spaceRock.cpp

spaceHole.o: spaceHole.cpp spaceHole.hpp
	g++ -std=c++11 -c spaceHole.cpp

indiana.o: indiana.cpp indiana.hpp	
	g++ -std=c++11 -c indiana.cpp

item.o: item.cpp item.hpp
	g++ -std=c++11 -c item.cpp

link.o: link.cpp link.hpp
	g++ -std=c++11 -c link.cpp

clean:
	rm *.o TheGame
