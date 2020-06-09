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
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

HeaderComponent::~HeaderComponent()
{
}

void HeaderComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("HeaderComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void HeaderComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
