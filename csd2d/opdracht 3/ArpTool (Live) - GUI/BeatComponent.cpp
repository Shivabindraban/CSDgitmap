/*
  ==============================================================================

    BeatComponent.cpp
    Created: 9 Jun 2020 4:27:11pm
    Author:  Shiva

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BeatComponent.h"

//==============================================================================
BeatComponent::BeatComponent()
{
    
    
    beatChooseDropDown.addItem("Beat 1", 1);
    beatChooseDropDown.addItem("Beat 2", 2);
    beatChooseDropDown.addItem("Beat 3", 3);
    beatChooseDropDown.addItem("Beat 4", 4);
    beatChooseDropDown.addItem("Beat 5", 5);
    beatChooseDropDown.addItem("Beat 6", 6);
    beatChooseDropDown.addItem("Beat 7 (RANDOM)", 7);
    addAndMakeVisible(beatChooseDropDown);

    beatChooseDropDownLabel.setText("Beat Presets:", dontSendNotification);
    beatChooseDropDownLabel.attachToComponent(&beatChooseDropDown, false);
    addAndMakeVisible(beatChooseDropDownLabel);

}

BeatComponent::~BeatComponent()
{
}

void BeatComponent::paint (Graphics& g)
{
}

void BeatComponent::resized()
{
    beatChooseDropDown.setBounds(80, 35, 100, 20);

}
