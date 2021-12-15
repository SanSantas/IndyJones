CC=g++
CFLAGS=-std=c++11 -Wall
LFLAGS=-std=c++11

MODS=main menu game space spaceBlank spaceTrap spaceRock spaceHole indiana item link
SRC=./src
OBJ=./obj

objects= $(addsuffix .o, $(addprefix $(OBJDIR)/, $(MODS)))
sources= $(addsuffix .cpp, $(addprefix $(SRCDIR)/, $(MODS)))

TheGame: $(objects)
	$(CC) $(LFLAGS) $(objects) -o $@

./obj/%.o: ./src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f obj/*.o TheGame
