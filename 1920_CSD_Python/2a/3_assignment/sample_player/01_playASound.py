"""
An example project in which three wav files are used.

------ EXERCISES ------

- What does the function wait_done() do?
>
Waits till the sound has been played, to continue the code

- Answer the following question before running the code:
  Do you expect to hear the samples played simultaneously or one after the other?
  Why?
>
No, because of the wait_done() function

- Alter the code:
  Play the sounds one after the other and then simultaneously.
>
synthPlay = synth.play()
synthPlay.wait_done()

hitPlay = hit.play()
hitPlay.wait_done()

kickPlay = kick.play()
kickPlay.wait_done()

synthPlay = synth.play()
hitPlay = hit.play()
kickPlay = kick.play()
kickPlay.wait_done()

- Alter the code:
  Ask the user to choose which one of the three samples should be played and
  only play the chosen sample.
>
sampleChoice = input("Which sample do you want to hear? \n  Enter 1 for a Synth, 2 for a Hit and 3 for a Kick> ")
sampleChoice = int(sampleChoice)
if sampleChoice==1:
    synthPlay = synth.play()
    synthPlay.wait_done()
elif sampleChoice==2:
    hitPlay = hit.play()
    hitPlay.wait_done()
elif sampleChoice==3:
    kickPlay = kick.play()
    kickPlay.wait_done()
else:
        print("this number is not assigned")

- Give yourself a couple of assignments, like playing one of the samples ten
  times before the others are played, playing all samples a given number
  of times or playing the samples one after the other with 1 second between
  them.
>
sampleChoice = input("Which sample do you want to hear? \n  Enter 1 for a Synth, 2 for a Hit and 3 for a Kick> ")
sampleChoice = int(sampleChoice)
Playtimes = input("How many times do you want to hear this sample? Enter a number > ")
Playtimes = int(Playtimes)
if sampleChoice==1:
    for x in range(Playtimes):
        synthPlay = synth.play()
        time.sleep(0.5)
        if x == (Playtimes -1):
            print("done")
elif sampleChoice==2:
    for x in range(Playtimes):
        hitPlay = hit.play()
        time.sleep(0.5)
        if x == (Playtimes -1):
            print("done")
elif sampleChoice==3:
    for x in range(Playtimes):
        kickPlay = kick.play()
        time.sleep(0.5)
        if x == (Playtimes -1):
            print("done")
else:
    print("this number is not assigned")

"""

# simpleaudio is imported as sa -> shorter name
import simpleaudio as sa
import time

# load audio files
synth = sa.WaveObject.from_wave_file("../audioFiles/Synth.wav")
hit = sa.WaveObject.from_wave_file("../audioFiles/Hit_mid.wav")
kick = sa.WaveObject.from_wave_file("../audioFiles/Kick_orchest.wav")

sampleChoice = input("Which sample do you want to hear? \n  Enter 1 for a Synth, 2 for a Hit and 3 for a Kick> ")
sampleChoice = int(sampleChoice)
Playtimes = input("How many times do you want to hear this sample? Enter a number > ")
Playtimes = int(Playtimes)
if sampleChoice==1:
    for x in range(Playtimes):
        synthPlay = synth.play()
        time.sleep(0.5)
        if x == (Playtimes -1):
            print("done")
elif sampleChoice==2:
    for x in range(Playtimes):
        hitPlay = hit.play()
        time.sleep(0.5)
        if x == (Playtimes -1):
            print("done")
elif sampleChoice==3:
    for x in range(Playtimes):
        kickPlay = kick.play()
        time.sleep(0.5)
        if x == (Playtimes -1):
            print("done")
else:
    print("this number is not assigned")

timeZero=1000*time.time();

# synthPlay = synth.play()
# synthPlay.wait_done()
# now=time.time()*1000
# verschil = now-timeZero
# print(verschil)
# time.sleep(verschil/1000)
#
# hitPlay = hit.play()
# hitPlay.wait_done()
# now2=time.time()*1000
# verschil2 = now2-timeZero - verschil
# print(verschil2)
# time.sleep(verschil2/1000)
#
# kickPlay = kick.play()
# kickPlay.wait_done()
# now3=time.time()*1000
# verschil3 = now3-timeZero - verschil -verschil2
# print(verschil3)
