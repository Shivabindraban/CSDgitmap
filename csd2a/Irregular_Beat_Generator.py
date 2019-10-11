import simpleaudio as sa
import time
import random

# NOTE:  load multiple audioFiles and store it into a list
synth = sa.WaveObject.from_wave_file("Samples_for_IBG/Synth.wav")
hit = sa.WaveObject.from_wave_file("Samples_for_IBG/Hit_mid.wav")
kick = sa.WaveObject.from_wave_file("Samples_for_IBG/Kick_orchest.wav")
pop = sa.WaveObject.from_wave_file("Samples_for_IBG/Pop.wav")

samples = [kick, synth, hit, pop]

# NOTE: Variables
BPM = 120
BPMSet = True
loopAmountSet = True

# NOTE: This loop forces you to enter a (correct) BPM number
print("default bpm is set at " + str(BPM) + " bpm" + '\n' "Enter a bpm number to adjust:")
while BPMSet==True:
    try:
        BPM = int(input())
        if BPM < 60:
            print("bpm value to Low, enter a number between 50 and 200:")
        elif BPM > 200:
            print("bpm value to High, enter a number between 50 and 200:")
        else:
            print("bpm succesfully set at " + str(BPM) + " bpm")
            BPMSet = False
    except ValueError:
        print("You did not insert a number, try again")

# NOTE: Maatlengte ALS 4/4e
quarterNote = 60.0 / BPM
measureLength = quarterNote * 4.0
sixteenthNoteLength = quarterNote / 4.0

# NOTE: a made up set of of 16th noteDurations
abstractNoteDurationList = [0.0,0.5,0.5,1,0.75]
timestamps16th = []
timestamps=[]



# NOTE: converts the note durations to abstract timestamps
def durationsToTimestamps16th(abstractNoteDurationList):
    currentTimestamp= 0
    for abstractNoteDuration in abstractNoteDurationList:
        # the adding of currentTimestamp is needed to make the list cumulative
        timestamps16th.append(int(abstractNoteDuration*4 + currentTimestamp))
        currentTimestamp = abstractNoteDuration*4 + currentTimestamp

durationsToTimestamps16th(abstractNoteDurationList)
print("this will be your sequence list ", timestamps16th)

# NOTE: converts the abstract timestamps to timestamps in seconds with selected BPM
def realTimeTimestamps(sixteenthNoteLength,timestamps16th):
    for timestamp in timestamps16th:
        timestamps.append(timestamp * sixteenthNoteLength)

realTimeTimestamps(sixteenthNoteLength,timestamps16th)

# NOTE: THis loop forces you to enter a (correct) number to determine how many times to loop the sequence
while loopAmountSet==True:
    try:
        loopAmount=int(input("How many times do you want to hear a sequence? > "))
        loopAmountSet=False
    except ValueError:
        print("You did not insert a number, try again")

abstractNoteDurationList = [0.0,0.5,0.5,1,0.75]

# NOTE: This loop determines how many the origal loop should play
i=0
while i < loopAmount:
    i+=1 # For meeting the loopAmount
    x=1
    # To go through each element of the timestamp. The loop will play x=1-5. When the 4th sample is played, the next x will be 0 because of the modulo.
    # This 0 will cause next sample to play, but will break the loop after, since 0 < 1.
    startTime = time.time()
    loopplay=True
    while loopplay==True:
        # retrieve current time
        currentTime = time.time()
        if(currentTime - startTime >= timestamps[x-1]):
            samples[random.randint(0,len(samples)-1)].play()
            # samples[3].play()
            if x >= 1:
                x = (x + 1)%len(timestamps)
            else:
                loopplay=False
        else:
            time.sleep(0.001)
    time.sleep(measureLength - timestamps[-1])
