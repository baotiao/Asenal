CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11 -DDEBUG
OBJECT = m1 m21 m22 m31 m32

.PHONY = all $(OBJECT) clean

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
 
m31: model3-1.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m31

m32: model3-2.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out m32

clean:
	rm -rf $(OBJECT)
	rm -rf *.o
	rm -rf *.gch
	rm -rf a.out
