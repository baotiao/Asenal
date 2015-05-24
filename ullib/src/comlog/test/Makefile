CC=g++
WORKROOT=../../../../../

MARCS=
ifeq ($(MAC),64)
LIBPATH=$(WORKROOT)lib2-64
else
LIBPATH=$(WORKROOT)lib2
endif

ULLIB=../../../output

INCLUDES= -I$(ULLIB)/include -I$(ULLIB)/include/comlog/
CFLAGS = -fsigned-char -Wall -W -pipe -Wno-unused-parameter -g -D__XDEBUG__ -D__YDEBUG__
LDFLAGS=  -L$(ULLIB)/lib -lullib -lpthread -lm
OBJS=test.o ptest.o ultest.o test.o test2.o test3.o test4.o test6.o
TARGET=test ptest ultest test test2 test3 test4 test6
LIB=

all : $(TARGET) $(LIB)
	rm -f $(OBJS) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

ultest : ultest.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test : test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test2 : test2.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test3 : test3.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test4 : test4.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test6 : test6.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

ptest : ptest.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)

tags : 
	ctags -R *

clean:
	rm -f $(OBJS) $(TARGET) $(LIB) core.[0-9]*
