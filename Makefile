# File: Makefile
# Date: 04/12/18
# Author: Drew Presson
#   -> Adapeted from Makefile by Joshua Gearin
# Description: Makefile for the Linked List assignment

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Memory Mangagment Flags
MEMFLAGS=-fsanitize=address -fno-omit-frame-pointer

# Target
TARGET=book_list

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o Library.o 
	$(CC) main.o Library.o -o $(TARGET) $(MEMFLAGS) 

main.o: main.cpp Library.h
	$(CC) $(CFLAGS) $(MEMFLAGS) main.cpp 

Library.o: Library.cpp Library.h Book.h
	$(CC) $(CFLAGS) $(MEMFLAGS) Library.cpp

clean:
rm -f *.o *~ $(TARGET) 
