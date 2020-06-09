/*
  ==============================================================================

    MasterVolComponent.h
    Created: 9 Jun 2020 4:29:00pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MasterVolComponent    : public Component
{
public:
    MasterVolComponent();
    ~MasterVolComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterVolComponent)
};
