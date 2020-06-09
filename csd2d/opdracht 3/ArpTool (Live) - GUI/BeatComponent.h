/*
  ==============================================================================

    BeatComponent.h
    Created: 9 Jun 2020 4:27:11pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class BeatComponent    : public Component
{
public:
    BeatComponent();
    ~BeatComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BeatComponent)
};
