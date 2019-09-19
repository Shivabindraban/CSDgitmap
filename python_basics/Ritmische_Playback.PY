import simpleaudio as sa
# ^enable-t geluid module
import time
# ^enable-t tijd/delay module
Kick = sa.WaveObject.from_wave_file("/media/shiva/Data/Samples/Linuxmap/kick.wav")
# ^ Laadt sample in
sequenceList=[]
# ^ Maakt lege lijst aan, waar de aan te geven nootlengtewaardes in komen
numPlaybackTimes= input("How many times would you like to play the sample? > " )
# ^Aantal playbacks/ritme
for noteNumber in range(int(numPlaybackTimes)):
    print("for number", noteNumber + 1, ":")
    sequenceValue = input("choose one of the following notelenghts: Whole note = 1, Half note = 2, Quarter note = 4, Eighth note = 8 > ")
    sequenceList.append(float(sequenceValue))
    # ^ maakt een lijst met de ingevoerde nootlengtewaardes
print("these are your chosen values", sequenceList)
BPM=input("What BMP do you want? > ")
wholeNoteLen=(60000./float(BPM))*4

for sequence in sequenceList:
    sequence = float(sequence)
    print("dong")
    print(wholeNoteLen/sequence, "ms")
    play_obj = Kick.play()
    time.sleep((wholeNoteLen/sequence)/1000)
    # ^ speelt de sample af met elke aangegeven nootlengtewaarde van de  sequenceList en houdt dit als delaytijd aan voor de volgende
