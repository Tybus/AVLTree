#Compiler
CC = g++

#Compiler flags
CFLAGS = -Wall -g -std=c++11

# Include directory
IDIR = -Iinclude/

# SRC directory
SRCDIR = src/

#SRC targets
SRC = debug

# TEST directory
TESTDIR = ../test/

TEST = main

all :
	$(CC) $(CFLAGS) $(IDIR) -c $(SRCDIR)*.cpp
	$(CC) $(CFLAGS) $(IDIR) -o test.out *.o

clean:
	rm $(SRC).o $(TEST).o debug_example.out
