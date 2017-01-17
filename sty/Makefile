CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11 -DDEBUG
# OBJECT = m1 m21 m22 m31 m32 p p1

OBJECT = mm ppnm

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

p: pprocess.cc
	$(CXX) $(CXXFLAGS) $^ xdebug.h
	mv a.out p

pp: pp.cc
	$(CXX) $(CXXFLAGS) $^ xdebug.h
	mv a.out pp

ppnm: ppnm.cc
	$(CXX) $(CXXFLAGS) $^ xdebug.h
	mv a.out ppnm

mm: mm.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out mm

nm: nm.cc
	$(CXX) $(CXXFLAGS) $^ sty.h xdebug.h
	mv a.out nm

clean:
	rm -rf $(OBJECT)
	rm -rf *.o
	rm -rf *.gch
	rm -rf a.out
