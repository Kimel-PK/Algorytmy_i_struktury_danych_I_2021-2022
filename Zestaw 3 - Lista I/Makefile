CFLAGS = -Wall -std=c++11 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: Generator.x LinkedList.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

Generator.x: Generator.o
Generator.o: Generator.cpp

LinkedList.x: LinkedList.o
LinkedList.o: LinkedList.cpp LinkedList.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump