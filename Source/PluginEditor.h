#pragma once
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
class VelvetAudioProcessorEditor : public juce::AudioProcessorEditor,
                                   private juce::Timer {
public:
    VelvetAudioProcessorEditor(VelvetAudioProcessor&);
    ~VelvetAudioProcessorEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
    void mouseDown(const juce::MouseEvent&) override;
private:
    void timerCallback() override;
    VelvetAudioProcessor& processorRef;
    VelvetLookAndFeel lnf;
    juce::Slider knob_DELAY_DELAY_MS_6J0N;
    juce::Label lbl_DELAY_DELAY_MS_6J0N;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_DELAY_MS_6J0N;
    juce::Slider knob_DELAY_FEEDBACK_6J0N;
    juce::Label lbl_DELAY_FEEDBACK_6J0N;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_FEEDBACK_6J0N;
    juce::Slider knob_DELAY_MIX_6J0N;
    juce::Label lbl_DELAY_MIX_6J0N;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_MIX_6J0N;
    juce::Slider knob_GAIN_GAIN_DB_6TF3;
    juce::Label lbl_GAIN_GAIN_DB_6TF3;
    juce::AudioProcessorValueTreeState::SliderAttachment att_GAIN_GAIN_DB_6TF3;
    juce::Slider knob_COMPRESSOR_THRESHOLD_7R4Q;
    juce::Label lbl_COMPRESSOR_THRESHOLD_7R4Q;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_THRESHOLD_7R4Q;
    juce::Slider knob_COMPRESSOR_RATIO_7R4Q;
    juce::Label lbl_COMPRESSOR_RATIO_7R4Q;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_RATIO_7R4Q;
    juce::Slider knob_COMPRESSOR_ATTACK_7R4Q;
    juce::Label lbl_COMPRESSOR_ATTACK_7R4Q;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_ATTACK_7R4Q;
    juce::Slider knob_COMPRESSOR_RELEASE_7R4Q;
    juce::Label lbl_COMPRESSOR_RELEASE_7R4Q;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_RELEASE_7R4Q;
    juce::Slider knob_COMPRESSOR_MAKEUP_7R4Q;
    juce::Label lbl_COMPRESSOR_MAKEUP_7R4Q;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_MAKEUP_7R4Q;
    juce::Slider knob_INPUT_GAIN;
    juce::Label lbl_INPUT_GAIN;
    juce::AudioProcessorValueTreeState::SliderAttachment att_INPUT_GAIN;
    juce::Slider knob_OUTPUT_GAIN;
    juce::Label lbl_OUTPUT_GAIN;
    juce::AudioProcessorValueTreeState::SliderAttachment att_OUTPUT_GAIN;
    float inLvlL=0,inLvlR=0,outLvlL=0,outLvlR=0;
    bool clipLed=false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VelvetAudioProcessorEditor)
};
