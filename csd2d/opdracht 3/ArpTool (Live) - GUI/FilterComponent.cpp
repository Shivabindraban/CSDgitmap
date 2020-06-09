/*
  ==============================================================================

    FilterComponent.cpp
    Created: 9 Jun 2020 4:26:50pm
    Author:  Shiva

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent()
{
    FilterCutOff.setRange(20, 20000, 1);
    FilterCutOff.setSliderStyle(Slider::SliderStyle::Rotary);
    FilterCutOff.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(FilterCutOff);

    FilterCutOffLabel.setText("Filter Frequency in Hz", dontSendNotification);
    FilterCutOffLabel.attachToComponent(&FilterCutOff, false);
    addAndMakeVisible(FilterCutOffLabel);

}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (Graphics& g)
{
}

void FilterComponent::resized()
{
    //Needed to adjust X and Y value from 0 to give room for the textbox
    FilterCutOff.setBounds(20, 20, 150, 100);
}
