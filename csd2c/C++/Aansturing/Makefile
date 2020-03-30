CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++17
LDFLAGS= -ljack -Wall

all: example

example : jack_module.o circBuffer.o main.o oscillator.o sine.o lfosine.o flanger.o osc.o
	$(CC) -o $@ $(CFLAGS) jack_module.o circBuffer.o main.o oscillator.o sine.o lfosine.o flanger.o osc.o -llo $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
