CFLAGS = -Wall -std=c++11 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: Generator.x ArrayList.x CursorList.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

Generator.x: Generator.o
Generator.o: Generator.cpp

ArrayList.x: ArrayList.o
ArrayList.o: ArrayList.cpp ArrayList.hpp

CursorList.x: CursorList.o
CursorList.o: CursorList.cpp CursorList.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump