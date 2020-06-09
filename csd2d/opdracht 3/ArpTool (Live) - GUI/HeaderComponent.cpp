/*
  ==============================================================================

    HeaderComponent.cpp
    Created: 9 Jun 2020 4:22:16pm
    Author:  Shiva

  ==============================================================================
*/

#include <JuceHeader.h>
#include "HeaderComponent.h"

//==============================================================================
HeaderComponent::HeaderComponent()
{
    bpmDial.setRange(60, 128, 1);
    bpmDial.setSliderStyle(Slider::SliderStyle::Rotary);
    bpmDial.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(bpmDial);

    bpmLabel.setText("BPM set @ ", dontSendNotification);
    bpmLabel.attachToComponent(&bpmDial, false);
    addAndMakeVisible(bpmLabel);

}

HeaderComponent::~HeaderComponent()
{
}

void HeaderComponent::paint (Graphics& g)
{  
}

void HeaderComponent::resized()
{
    bpmDial.setBounds(0, 0, 100, 100);
}
