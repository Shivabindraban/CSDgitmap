# import time
#
# ritmelijst=[]
# Hoeveelnoten=input("hoeveel noten? >")
#
# for nootnummer in range(int(Hoeveelnoten)):
#     nootlengte=input("wat is deze lengte? ")
#     ritmelijst.append(nootlengte)
#
# BPM=input("wat voor BPM? > ")
# helenoot=(60000./float(BPM))*4
#
# for playbacknummer in ritmelijst:
#     print("dong")
#     time.sleep((float(helenoot)/float(playbacknummer))/1000)

import simpleaudio as sa
import time

Kick = sa.WaveObject.from_wave_file("/mnt/d/Samples/Camou's Selection/Kick/kick.wav")
Snare = sa.WaveObject.from_wave_file("/mnt/d/Samples/Camou's Selection/Kick/kick.wav")
Hihat = sa.WaveObject.from_wave_file("/mnt/d/Samples/Camou's Selection/Kick/kick.wav")

sequence=[]
sequence.append(0,Kick)


timestamps16th=[0,1,4,5,7,11,14,15]
quarterNoteDuration = 500               #assuming BPM 120
sixteenthNoteDuration = quarterNoteDuration/4
timeZero = 1000*time.time();                                                    # Get time in milliseconds

ts=timestamps16th.pop(0)
while True:
    now=1000*time.time()                                                        # voor millisecondes, normale uitdrukking in secondes. Checks time!
    if now-timeZero >= ts*sixteenthNoteDuration:                                # Wanneer tijd. Controleert of het tijd is om de volgende sample af te spelen
        print(ts)
        print(now)
        play_obj = Kick.play()
        if timestamps16th:
            ts=timestamps16th.pop(0)
        else:
            break
    else:
        time.sleep(0.001)                                                       # in secondes, dit is dus 1 millisecondes
