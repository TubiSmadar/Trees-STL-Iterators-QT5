CXX=clang++
CXXFLAGS=-std=c++11 -Wall -Wextra -g
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

# The default target
all: tree test

# Rule to create the tree executable
tree: Demo.o dfs.o bfs.o inOrder.o preOrder.o postOrder.o complex.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to create the test executable
test: test.o dfs.o bfs.o inOrder.o preOrder.o postOrder.o tree.o complex.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to run valgrind on tree and test
valgrind: tree test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./tree 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# Rule to run clang-tidy
tidy:
	clang-tidy $(SRCS) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --
# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Demo.o: Demo.cpp tree.hpp node.hpp 
	$(CXX) $(CXXFLAGS) -c Demo.cpp


# Rule to clean the build directory
clean:
	rm -f $(OBJS) tree test
