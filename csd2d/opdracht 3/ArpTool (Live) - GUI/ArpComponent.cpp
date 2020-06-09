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

    scaleDropDown.addItem("Aeolian", 1);
    scaleDropDown.addItem("Blues", 2);
    scaleDropDown.addItem("Harmonic Major", 3);
    scaleDropDown.addItem("Ionian", 4);
    scaleDropDown.addItem("Locrian", 5);
    scaleDropDown.addItem("Lydian", 6);
    scaleDropDown.addItem("Additive", 7);
    addAndMakeVisible(scaleDropDown);

    scaleDropDownLabel.setText("Scale Presets:", dontSendNotification);
    scaleDropDownLabel.attachToComponent(&scaleDropDown, false);
    addAndMakeVisible(scaleDropDownLabel);

    arpRhythmDropDown.addItem("Steady Notes", 1);
    arpRhythmDropDown.addItem("Conga", 2);
    arpRhythmDropDown.addItem("Son Clave", 3);
    arpRhythmDropDown.addItem("Mambo", 4);
    arpRhythmDropDown.addItem("Salsa", 5);
    arpRhythmDropDown.addItem("Habanero", 6);
    arpRhythmDropDown.addItem("Phrygian", 7);
    addAndMakeVisible(arpRhythmDropDown);

    arpRhythmDropDownLabel.setText("Rhythm Presets:", dontSendNotification);
    arpRhythmDropDownLabel.attachToComponent(&arpRhythmDropDown, false);
    addAndMakeVisible(arpRhythmDropDownLabel);

         
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

    arpRhythmDropDown.setBounds(80, 160, 100, 20);
    scaleDropDown.setBounds(300, 160, 100, 20);



}
