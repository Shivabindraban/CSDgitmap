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
    // Filter Cut off Dial
    filterCutOff.setRange(20, 20000, 1);
    filterCutOff.setSliderStyle(Slider::SliderStyle::Rotary);
    filterCutOff.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(filterCutOff);
    

    filterCutOffLabel.setText("Filter Frequency in Hz", dontSendNotification);
    filterCutOffLabel.attachToComponent(&filterCutOff, false);
    addAndMakeVisible(filterCutOffLabel);

    // Options to change filtertypes. I did not adjust the mapping accordingly for this
    filterType.addItem("LowPass", 1);
    filterType.addItem("HighPass", 2);
    filterType.addItem("BandPass", 3);
    addAndMakeVisible(filterType);

    filterTypeLabel.setText("Filter Type:", dontSendNotification);
    filterTypeLabel.attachToComponent(&filterType, false);
    addAndMakeVisible(filterTypeLabel);

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
    filterCutOff.setBounds(20, 20, 150, 100);
    filterType.setBounds(180,20,100,20);

}
