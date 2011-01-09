
CC=gcc
CFLAGS=-I/usr/include/lua5.1
LIBS=-llua5.1
OBJ=lua.o

PROG=lua

lua: $(OBJ)
	$(CC) -o $(PROG) $^ $(CLFAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(PROG) $(OBJ)
