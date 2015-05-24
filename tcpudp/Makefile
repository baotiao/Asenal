CXXFLAGS= -g -D__XDEBUG__
.PHONY: all clean


OBJECT= srv cli udp ucli

all: $(OBJECT)

srv: srv.cc csapp.cc
	g++ $(CXXFLAGS) $^  -lpthread -o $@

cli: cli.cc csapp.cc
	g++ $(CXXFLAGS) $^ -lpthread -o $@

udp: udp.cc csapp.cc
	g++ $(CXXFLAGS) $^ -lpthread -o $@

ucli: ucli.cc csapp.cc
	g++ $(CXXFLAGS) $^ -lpthread -o $@

clean:
	rm -rf $(OBJECT)
