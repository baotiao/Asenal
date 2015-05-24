CXX = g++
CXXFLAGS = -Wall -W -DDEBUG -g -O2 -D__XDEBUG__
OBJECT = qlog
SRC_DIR = src

LIB_PATH = -L./
LIBS = 

INCLUDE_PATH = -I./include/

.PHONY: all clean


BASE_BOJS := $(wildcard $(SRC_DIR)/*.cc)
BASE_BOJS += $(wildcard $(SRC_DIR)/*.c)
BASE_BOJS += $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cc,%.o,$(BASE_BOJS))

all: $(OBJECT)
	@echo $(OBJS)
	rm $(SRC_DIR)/*.o

$(OBJECT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDE_PATH) $(LIB_PATH) $(LIBS)

$(OBJS) : %.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE_PATH) 
