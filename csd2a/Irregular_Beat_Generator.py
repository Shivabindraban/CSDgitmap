import simpleaudio as sa
import time
import random
from midiutil import MIDIFile

# NOTE:  load multiple audioFiles and store it into a list
synth = sa.WaveObject.from_wave_file("Samples_for_IBG/Synth.wav")
hit = sa.WaveObject.from_wave_file("Samples_for_IBG/Hit_mid.wav")
kick = sa.WaveObject.from_wave_file("Samples_for_IBG/Kick_orchest.wav")
pop = sa.WaveObject.from_wave_file("Samples_for_IBG/Pop.wav")
samples = [kick, synth, hit, pop]

# NOTE: Variables
BPM = 120

# NOTE: This loop forces you to enter a (correct) BPM number
print("Default bpm is set at " + str(BPM) + " bpm. Please enter a bpm number to adjust:")
while True:
    try:
        BPM = int(input())
        if BPM < 60:
            print("bpm value too Low, enter a number between 60 and 200:")
        elif BPM > 200:
            print("bpm value too High, enter a number between 60 and 200:")
        else:
            print("\nbpm succesfully set at " + str(BPM) + " bpm." )
            break
    except ValueError:
        print("You did not insert a number, try again")


# NOTE: determine the time signature
print("We will now set up a timesignature \n-->")
while True:
    try:
        timeSig_2=int(input("If you want quarter notes, Enter > 4 < and If you want eight notes, Enter > 8 < :\n"))
        if timeSig_2 != 4 and timeSig_2 != 8:
            print("please Enter a 4 or 8")
        elif timeSig_2 == 4 or timeSig_2 == 8:
            break
    except ValueError:
        print("You did not insert a (whole) number, try again")
while True:
    try:
        timeSig_1=int(input("How many do you want of the chosen note length in one measure?\nPlease enter a number:\n" ))
        break
    except ValueError:
        print("You did not insert a (whole) number, try again")
print("timesignature succesfully set at " + str(timeSig_1) + " / " + str(timeSig_2))

# NOTE: Calculate the length of a whole measure
quarterNote = 60.0 / BPM
sixteenthNoteLength = quarterNote / 4.0
if timeSig_2 == 4:
    measureLength = timeSig_1 * quarterNote
elif timeSig_2 == 8:
    measureLength = timeSig_1 * (quarterNote/2)
sixteenthAmount = int(measureLength / sixteenthNoteLength)

# NOTE: make 3 patterns to play
sound1list=[]
sound2list=[]
sound3list=[]
a=0
while a<sixteenthAmount:
    print(a)
    if a%4==0:
        sound1list.append(1)
    else:
        sound1list.append(0)
    a+=1
b=0
while b <sixteenthAmount:
    print(b)
    if b%8==0:
        sound2list.append(1)
    else:
        sound2list.append(0)
    b+=1
c=0
while c<sixteenthAmount:
    print(c)
    if c%4==0:
        sound3list.append(0)
    else:
        sound3list.append(1)
    c+=1

print(sound1list)
print(sound2list)
print(sound3list)

#MIDI file write
degrees  = sound1list # MIDI note number
track    = 0
channel  = 9
timer    = 0   # In beats
tempo    = BPM  # In BPM
volume   = 100 # 0-127, as per the MIDI standard

MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track automatically created)
MyMIDI.addTempo(track, timer, tempo)

for volume in degrees:
    MyMIDI.addNote(track, channel, 36, timer, 0.25, volume*100)
    timer = timer + 0.25

degrees = sound2list
timer = 0
for volume in degrees:
    MyMIDI.addNote(track, channel, 38, timer, 0.25, volume*100)
    timer = timer + 0.25

degrees = sound3list
timer = 0
for volume in degrees:
    MyMIDI.addNote(track, channel, 42, timer, 0.25, volume*100)
    timer = timer + 0.25

with open("midi_IBG.mid", "wb") as output_file:
    MyMIDI.writeFile(output_file)

def sample_poly():
    if sound1list[x] == 1:
        hit.play()
    if sound2list[x] == 1:
        synth.play()
    if sound3list[x] == 1:
        pop.play()

# NOTE: This loop forces you to enter a (correct) number to determine how many times to loop the sequence
while True:
    try:
        loopAmount=int(input("How many times do you want to hear a sequence? > "))
        break
    except ValueError:
        print("You did not insert a number, try again")


# NOTE: This loop determines how many times the original loop should play
i=0
while i < loopAmount:
    i+=1 # For matching the loopAmount
    x=0
    startTime = time.time()
    while True:
        currentTime = time.time() # retrieve current time
        # This statement will start with 0 and start instantly, since x is given 0 at start.
        if((currentTime - startTime) >= (sixteenthNoteLength * x)):
            sample_poly()
            print(x)
            # The loop should break after the last sixteenth amount is played and stop counting afterwarts.
            # If you have a 4/4th measure with 16 sixteenths, the statement checks from 0-15 (16 times)
            if x == (sixteenthAmount - 1):
                break
            else:
                x = (x + 1)
        else:
            time.sleep(0.001)
    time.sleep(measureLength - (sixteenthNoteLength * x))
