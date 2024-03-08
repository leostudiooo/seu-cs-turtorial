# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -g -std=c++11
# Source files
SOURCES = **.cpp
# Object files
OBJECTS = $(SOURCES:.cpp=.o)
# Executable
EXECUTABLE = money
# Build
all: 
	$(CC) $(CFLAGS) -c $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)