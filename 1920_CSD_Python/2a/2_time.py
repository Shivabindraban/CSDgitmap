# import the time module
import time
import simpleaudio as sa

# use it in a forloop
"""
for i in range(5):
    print("hi")
    time.sleep(2)
"""

# play a timed sequence using print
measure = [1, 0.5, 1, 1, 0.5]

"""
for seconds in measure:
    print("hi")
    time.sleep(seconds)
"""

# play a timed sequence, playing a sound
# load an audioFiles, create an sample object
sample_pop = sa.WaveObject.from_wave_file("Pop.wav")
for seconds in measure:
    sample_pop.play()
    time.sleep(seconds)
