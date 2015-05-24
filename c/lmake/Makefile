objects = main.o mytool1.o mytool2.o
COMPILER = gcc
CCFLAGS = -Wall

main: $(objects)
	$(COMPILER) $(CCFLAGS) $(objects)

mytool1.o: mytool1.h

mytool2.o: mytool2.h

clean:
	rm $(objects) a.out
    
