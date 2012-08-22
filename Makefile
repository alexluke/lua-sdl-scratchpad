
CC=gcc
CFLAGS=$(shell sdl-config --cflags) -Wall -Werror -g -DDEBUG
LIBS=-llua $(shell sdl-config --libs) -l SDL_image
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
