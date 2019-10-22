import simpleaudio as sa
import time
import random
from midiutil import MIDIFile

# NOTE:  load multiple audioFiles and store it into a list
synth = sa.WaveObject.from_wave_file("Samples_for_IBG/Synth.wav")
hit = sa.WaveObject.from_wave_file("Samples_for_IBG/Hit_mid.wav")
lazer = sa.WaveObject.from_wave_file("Samples_for_IBG/Laser1.wav")
kick = sa.WaveObject.from_wave_file("Samples_for_IBG/Kick_orchest.wav")
pop = sa.WaveObject.from_wave_file("Samples_for_IBG/Pop.wav")
samples = [kick, synth, lazer, hit, pop]

words = ["please", "would you please", "come on please"]

# NOTE: Variables
BPM = 120
# NOTE: Intro
print("Welcome to Beat Generator V1!\nAfter your setup, a MIDI file will be saved.\nLets set up a sequence\n---")
# NOTE: This loop forces you to enter a (correct) BPM number
print("Default bpm is set at " + str(BPM) + ". Hit <ENTER> to keep it or enter a new bpm number to adjust:")
while True:
    try:
        BPM = int(input() or 120)
        if BPM < 60:
            print("bpm value too Low, enter a number between 60 and 200:")
        elif BPM > 200:
            print("bpm value too High, enter a number between 60 and 200:")
        else:
            print("---\nbpm succesfully set at " + str(BPM) + " bpm.\n---" )
            break
    except ValueError:
        print("You did not insert a (whole) number, " + str(words[random.randint(0, 2)]) + " try again")

# NOTE: determine the time signature
print("We will now set up a timesignature>")
print("If you want quarter notes: Enter > 4 < || If you want eight notes, Enter > 8 <:")
while True:
    try:
        timeSig_2=int(input() or 4)
        if timeSig_2 != 4 and timeSig_2 != 8:
            print("please Enter a 4 or 8")
        elif timeSig_2 == 4 or timeSig_2 == 8:
            break
    except ValueError:
        print("You did not insert a (whole) number, " + str(words[random.randint(0, 2)]) + " try again")
print("How many do you want of the chosen note length in one measure?\nPlease enter a number")
while True:
    try:
        timeSig_1=int(input() or 4)
        if timeSig_1 < 3:
            print("value too low. Please enter a number greater than 3:")
        else:
            break
    except ValueError:
        print("You did not insert a (whole) number, " + str(words[random.randint(0, 2)]) + " try again")
print("timesignature succesfully set at " + str(timeSig_1) + " / " + str(timeSig_2) + "\n---")

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
aCount=0
while a<sixteenthAmount:
    if a%4==0:
        print(aCount)
        if aCount <= 2:
            sound1list.append(1)
        else:
            if random.randint(0, 100) <= 90:
                sound1list.append(1)
            else:
                sound1list.append(0)
        aCount =  aCount + 1
    else:
        sound1list.append(0)
    a+=1

b=0
while b <sixteenthAmount:
    if b%4==0:
        sound2list.append(0)
    elif b%4==1:
        if (random.randint(0, 100)) <= 40:
            sound2list.append(1)
        else:
            sound2list.append(0)
    elif b%4==2:
        if (random.randint(0, 100)) <= 80:
            sound2list.append(1)
        else:
            sound2list.append(0)
    else:
        if (random.randint(0, 100)) <= 60:
            sound2list.append(1)
        else:
            sound2list.append(0)
    b+=1
c=0
while c<sixteenthAmount:
    if (random.randint(0, 100)) >= 50:
        sound3list.append(0)
    else:
        sound3list.append(1)
    c+=1

print(sound1list)
print(sound2list)
print(sound3list)

def sample_poly():
    if sound1list[x] == 1:
        hit.play()
    if sound2list[x] == 1:
        lazer.play()
    if sound3list[x] == 1:
        pop.play()

# NOTE: This loop forces you to enter a (correct) number to determine how many times to loop the sequence
while True:
    try:
        loopAmount=int(input("How many times do you want to hear a sequence? > ") or 4)
        if loopAmount < 1:
            print("value too low. Please enter a (whole) number greater than 0:")
        elif loopAmount > 16:
            print("value too High. Please enter a (whole) number smaller than 16:")
        else:
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
            # print(x)
            # The loop should break after the last sixteenth amount is played and stop counting afterwarts.
            # If you have a 4/4th measure with 16 sixteenths, the statement checks from 0-15 (16 times)
            if x == (sixteenthAmount - 1):
                break
            else:
                x = (x + 1)
        else:
            time.sleep(0.001)
    # To let the last sixteenth note ring out, since only 1 sixteenthNoteLength is left over in the calculation.
    time.sleep(measureLength - (sixteenthNoteLength * x))

print("All done playing!\nNow would you like to safe the MIDI file? (P.S. My choice would be yes)\nPlease Enter a Y or N")
while True:
    MIDIsafe=input()
    if MIDIsafe !="Y" and MIDIsafe !="N":
        print("Please Enter a Y or N")
    else:
        break

if MIDIsafe == "Y":
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
    print("All done! Midi file is saved in the same directory")
else:
    print("File not saved. Have a nice day.")
# sys.exit()
