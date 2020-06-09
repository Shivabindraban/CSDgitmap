#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 900);

    getLookAndFeel().setColour(Slider::thumbColourId, Colours::dimgrey);
    getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::darkkhaki);


    addAndMakeVisible(headerBlock);
    addAndMakeVisible(filterBlock);
    addAndMakeVisible(arpBlock);
    addAndMakeVisible(masterVolBlock);


    /*

    // TODO = make dropdown menu
    keyScale.setSliderStyle(Slider::SliderStyle::Rotary);
    keyScale.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);



    // TODO = make dropdown menu
    setRhythm.setSliderStyle(Slider::SliderStyle::Rotary);
    setRhythm.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

    */


    
}
MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::darkgrey);

    
    g.setColour(Colours::black); // Block Grid Colour
    // HeaderBlock Grid
    g.drawRect(0                    , 0                    , getWidth()          , (getHeight() / 5) * 1, 2.0); 
    // BeatBlock Grid
    g.drawRect(0                    , (getHeight() / 5) * 1, getWidth()          , (getHeight() / 5) * 1, 2.0);
    // ArpBlock Grid
    g.drawRect(0                    , (getHeight() / 5) * 2, (getWidth() / 3) * 2, (getHeight() / 5) * 2, 2.0); 
    // FilterBlock Grid
    g.drawRect((getWidth() / 3) * 2 , (getHeight() / 5) * 2, (getWidth() / 3) * 1, (getHeight() / 5) * 1, 2.0); 
    // MasterVolumeBlock Grid
    g.drawRect((getWidth() / 3) * 2 , (getHeight() / 5) * 3, (getWidth() / 3) * 1, (getHeight() / 5) * 1, 2.0); 





  

    g.setFont (Font (40.0f));
    g.setColour (Colours::darkgrey);
    g.drawText ("ArpTool (Live)", getLocalBounds(), Justification::centredTop, true);
}

void MainComponent::resized() 
{
    // Blocksizes and placement
    headerBlock.setBounds(  0                     , 0                           , getWidth()    , getHeight() / 5);
    
    arpBlock.setBounds(     0                     , ((getHeight() / 5) * 2) + 50, (getWidth() / 3)*2, getHeight() / 5);

    filterBlock.setBounds((getWidth() / 3) * 2, ((getHeight() / 5) * 2) + 50, getWidth() / 3, getHeight() / 5);
    masterVolBlock.setBounds((getWidth() / 3) * 2, ((getHeight() / 5) * 3)  , getWidth() / 3, getHeight() / 5);
    
}
