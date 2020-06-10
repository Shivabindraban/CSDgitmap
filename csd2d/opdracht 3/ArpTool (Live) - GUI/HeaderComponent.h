/*
  ==============================================================================

    HeaderComponent.h
    Created: 9 Jun 2020 4:22:16pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class HeaderComponent    : public Component
{
public:
    HeaderComponent();
    ~HeaderComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HeaderComponent);
    Slider  bpmDial;
    Label   bpmLabel;
    ToggleButton onOrOff;
};
