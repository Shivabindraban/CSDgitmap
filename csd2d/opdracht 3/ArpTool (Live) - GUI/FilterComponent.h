/*
  ==============================================================================

    FilterComponent.h
    Created: 9 Jun 2020 4:26:50pm
    Author:  Shiva

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FilterComponent    : public Component
{
public:
    FilterComponent();
    ~FilterComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
