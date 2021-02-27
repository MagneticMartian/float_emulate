.RECIPEPREFIX = > 
HOME = .
CC = gcc
OBJ = o
CSRC = c
HEAD = h
BINLOC = $(HOME)/bin/
INCLOC = $(HOME)/include/
LIBLOC = $(HOME)/lib/
SRCLOC = $(HOME)/src/

all: read_reg.$(OBJ) get_reg.$(OBJ) main

read_reg.$(OBJ): $(SRCLOC)read_reg.$(CSRC) $(INCLOC)r_reg.$(HEAD)
> $(CC) -c $(SRCLOC)read_reg.$(CSRC) -lm
> mv read_reg.$(OBJ) $(LIBLOC)

get_reg.$(OBJ): $(SRCLOC)get_reg.$(CSRC) $(INCLOC)r_reg.$(HEAD)
> $(CC) -c $(SRCLOC)get_reg.$(CSRC)
> mv get_reg.$(OBJ) $(LIBLOC)

main: $(SRCLOC)main.$(CSRC) $(LIBLOC)get_reg.$(OBJ) $(LIBLOC)read_reg.$(OBJ) $(INCLOC)r_reg.$(HEAD)
> $(CC) -o main $(SRCLOC)main.$(CSRC) $(LIBLOC)get_reg.$(OBJ) $(LIBLOC)read_reg.$(OBJ) -lm
> mv main $(BINLOC)
