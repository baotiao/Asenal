CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11 -DDEBUG
OBJECT = m1 m21 m22

.PHONY = all m1 m21 m22 clean

all: $(OBJECT)
	@echo "Success, go, go, go..."
 

m1: model1.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m1

m21: model2-1.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m21

m22: model2-2.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m22
 
clean:
	rm -rf $(OBJECT)
	rm -rf *.o
	rm -rf *.gch
	rm -rf a.out
