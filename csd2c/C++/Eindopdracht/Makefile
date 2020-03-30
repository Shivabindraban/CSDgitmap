CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : jack_module.o main.o oscillator.o lfo_sine.o distortion.o flanger.o circBuffer.o
	$(CC) -o $@ $(CFLAGS) jack_module.o main.o oscillator.o lfo_sine.o distortion.o flanger.o circBuffer.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
