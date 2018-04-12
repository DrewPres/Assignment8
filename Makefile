# File: Makefile
# Date: 04/12/18
# Author: Drew Presson
#   -> Adapeted from Makefile by Joshua Gearin
# Description: Binary Search Tree

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Memory Mangagment Flags
MEMFLAGS=-fsanitize=address -fno-omit-frame-pointer

# Target
TARGET=SearchTree

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o Node.o BinarySearchTree.o
	$(CC) main.o Node.o BinarySearchTree.o -o $(TARGET) $(MEMFLAGS) 

main.o: main.cpp Node.h
	$(CC) $(CFLAGS) $(MEMFLAGS) main.cpp 

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) $(MEMFLAGS) Node.cpp

BinarySearchTree.o : BinarySearchTree.cpp BinarySearchTree.h
	$(CC) $(CFLAGS) $(MEMFLAGS) BinarySearchTree.cpp

clean:
rm -f *.o *~ $(TARGET)
