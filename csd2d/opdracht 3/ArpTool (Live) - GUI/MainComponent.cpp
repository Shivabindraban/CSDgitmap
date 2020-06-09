#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 900);

    getLookAndFeel().setColour(Slider::thumbColourId, Colours::dimgrey);
    getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::darkkhaki);


    addAndMakeVisible(headerBlock);

    arpSpeed.setRange(1, 8, 1);
    arpSpeed.setSliderStyle(Slider::SliderStyle::Rotary);
    arpSpeed.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

    jumpSize.setRange(1, 7, 1);
    jumpSize.setSliderStyle(Slider::SliderStyle::Rotary);
    jumpSize.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

    tonalRange.setRange(1, 8, 1);
    tonalRange.setSliderStyle(Slider::SliderStyle::Rotary);
    tonalRange.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

    /*

    // TODO = make dropdown menu
    keyScale.setSliderStyle(Slider::SliderStyle::Rotary);
    keyScale.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);



    // TODO = make dropdown menu
    setRhythm.setSliderStyle(Slider::SliderStyle::Rotary);
    setRhythm.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

    */


    addAndMakeVisible(arpSpeed);

    addAndMakeVisible(jumpSize);
    addAndMakeVisible(tonalRange);



    
}
MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::bisque);
    Rectangle<int> totalArea = getLocalBounds();// Rect is windowSize
    Rectangle<int> headerSectionArea = totalArea.removeFromTop(totalArea.getHeight()/6) ;// Rect is windowSize
    Rectangle<int> keyBoardSectionArea = totalArea.removeFromBottom(totalArea.getHeight()/6);

    g.setColour(Colours::black);
    g.drawRect(headerSectionArea);
    g.drawRect(keyBoardSectionArea);
    







    g.setFont (Font (40.0f));
    g.setColour (Colours::darkkhaki);
    g.drawText ("ArpTool (Live)", getLocalBounds(), Justification::centredTop, true);
}

void MainComponent::resized() 
{
    headerBlock.setBounds(0, 0, getWidth(), 200);
    
}
