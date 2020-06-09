#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"
#include "BeatComponent.h"
#include "FilterComponent.h"
#include "ArpComponent.h"
#include "MasterVolComponent.h"

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
    BeatComponent beatBlock;
    FilterComponent filterBlock;
    ArpComponent arpBlock;
    MasterVolComponent masterVolBlock;


    ComboBox arpRhythmSetter;
    ComboBox beatRhythmSetter;
    ComboBox keyScaleSetter;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
