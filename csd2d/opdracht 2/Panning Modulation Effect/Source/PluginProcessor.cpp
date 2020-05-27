/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"


//==============================================================================
WizardAudioProcessor::WizardAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    addParameter(pmAmount = new AudioParameterFloat("pmAmount", "Panning Mod Amount", 0.0f, 10.0f, 0.5f)); //min max default floats
    addParameter(milliseconds = new AudioParameterFloat("milliseconds", "Panning Speed", 0.0f, 20.0f, 0.5f));
    addParameter(gain = new AudioParameterFloat("gain", "Gain", 0.0f, 1.0f, 0.5f));
    
}

WizardAudioProcessor::~WizardAudioProcessor()
{
}

//==============================================================================
const String WizardAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WizardAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WizardAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WizardAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WizardAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WizardAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WizardAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WizardAudioProcessor::setCurrentProgram (int index)
{
}

const String WizardAudioProcessor::getProgramName (int index)
{
    return {};
}

void WizardAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WizardAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void WizardAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WizardAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void WizardAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    //Assign a variable channeldata as the write pointer of the audio buffer
    auto* channeldataL = buffer.getWritePointer(0); // 0 = L
    auto* channeldataR = buffer.getWritePointer(1); // 1 = R

    float mSeconds = milliseconds->get() / 1000;
    
    int numberSamples = getSampleRate() * mSeconds;
    const float radsPerSample = (2 * double_Pi) / numberSamples; // 1 cycle is 2*pi radians

    float pmaSliderValue = pmAmount->get();
    float gainValue = gain->get();

    for (int i = 0; i < buffer.getNumSamples(); i++) 
    {
        auto inputL = channeldataL[i]; 
        auto inputR = channeldataR[i]; 

        float sinValue = std::sin(nextRad) + 1;
        sinValue = ((sinValue * double_Pi) / 4) * pmaSliderValue;
        inputL = inputL * cos(sinValue) * gainValue ; // cos instead of sin so that they invert smoothly
        inputR = inputR * sin(sinValue) * gainValue ; 

        channeldataL[i] = inputL; // writing input tot channel data
        channeldataR[i] = inputR; 

        nextRad += radsPerSample;
    }
    if (nextRad > numberSamples)
    {
        nextRad = 0; // to reset the nextRad variable
    }
}

//==============================================================================
bool WizardAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WizardAudioProcessor::createEditor()
{
   // return new WizardAudioProcessorEditor (*this);
    return new GenericAudioProcessorEditor(this); // no need for two extra files
}

//==============================================================================
void WizardAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WizardAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WizardAudioProcessor();
}
