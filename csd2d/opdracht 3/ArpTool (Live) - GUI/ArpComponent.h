/*
  ==============================================================================

    ArpComponent.h
    Created: 9 Jun 2020 4:27:38pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ArpComponent    : public Component
{
public:
    ArpComponent();
    ~ArpComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ArpComponent)
    Slider  arpSpeed;
    Label   arpSpeedLabel;
    Slider  jumpSteps;
    Label   jumpStepsLabel;
    Slider  tonalRange;
    Label   tonalRangeLabel;
};
