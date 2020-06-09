/*
  ==============================================================================

    BeatRhythmComponent.h
    Created: 9 Jun 2020 9:09:26pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class BeatRhythmComponent    : public Component
{
public:
    BeatRhythmComponent();
    ~BeatRhythmComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BeatRhythmComponent)
};
