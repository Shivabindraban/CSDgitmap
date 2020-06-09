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

    //Mock Grid
    boxWidth = 30;
    boxHeight = 20;
    Rectangle<int>rectArea(250, 40, boxWidth, boxHeight);
    for (int i = 0; i < 3; i++) {
        g.setColour(Colours::antiquewhite);
        g.fillRect(rectArea);
        rectArea.translate(boxWidth, boxHeight); // Placing diagonal
    }

    for (int i = 0; i < 16; i++) {
        g.drawRect(250 + (boxWidth * i), boxHeight*1, boxWidth, boxHeight);
        g.drawRect(250 + (boxWidth * i), boxHeight*2, boxWidth, boxHeight);
        g.drawRect(250 + (boxWidth * i), boxHeight*3, boxWidth, boxHeight);
        g.drawRect(250 + (boxWidth * i), boxHeight*4, boxWidth, boxHeight);
    }

    Rectangle<int>currentArea(250 + 60, 20, boxWidth, boxHeight);
    g.setColour(Colours::black);
    g.fillRect(currentArea);
}

void BeatComponent::resized()
{
    beatChooseDropDown.setBounds(80, 35, 100, 20);

}
