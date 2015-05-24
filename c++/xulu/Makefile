ifdef OPT
  CCFLAGS = -O2
else
  CCFLAGS = -g
endif

CC=g++
HEADERS=formula.h clause.h debug.h clause_impl.h formula_impl.h solver.h
SOURCES=sat.cpp formula.cpp clause.cpp debug.cpp clause_impl.cpp formula_impl.cpp solver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sat

all: $(SOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f sat *.o
