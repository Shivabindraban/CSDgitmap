#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 900);
    // Setting up Looks
    getLookAndFeel().setColour(Slider::thumbColourId, Colours::dimgrey);
    getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::darkkhaki);

    // Setting up all the components
    addAndMakeVisible(headerBlock);
    addAndMakeVisible(beatBlock);
    addAndMakeVisible(filterBlock);
    addAndMakeVisible(arpBlock);
    addAndMakeVisible(masterVolBlock);
     
}
MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);

    // Making Block Grids or separations
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

            
    g.setFont (Font (50.0f));
    g.setColour (Colours::darkkhaki);
    g.drawText ("ArpTool (Live)", 330,70,300,50, Justification::centredTop, true);
   
    g.setFont(Font(25.0f));
    g.setColour(Colours::darkkhaki);
    g.drawText("Beat Settings", 350, 150 ,200,100, Justification::centred, true);
    g.drawText("Arp Settings", 210, 365, 200, 100, Justification::centredTop, true);
    g.drawText("Filter Settings", 650, 365, 200, 100, Justification::centredTop, true);
    g.drawText("Volume Settings", 600, 545, 300, 100, Justification::centredTop, true);

    g.setFont(Font(15.0f));
    g.setColour(Colours::antiquewhite);

    g.drawText("Current Time", 729,252,100,100, Justification::centredTop, true);
    g.drawText("Kick Pattern", 728, 273, 100, 100, Justification::centredTop, true);
    g.drawText("Clap Pattern", 729, 293, 100, 100, Justification::centredTop, true);
    g.drawText("Hihats Pattern", 728, 313, 110, 100, Justification::centredTop, true);

}

void MainComponent::resized() 
{
    // Blocksizes and placement
    headerBlock.setBounds(      0                     , 0                           , getWidth()            , getHeight() / 5);
    beatBlock.setBounds(        0                     , ((getHeight() / 5) * 1) + 50, getWidth()            , getHeight() / 5);
    arpBlock.setBounds(         0                     , ((getHeight() / 5) * 2) + 50, (getWidth() / 3)*2    , getHeight() / 5);

    filterBlock.setBounds(      (getWidth() / 3) * 2  , ((getHeight() / 5) * 2) + 50, getWidth() / 3        , getHeight() / 5);
    masterVolBlock.setBounds(   (getWidth() / 3) * 2  , ((getHeight() / 5) * 3)     , getWidth() / 3        , getHeight() / 5);
    
}
