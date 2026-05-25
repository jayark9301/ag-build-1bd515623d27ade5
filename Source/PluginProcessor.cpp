#include "PluginProcessor.h"
#include "PluginEditor.h"
VelvetAudioProcessor::VelvetAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input",juce::AudioChannelSet::stereo()).withOutput("Output",juce::AudioChannelSet::stereo())),
      apvts(*this,nullptr,"Parameters",createParameterLayout()) {}
VelvetAudioProcessor::~VelvetAudioProcessor() {}
juce::AudioProcessorValueTreeState::ParameterLayout VelvetAudioProcessor::createParameterLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("INPUT_GAIN","Input Gain",juce::NormalisableRange<float>(-24.0f,24.0f,0.01f),0.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("OUTPUT_GAIN","Output Gain",juce::NormalisableRange<float>(-24.0f,24.0f,0.01f),0.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_DELAY_MS_6J0N","Delay Time",juce::NormalisableRange<float>(1.0f,2000.0f,0.01f),250.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_FEEDBACK_6J0N","Delay Feedback",juce::NormalisableRange<float>(0.0f,95.0f,0.01f),40.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_MIX_6J0N","Delay Mix",juce::NormalisableRange<float>(0.0f,100.0f,0.01f),30.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("GAIN_GAIN_DB_6TF3","Gain Gain",juce::NormalisableRange<float>(-24.0f,24.0f,0.01f),0.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_THRESHOLD_7R4Q","Compressor Threshold",juce::NormalisableRange<float>(-60.0f,0.0f,0.01f),-18.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_RATIO_7R4Q","Compressor Ratio",juce::NormalisableRange<float>(1.0f,20.0f,0.1f),4.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_ATTACK_7R4Q","Compressor Attack",juce::NormalisableRange<float>(0.1f,200.0f,0.01f),10.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_RELEASE_7R4Q","Compressor Release",juce::NormalisableRange<float>(10.0f,2000.0f,0.01f),150.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_MAKEUP_7R4Q","Compressor Makeup",juce::NormalisableRange<float>(0.0f,24.0f,0.01f),0.0f));
    return layout;
}
void VelvetAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    currentSampleRate = sampleRate;
    juce::dsp::ProcessSpec spec;
    spec.sampleRate=(uint32_t)sampleRate; spec.maximumBlockSize=(uint32_t)samplesPerBlock; spec.numChannels=(uint32_t)getTotalNumOutputChannels();
    inputGainDsp.prepare(spec); inputGainDsp.setGainDecibels(0.0f);
    outputGainDsp.prepare(spec); outputGainDsp.setGainDecibels(0.0f);
    delay_6J0N.prepare(spec); delay_6J0N.setMaximumDelayInSamples((int)(spec.sampleRate*2.0)); delayMix_6J0N.prepare(spec); delayMix_6J0N.setWetMixProportion(0.3f);
    gain_6TF3.prepare(spec); gain_6TF3.setGainDecibels(0.0f);
    comp_7R4Q.prepare(spec); comp_7R4Q.setThreshold(-18.0f); comp_7R4Q.setRatio(4.0f); comp_7R4Q.setAttack(10.0f); comp_7R4Q.setRelease(150.0f); compMakeup_7R4Q.prepare(spec); compMakeup_7R4Q.setGainDecibels(0.0f);
}
void VelvetAudioProcessor::releaseResources() {}
bool VelvetAudioProcessor::isBusesLayoutSupported(const BusesLayout& l) const {
    return l.getMainOutputChannelSet()==juce::AudioChannelSet::stereo()&&l.getMainInputChannelSet()==juce::AudioChannelSet::stereo();
}
void VelvetAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    { const int ns=buffer.getNumSamples(),nc=buffer.getNumChannels(); float pkL=0,pkR=0; for(int i=0;i<ns;++i){ pkL=std::max(pkL,std::abs(buffer.getSample(0,i))); if(nc>1) pkR=std::max(pkR,std::abs(buffer.getSample(1,i))); } inputLevelL.store(pkL,std::memory_order_relaxed); inputLevelR.store(nc>1?pkR:pkL,std::memory_order_relaxed); }
    inputGainDsp.setGainDecibels(*apvts.getRawParameterValue("INPUT_GAIN")); inputGainDsp.process(context);
    { delay_6J0N.setDelay((float)(*apvts.getRawParameterValue("DELAY_DELAY_MS_6J0N")*currentSampleRate/1000.0)); delayMix_6J0N.setWetMixProportion(*apvts.getRawParameterValue("DELAY_MIX_6J0N")/100.0f); delayMix_6J0N.pushDrySamples(block); delay_6J0N.process(context); delayMix_6J0N.mixWetSamples(block); }
    gain_6TF3.setGainDecibels(*apvts.getRawParameterValue("GAIN_GAIN_DB_6TF3")); gain_6TF3.process(context);
    comp_7R4Q.setThreshold(*apvts.getRawParameterValue("COMPRESSOR_THRESHOLD_7R4Q")); comp_7R4Q.setRatio(*apvts.getRawParameterValue("COMPRESSOR_RATIO_7R4Q")); comp_7R4Q.setAttack(*apvts.getRawParameterValue("COMPRESSOR_ATTACK_7R4Q")); comp_7R4Q.setRelease(*apvts.getRawParameterValue("COMPRESSOR_RELEASE_7R4Q")); compMakeup_7R4Q.setGainDecibels(*apvts.getRawParameterValue("COMPRESSOR_MAKEUP_7R4Q")); comp_7R4Q.process(context); compMakeup_7R4Q.process(context);
    outputGainDsp.setGainDecibels(*apvts.getRawParameterValue("OUTPUT_GAIN")); outputGainDsp.process(context);
    { const int ns=buffer.getNumSamples(),nc=buffer.getNumChannels(); float pkL=0,pkR=0; for(int i=0;i<ns;++i){ pkL=std::max(pkL,std::abs(buffer.getSample(0,i))); if(nc>1) pkR=std::max(pkR,std::abs(buffer.getSample(1,i))); } outputLevelL.store(pkL,std::memory_order_relaxed); outputLevelR.store(nc>1?pkR:pkL,std::memory_order_relaxed); }
}
void VelvetAudioProcessor::getStateInformation(juce::MemoryBlock& d) {
    auto s=apvts.copyState(); std::unique_ptr<juce::XmlElement> xml(s.createXml()); copyXmlToBinary(*xml,d);
}
void VelvetAudioProcessor::setStateInformation(const void* d,int sz) {
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(d,sz));
    if(xml&&xml->hasTagName(apvts.state.getType())) apvts.replaceState(juce::ValueTree::fromXml(*xml));
}
juce::AudioProcessorEditor* VelvetAudioProcessor::createEditor() { return new VelvetAudioProcessorEditor(*this); }
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new VelvetAudioProcessor(); }
