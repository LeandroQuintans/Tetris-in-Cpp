CXX=g++
CXXFLAGS=-Wall -std=c++17

ifeq ($(OS),Windows_NT)
	LIBFLAGS:=-lSOIL -lglu32 -lopengl32 -lfreeglut -lm
else
	LIBFLAGS:=-lSOIL -lGL -lGLU -lglut -lm
endif

SRCDIR=src
UTESTDIR=src/tests
OBJDIR=obj
BINDIR=bin
LIBDIR=lib

_DEPS=matrix.h piece.h tetris.h testtetris.h opengltetris.h
DEPS=$(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ=main.o piece.o tetris.o testtetris.o opengltetris.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(_OBJ))

_OBJ_UNITTEST=matrix_unittests.o
OBJ_UNITTEST=$(patsubst %,$(OBJDIR)/%,$(_OBJ_UNITTEST))

.PHONY: all
all: main

main: $(OBJ)
	$(CXX) -o $(BINDIR)/main.out $^ $(CXXFLAGS) -L $(LIBDIR) $(LIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) -c $< -o $@ $(CXXFLAGS) -L $(LIBDIR) $(LIBFLAGS) -I $(SRCDIR)

.PHONY: all_unittests
all_unittests: matrix_unittests

matrix_unittests: $(OBJ_UNITTEST)
	$(CXX) -o $(BINDIR)/matrix_unittests.exe $^ $(CXXFLAGS) -L $(LIBDIR) $(LIBFLAGS)

$(OBJDIR)/%.o: $(UTESTDIR)/%.cpp $(DEPS)
	$(CXX) -c $< -o $@ $(CXXFLAGS) -I $(UTESTDIR) -L $(LIBDIR) $(LIBFLAGS) -I $(SRCDIR)

.PHONY: clean
clean:
	rm -f obj/* bin/*

# Tests




