IDIR = inc
CC = gcc
CFLAGS = -g -I. -Wall -Werror

TARGET = ConsoleCardGame

SDIR = src
ODIR = obj
LDIR = lib

LIBS =

_DEPS = main.h card.h deck.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o deck.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

SRCS = $(wildcard $(SDIR)/*.c)

$(ODIR)/%.o: $(SRCS) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(TARGET): $(OBJ)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
