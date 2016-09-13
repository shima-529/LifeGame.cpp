CC=c++
# CFLAGS=-Wall -g -O2
CFLAGS=-std=c++11 -g -O2
PROG_NAME=lifegame
OBJS=Cell.o init.o cellRW.o lifePrint.o main.o

all: $(OBJS)
	$(CC) $^ -o $(PROG_NAME)
	@cat README

love:
	@echo "Erotic!"

clean:
	$(RM) $(OBJS)

allclean:
	$(RM) $(OBJS) $(PROG_NAME)

main.o: main.cpp
	$(CC) -c $(CFLAGS) $^

Cell.o: Cell.cpp
	$(CC) -c $(CFLAGS) $^

init.o: init.cpp
	$(CC) -c $(CFLAGS) $^

cellRW.o: cellRW.cpp
	$(CC) -c $(CFLAGS) $^

lifePrint.o: lifePrint.cpp
	$(CC) -c $(CFLAGS) $^
