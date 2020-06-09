#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"
#include "FilterComponent.h"
#include "ArpComponent.h"

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
    HeaderComponent headerBlock;
    FilterComponent filterBlock;
    ArpComponent arpBlock;
    


    ComboBox arpRhythmSetter;
    ComboBox beatRhythmSetter;
    ComboBox keyScaleSetter;

    Slider arpVol;
    Slider beatVol;
    Slider masterVol;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
