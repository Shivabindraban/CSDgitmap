all: instrumentProgram

instrument_set : instrument_set.cpp instrument_class.h
				g++ -c instrument_set.cpp

instrument_main : instrument_main.cpp instrument_class.h
				g++ -c instrument_main.cpp

instrumentProgram : instrument_set.o instrument_main.o
				g++ -o instrumentProgram instrument_set.o instrument_main.o

clean :
				rm -f *.o instrumentProgram
