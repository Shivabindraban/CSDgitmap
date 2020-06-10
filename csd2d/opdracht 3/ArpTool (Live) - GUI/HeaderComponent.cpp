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
    // BPM dial
    bpmDial.setRange(60, 200, 1);
    bpmDial.setSliderStyle(Slider::SliderStyle::Rotary);
    bpmDial.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    addAndMakeVisible(bpmDial);
    
    bpmLabel.setText("BPM", dontSendNotification);
    bpmLabel.attachToComponent(&bpmDial, false);
    addAndMakeVisible(bpmLabel);


    // On and Off  "PowerButton" Logo/toggle Button
    addAndMakeVisible(onOrOff);
    onOrOff.setColour(ToggleButton::tickColourId, Colours::white);
    onOrOff.setColour(ToggleButton::tickDisabledColourId, Colours::black);
    onOrOff.setButtonText("OnOrOff");
    onOrOff.changeWidthToFitText();
    


}

HeaderComponent::~HeaderComponent()
{
}

void HeaderComponent::paint (Graphics& g)
{  
}

void HeaderComponent::resized()
{
    //Needed to adjust X and Y value from 0 to give room for the textbox
    bpmDial.setBounds(getWidth()-(150+80), 35, 150, 100); 
    onOrOff.setBounds(80,35,150,100);

}
