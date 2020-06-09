#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 900);

    getLookAndFeel().setColour(Slider::thumbColourId, Colours::dimgrey);
    getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::darkkhaki);


    addAndMakeVisible(headerBlock);
    addAndMakeVisible(filterBlock);

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

    
    g.setColour(Colours::black);
    g.drawRect(0, 0                    , getWidth()          , (getHeight() / 5) * 1, 2.0); // HeaderBlock
    g.drawRect(0, (getHeight() / 5) * 1, getWidth()          , (getHeight() / 5) * 1, 2.0); // BeatBlock
    g.drawRect(0, (getHeight() / 5) * 2, (getWidth() / 3) * 2, (getHeight() / 5) * 2, 2.0); // ArpBlock

    g.drawRect((getWidth() / 3) * 2, (getHeight() / 5) * 2, (getWidth() / 3) * 1, (getHeight() / 5) * 1, 2.0); // Filter
    g.drawRect((getWidth() / 3) * 2, (getHeight() / 5) * 3, (getWidth() / 3) * 1, (getHeight() / 5) * 1, 2.0); // MasterVolume





  

    g.setFont (Font (40.0f));
    g.setColour (Colours::darkkhaki);
    g.drawText ("ArpTool (Live)", getLocalBounds(), Justification::centredTop, true);
}

void MainComponent::resized() 
{
    // Blocksizes and placement
    headerBlock.setBounds(0, 0, getWidth(), getHeight()/7);
    filterBlock.setBounds(0, getHeight()/4, getWidth(), 200);
    
}
