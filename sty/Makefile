CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11 -DDEBUG
OBJECT = m1 m2

.PHONY = all m1 m2 clean

all: $(OBJECT)
	@echo "Success, go, go, go..."
 

m1: model1.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m1

m2: model2.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m2
 
clean:
	rm -rf $(OBJECT)
	rm -rf *.o
	rm -rf *.gch
	rm -rf a.out
