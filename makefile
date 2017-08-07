P=calc
OBJECTS=stack.c getch.c getop.c
CFLAGS=-g -Wall -O3
# LDLIBS=-lgsl -lgslcblas -lm
LDLIBS=
CC=c99

$(P): $(OBJECTS)
