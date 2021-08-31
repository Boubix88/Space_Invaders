CXXFLAGS = -Wall
SDL_FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2

INC = main.h 
SRC = main.c world.c graphics.c deplacement.c
OBJ = $(SRC:%.c=%.o)

PROG = ../bin/test

%.o: %.c $(INC)
	gcc $(CXXLAGS) -c $<

test: $(OBJ)
	gcc $(CXXLAGS) $(OBJ) $(SDL_FLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f PROG *.o 