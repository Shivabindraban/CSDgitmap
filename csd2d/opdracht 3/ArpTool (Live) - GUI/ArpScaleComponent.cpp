/*
  ==============================================================================

    ArpScaleComponent.cpp
    Created: 9 Jun 2020 9:10:11pm
    Author:  Shiva

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ArpScaleComponent.h"

//==============================================================================
ArpScaleComponent::ArpScaleComponent()
{
    scaleDropDown.addItem("Aeolian", 1);
    scaleDropDown.addItem("Blues", 2);
    scaleDropDown.addItem("Harmonic Major", 3);
    scaleDropDown.addItem("Ionian", 4);
    scaleDropDown.addItem("Locrian", 5);
    scaleDropDown.addItem("Lydian", 6);
    scaleDropDown.addItem("Phrygian", 7);
    addAndMakeVisible(scaleDropDown);

    scaleDropDownLabel.setText("Scale Presets:", dontSendNotification);
    scaleDropDownLabel.attachToComponent(&scaleDropDown, false);
    addAndMakeVisible(scaleDropDownLabel);

}

ArpScaleComponent::~ArpScaleComponent()
{
}

void ArpScaleComponent::paint (Graphics& g)
{

}

void ArpScaleComponent::resized()
{
    scaleDropDown.setBounds(20, 0, 100, 20);

}
