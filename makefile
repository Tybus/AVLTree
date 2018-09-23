#Comepiler
CC = g++

#Compiler flags
CFLAGS = -Wall -g -std=c++14

# Include directory
IDIR = -Iinclude/

# SRC directory
SRCDIR = src/

#SRC targets
SRC = AVLNode AVLTree

# OBJ Directory
OBJ = obj/
# TEST directory
TESTDIR = test/

MAIN = ./

TEST = main_unittest
all : $(SRC) $(TEST) $(MAIN) unittest main

make_run:
	./main.out
main:
	$(CC) $(CFLAGS) $(IDIR) -o main.out $(OBJ)AVLTree.o $(OBJ)AVLNode.o $(OBJ)main.o	
run_unittest: unittest
	./unit_test.out

unittest: $(SRC) $(TEST)
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(IDIR) -o unnit_test.out $(OBJ)AVLNode.o $(OBJ)AVLTree.o $(OBJ)$(TEST).o


$(MAIN): $(SRC)
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(IDIR) -c main.cpp -o $(OBJ)main.o	

$(TEST): $(SRC)
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$@.cpp -o $(OBJ)$@.o

$(SRC):
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(IDIR) -c $(SRCDIR)$@.cpp -o $(OBJ)$@.o

clean:
	rm $(OBJ)/* *.out
