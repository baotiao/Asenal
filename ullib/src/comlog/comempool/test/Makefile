CC=g++
INCLUDES=-I../
CFLAGS = -fsigned-char -Wall -W -pipe -Wno-unused-parameter -g 
LDFLAGS= -L../ -lcomempool -lm -lpthread
OBJS=test.o
TARGET=test
LIB=
all : $(TARGET) $(LIB)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)

tags : 
	 ctags -R *

clean:
	rm -f $(OBJS) $(TARGET) $(LIB) core.[0-9]*

