CXX=g++
CXXFLAGS=-Wall -std=c++17
# LIBFLAGS=-lm -pthread -fopenmp

SRCDIR=src
UTESTDIR=src/tests
OBJDIR=obj
BINDIR=bin


_DEPS=matrix.h piece.h tetris.h testtetris.h
DEPS=$(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ=main.o piece.o tetris.o testtetris.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(_OBJ))

_OBJ_UNITTEST=matrix_unittests.o
OBJ_UNITTEST=$(patsubst %,$(OBJDIR)/%,$(_OBJ_UNITTEST))

.PHONY: all
all: main

main: $(OBJ)
	$(CXX) -o $(BINDIR)/main.exe $^ $(CXXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) -c $< -o $@ $(CXXFLAGS) -I $(SRCDIR)

.PHONY: all_unittests
all_unittests: matrix_unittests

matrix_unittests: $(OBJ_UNITTEST)
	$(CXX) -o $(BINDIR)/matrix_unittests.exe $^ $(CXXFLAGS)

$(OBJDIR)/%.o: $(UTESTDIR)/%.cpp $(DEPS)
	$(CXX) -c $< -o $@ $(CXXFLAGS) -I $(UTESTDIR) -I $(SRCDIR)

.PHONY: clean
clean:
	del /q obj\*.o bin\*.exe

# Tests




