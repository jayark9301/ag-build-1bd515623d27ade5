#pragma once
#include <JuceHeader.h>
class VelvetAudioProcessor : public juce::AudioProcessor {
public:
    VelvetAudioProcessor();
    ~VelvetAudioProcessor() override;
    void prepareToPlay(double, int) override;
    void releaseResources() override;
    bool isBusesLayoutSupported(const BusesLayout&) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return "Velvet"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 2.0; }
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;
    juce::AudioProcessorValueTreeState apvts;
private:
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    double currentSampleRate = 44100.0;
    juce::dsp::DelayLine<float,juce::dsp::DelayLineInterpolationTypes::Lagrange3rd> delay_6J0N { 96000 };
    juce::dsp::DryWetMixer<float> delayMix_6J0N;
    juce::dsp::Gain<float> gain_6TF3;
    juce::dsp::Compressor<float> comp_7R4Q;
    juce::dsp::Gain<float> compMakeup_7R4Q;
    juce::dsp::Gain<float> inputGainDsp, outputGainDsp;
    std::atomic<float> inputLevelL{0}, inputLevelR{0}, outputLevelL{0}, outputLevelR{0};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VelvetAudioProcessor)
};
