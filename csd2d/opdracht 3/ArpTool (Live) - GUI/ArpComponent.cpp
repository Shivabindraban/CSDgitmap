/*
  ==============================================================================

    ArpComponent.cpp
    Created: 9 Jun 2020 4:27:38pm
    Author:  Shiva

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ArpComponent.h"

//==============================================================================
ArpComponent::ArpComponent()
{
    arpSpeed.setRange(1, 8, 1);
    arpSpeed.setSliderStyle(Slider::SliderStyle::Rotary);
    arpSpeed.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(arpSpeed);

    arpSpeedLabel.setText("Arp Speed", dontSendNotification);
    arpSpeedLabel.attachToComponent(&arpSpeed, false);
    addAndMakeVisible(arpSpeedLabel);


    jumpSteps.setRange(1, 7, 1);
    jumpSteps.setSliderStyle(Slider::SliderStyle::Rotary);
    jumpSteps.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(jumpSteps);

    jumpStepsLabel.setText("Jump Steps", dontSendNotification);
    jumpStepsLabel.attachToComponent(&jumpSteps, false);
    addAndMakeVisible(jumpStepsLabel);


    tonalRange.setRange(1, 8, 1);
    tonalRange.setSliderStyle(Slider::SliderStyle::Rotary);
    tonalRange.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(tonalRange);

    tonalRangeLabel.setText("Tonal Range", dontSendNotification);
    tonalRangeLabel.attachToComponent(&tonalRange, false);
    addAndMakeVisible(tonalRangeLabel);
         
}

ArpComponent::~ArpComponent()
{
}

void ArpComponent::paint (Graphics& g)
{
}

void ArpComponent::resized()
{
    //Needed to adjust X and Y value from 0 to give room for the textbox
    arpSpeed.setBounds(     20,  20, 150, 100);
    jumpSteps.setBounds(    200, 20, 150, 100);
    tonalRange.setBounds(   400, 20, 150, 100);

}
