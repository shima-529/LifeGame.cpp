CC         = c++
CFLAGS     = -std=c++11 -g -O2
PROG_NAME  = lifegame
OBJS       = Cell.o init.o cellRW.o lifePrint.o sigInterrupt.o main.o
OBJDIR     = ./obj
OBJS_FPATH = $(addprefix $(OBJDIR)/,$(OBJS))
INCLUDE    = -I ./h

all: $(OBJS_FPATH)
	$(CC) $^ -o $(PROG_NAME)
	@cat README

$(OBJDIR)/%.o: %.cpp
	if [ ! -d "$(OBJDIR)" ]; then \
		mkdir "$(OBJDIR)"; \
		fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: love clean allclean
love:
	@echo "Erotic!"

clean:
	$(RM) $(OBJS_FPATH)

allclean:
	$(RM) $(OBJS_FPATH) $(PROG_NAME)
