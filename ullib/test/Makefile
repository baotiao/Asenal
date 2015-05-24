CC=g++
WORKROOT=../../../../../

MARCS=
ifeq ($(MAC),64)
LIBPATH=$(WORKROOT)lib2-64
else
LIBPATH=$(WORKROOT)lib2
endif

PUBLIC=$(WORKROOT)/public
ULLIB=$(LIBPATH)/ullib/
NSHEAD=$(PUBLIC)/nshead/
DICT=$(LIBPATH)/dict/
MYNET=$(PUBLIC)/ns/mynet/
COMLOG=../../../include/comlog/
MEMPOOl=../../comempool

INCLUDES= -I../include
CFLAGS = -fsigned-char -Wall -W -pipe -Wno-unused-parameter -g -D__XDEBUG__ -D__YDEBUG__
LDFLAGS=  -L../lib -L..\
		  -lullib -lpthread -lm
OBJS=test.o ptest.o ultest.o test2.o test3.o test4.o test_layout_leak.o test_adpater.o test_pack.o test_pack_io_client.o test_pack_io_server.o test_ul_conf.o test_ul_url.o test_ul_url_vhplink.o
TARGET=test test2 test3 test4 test_layout_leak test_adapter test_pack test_pack_client test_pack_server test_ul_conf test_ul_url test_ul_url_vhplink
LIB=
all : $(TARGET) $(LIB)
	rm -f $(OBJS) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

test3 : test3.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test : test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test2 : test2.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)


test4 : test4.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_layout_leak : test_layout_leak.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test5 : test5.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_adapter : test_adapter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_pack : test_pack.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_pack_client : test_pack_io_client.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_pack_server : test_pack_io_server.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_ul_conf : test_ul_conf.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_ul_poll: test_ul_poll.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_ul_url: test_ul_url.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

test_ul_url_vhplink: test_ul_url_vhplink.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INCLUDES)

$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)

tags : 
	ctags -R *

clean:
	rm -f $(OBJS) $(TARGET) $(LIB) core.[0-9]*


