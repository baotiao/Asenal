

#--------------------path para----------------------
WORKROOT=../..
ifeq ($(MAC),64)
	LIBPATH=$(WORKROOT)/ullib/output
else
	LIBPATH=$(WORKROOT)/ullib/output
endif

ULLIB=$(LIBPATH)/

#-------------------c flags--------------------------
CC=g++
INCLUDES=-I$(ULLIB)/include 
CFLAGS =-fPIC -fsigned-char -Wall -W -pipe -Wno-unused-parameter -g 
LDFLAGS=-L$(ULLIB)/lib -lullib  -lpthread


#-------------------targets---------------------------


all : test

test : test.cpp
	$(CC) $(CFLAGS) test.cpp -o $@ $(INCLUDES) $(LDFLAGS)

clean:
	rm -rf test

