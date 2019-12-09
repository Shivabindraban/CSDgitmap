CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= instrument.o percussion.o main.o strings.o drumset.o

example: $(SOURCE)
			$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
			$(CXX) -c $(CXXFLAGS) $<
clean:
			rm -f example *.o
