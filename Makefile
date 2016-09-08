CC=c++
CFLAGS=-Wall -g -O2
PROG_NAME=lifegame
OBJS=Cell.o init.o cellRW.o main.o

all: $(OBJS)
	$(CC) $^ -o $(PROG_NAME)
	@cat README

love:
	@echo "Erotic!"

clean:
	$(RM) $(OBJS)

main.o: Cell.o init.o cellRW.o

Cell.o: Cell.cpp
	$(CC) -c $^

init.o: init.cpp
	$(CC) -c $^

cellRW.o: cellRW.cpp
	$(CC) -c $^
