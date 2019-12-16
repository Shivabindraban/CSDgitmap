CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : jack_module.o sine.o saw.o square.o pulse.o main.o oscillator.o synth.o additiveSynth.o AMSynth.o
	$(CC) -o $@ $(CFLAGS) jack_module.o sine.o saw.o square.o pulse.o main.o oscillator.o synth.o additiveSynth.o AMSynth.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
