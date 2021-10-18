DIR = `basename $(CURDIR)`

NAME2 = Generator
NAME1 = Stack
NAME3 = ONP

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o

CFLAGS = -Wall -std=c11 -pedantic -O -fPIC
LFLAGS = -Wall -std=c11 -pedantic -O

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rsv

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(OBJS1) $(LIBS1)
	$(LD) -o $@ $(LFLAGS) $^
	
$(EXEC2): $(OBJS2) $(LIBS2)
	$(LD) -o $@ $(LFLAGS) $^
	
$(EXEC3): $(OBJS3) $(LIBS3)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}