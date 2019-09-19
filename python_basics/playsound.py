import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("/media/shiva/Data/Samples/Linuxmap/kick.wav")

PlayAmount = input('How many times would you like to play your sample? ')
if( PlayAmount.isdigit()):
    for PlayAmount in range(int(PlayAmount)):
        play_obj = wave_obj.play()
        play_obj.wait_done()
        print(PlayAmount)
        print('dong')
else:
    print("You did not enter a number")
