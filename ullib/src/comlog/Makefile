CC=g++


ifeq ($(DEBUG), open)
	DEBUGOPEN=-D__XDEBUG__
else
	DEBUGOPEN=
endif

ifeq ($(DEBUG), sec)
	DEBUGOPEN=-D__YDEBUG__
endif

ifeq ($(CHECK), check)
	CHECKOPEN=-D__CHECK__
else
	CHECKOPEN=
endif

MPOOL=-D_XLOG_MEMPOOL_USED_
GCC4_IGNORE_WARNINGS= -Wno-write-strings

INCLUDES=-I../../include -I../../include/comlog -I../../include/comlog/comempool -I../../include/comlog/appender \
		 -I../../include/comlog/sendsvr
#CFLAGS =-fPIC -fsigned-char -Wall -W -pipe -Wno-unused-parameter -g $(DEBUGOPEN) $(CHECKOPEN) $(GCC4_IGNORE_WARNINGS) -D__XDEBUG__
CFLAGS =-fPIC -fsigned-char -Wall -W -pipe -Wno-unused-parameter -g $(DEBUGOPEN) $(CHECKOPEN) $(GCC4_IGNORE_WARNINGS)
LDFLAGS= 
OBJS= category.o event.o layout.o logcore.o namemg.o xutils.o comlog.o logstat.o comsig.o\
	 appender/appender.o appender/ttyappender.o appender/fileappender.o appender/netappender.o appender/ullogappender.o\
	 sendsvr/sendsvr.o sendsvr/checksvr.o sendsvr/netappendersvr.o appender/asyncfileappender.o appender/appenderfactory.o \
	 comempool/dlist.o comempool/mempool.o sendsvr/loghead.o
TARGET=
#LIB=libcomlog.a
all : $(TARGET) $(OBJS) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(TARGET) $(LIB)

