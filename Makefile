COMPILER=c++
CFLAGS=-Wall -g -O2
PROG_NAME=lifegame
OBJS=Cell.o init.o cellRW.o main.o
OBJ_DIR=./obj

all: $(OBJS)
	$(COMPILER) $^ -o $(PROG_NAME)
	@cat README

main.o: Cell.o init.o cellRW.o

Cell.o: Cell.cpp
	$(COMPILER) -c $^

init.o: init.cpp
	$(COMPILER) -c $^

cellRW.o: cellRW.cpp
	$(COMPILER) -c $^

love:
	@echo "Erotic!"

clean:
	$(RM) $(OBJS)
