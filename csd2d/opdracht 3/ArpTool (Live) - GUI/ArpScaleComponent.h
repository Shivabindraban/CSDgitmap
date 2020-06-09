/*
  ==============================================================================

    ArpScaleComponent.h
    Created: 9 Jun 2020 9:10:11pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ArpScaleComponent    : public Component
{
public:
    ArpScaleComponent();
    ~ArpScaleComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ArpScaleComponent)
    ComboBox  scaleDropDown;
    Label scaleDropDownLabel;
};
