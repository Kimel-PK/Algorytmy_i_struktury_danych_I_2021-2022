CFLAGS = -Wall -std=c++11 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: BinaryTree.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

BinaryTree.x: BinaryTree.o
BinaryTree.o: BinaryTree.cpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump