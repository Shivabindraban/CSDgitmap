#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 900);


    bpmDial.setSliderStyle(Slider::SliderStyle::Rotary);
    bpmDial.setTextBoxStyle(Slider::TextBoxRight, false, 50,20);
    
    arpSpeed.setSliderStyle(Slider::SliderStyle::Rotary);
    arpSpeed.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    keyScale.setSliderStyle(Slider::SliderStyle::Rotary);
    keyScale.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    jumpSize.setSliderStyle(Slider::SliderStyle::Rotary);
    jumpSize.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    tonalRange.setSliderStyle(Slider::SliderStyle::Rotary);
    tonalRange.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    setRhythm.setSliderStyle(Slider::SliderStyle::Rotary);
    setRhythm.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

    addAndMakeVisible(bpmDial);

    addAndMakeVisible(arpSpeed);
    addAndMakeVisible(keyScale);
    addAndMakeVisible(jumpSize);
    addAndMakeVisible(tonalRange);
    addAndMakeVisible(setRhythm);


    
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
    
    Rectangle<int> area = getLocalBounds();// Rect is windowSize
    Rectangle<int> headerArea = area.removeFromTop(area.getHeight() / 6); // For On/Of, BPM dial and name

    bpmDial.setBounds(headerArea.removeFromLeft(area.getWidth()/2));

    arpSpeed.setBounds(area.removeFromLeft(area.getWidth() / 2));
    keyScale.setBounds(area.removeFromLeft(area.getWidth() / 2));
    jumpSize.setBounds(area.removeFromLeft(area.getWidth() / 2));
    tonalRange.setBounds(area.removeFromLeft(area.getWidth() / 2));
    setRhythm.setBounds(area.removeFromLeft(area.getWidth() / 2));


    
}
