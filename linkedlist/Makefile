
# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Werror -Wfatal-errors -g

# cleaning up
DEL = rm

all: main

linkedlist.o: linkedlist.cpp
	$(CC) -c $(CFLAGS) $< -o $@

main: main.cpp linkedlist.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(DEL) *.out *.o