
# Compiler 
CC = g++

# Compiler flags 
CFLAGS = -Wall -Werror -Wfatal-errors -g


# cleaning up
DEL = rm


all: main


binarytree.o: binarytree.cpp
	$(CC) -c $(CFLAGS) $< -o $@


main: main.cpp binarytree.o
	$(CC) $(CFLAGS) $^ -o $@


clean:
	$(DEL) *.out *.o