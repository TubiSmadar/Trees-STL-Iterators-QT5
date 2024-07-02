# Tuvia Smadar
# gunslokij@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SFML_INCLUDE = -I/usr/include/SFML

OBJS = main.o Complex.o NodeItem.o

all: tree test

tree: $(OBJS) Tree.hpp
	$(CXX) -o tree $(OBJS) $(LDFLAGS)

test: test.o Complex.o NodeItem.o
	$(CXX) -o test test.o Complex.o NodeItem.o $(LDFLAGS)

main.o: main.cpp Tree.hpp Complex.hpp NodeItem.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c main.cpp

Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Complex.cpp

NodeItem.o: NodeItem.cpp NodeItem.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c NodeItem.cpp

test.o: test.cpp Tree.hpp Complex.hpp NodeItem.hpp doctest.h
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c test.cpp

clean:
	rm -f *.o tree test
