/*
  ==============================================================================

    MasterVolComponent.cpp
    Created: 9 Jun 2020 4:29:00pm
    Author:  Shiva

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MasterVolComponent.h"

//==============================================================================
MasterVolComponent::MasterVolComponent()
{
    arpVolume.setRange(0, 1.0, 0.01);
    arpVolume.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    arpVolume.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(arpVolume);
  

    arpVolumeLabel.setText("Arp Volume", dontSendNotification);
    arpVolumeLabel.attachToComponent(&arpVolume, true);
    addAndMakeVisible(arpVolumeLabel);


    beatVolume.setRange(0, 1.0, 0.01);
    beatVolume.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    beatVolume.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(beatVolume);

    beatVolumeLabel.setText("Beat Volume", dontSendNotification);
    beatVolumeLabel.attachToComponent(&beatVolume, true);
    addAndMakeVisible(beatVolumeLabel);


    masterVolume.setRange(0, 1.0, 0.01);
    masterVolume.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    masterVolume.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(masterVolume);

    masterVolumeLabel.setText("Master Volume", dontSendNotification);
    masterVolumeLabel.attachToComponent(&masterVolume, true );
    addAndMakeVisible(masterVolumeLabel);

}

MasterVolComponent::~MasterVolComponent()
{
}

void MasterVolComponent::paint (Graphics& g)
{
}

void MasterVolComponent::resized()
{
    //Needed to adjust X and Y value from 0 to give room for the textbox
    arpVolume.setBounds(    80, 5   , getWidth()/1.5, 100);
    beatVolume.setBounds(   80, 55  , getWidth()/1.5, 100);
    masterVolume.setBounds( 80, 105 , getWidth()/1.5, 100);
}
