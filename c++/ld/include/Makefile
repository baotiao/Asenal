CXX = g++
FLAGS = -Wall -W -DDEBUG
OBJECT = a.out

INCLUDE_PATH = -I./

BASE_BOJS := $(wildcard *.cpp)
BASE_BOJS += $(wildcard *.c)
OBJS := $(patsubst %.cpp,%.o,$(BASE_BOJS))

$(OBJECT): $(OBJS)
	$(CXX) $(FLAGS) -o $@ $^ $(INCLUDE_PATH)
%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@ $(INCLUDE_PATH)
clean:
	rm $(OBJECT)
    
