/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    Slider bpmDial;
    Label bpmLabel;

    Slider arpSpeed;
    Label arpSpeedLabel;
    Slider jumpSize;
    Label jumpSizeLabel;
    Slider tonalRange;
    Label tonalRangeLabel;

    ComboBox arpRhythmSetter;
    ComboBox beatRhythmSetter;
    ComboBox keyScaleSetter;

    Slider arpVol;
    Slider beatVol;
    Slider masterVol;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
