CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2

INC = main.h 
SRC = main.c graphics.c deplacement.c
OBJ = $(SRC:%.c=%.o)

PROG = ../bin/test

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

test: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html