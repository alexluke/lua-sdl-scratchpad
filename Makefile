
CC=gcc
CFLAGS=-I/usr/include/lua5.1
LIBS=-llua5.1 -lSDL -l SDL_image
OBJ=graphics.o lua.o
DEPS=graphics.h

PROG=game

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	$(CC) -o $(PROG) $^ $(CLFAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(PROG) $(OBJ)
