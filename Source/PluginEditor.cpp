#include "PluginEditor.h"
VelvetAudioProcessorEditor::VelvetAudioProcessorEditor(VelvetAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p),
      att_DELAY_DELAY_MS_6J0N(processorRef.apvts,"DELAY_DELAY_MS_6J0N",knob_DELAY_DELAY_MS_6J0N),
      att_DELAY_FEEDBACK_6J0N(processorRef.apvts,"DELAY_FEEDBACK_6J0N",knob_DELAY_FEEDBACK_6J0N),
      att_DELAY_MIX_6J0N(processorRef.apvts,"DELAY_MIX_6J0N",knob_DELAY_MIX_6J0N),
      att_GAIN_GAIN_DB_6TF3(processorRef.apvts,"GAIN_GAIN_DB_6TF3",knob_GAIN_GAIN_DB_6TF3),
      att_COMPRESSOR_THRESHOLD_7R4Q(processorRef.apvts,"COMPRESSOR_THRESHOLD_7R4Q",knob_COMPRESSOR_THRESHOLD_7R4Q),
      att_COMPRESSOR_RATIO_7R4Q(processorRef.apvts,"COMPRESSOR_RATIO_7R4Q",knob_COMPRESSOR_RATIO_7R4Q),
      att_COMPRESSOR_ATTACK_7R4Q(processorRef.apvts,"COMPRESSOR_ATTACK_7R4Q",knob_COMPRESSOR_ATTACK_7R4Q),
      att_COMPRESSOR_RELEASE_7R4Q(processorRef.apvts,"COMPRESSOR_RELEASE_7R4Q",knob_COMPRESSOR_RELEASE_7R4Q),
      att_COMPRESSOR_MAKEUP_7R4Q(processorRef.apvts,"COMPRESSOR_MAKEUP_7R4Q",knob_COMPRESSOR_MAKEUP_7R4Q),
      att_INPUT_GAIN(processorRef.apvts,"INPUT_GAIN",knob_INPUT_GAIN),
      att_OUTPUT_GAIN(processorRef.apvts,"OUTPUT_GAIN",knob_OUTPUT_GAIN)
{
    setLookAndFeel(&lnf); setSize(750,450); startTimerHz(30);
    knob_DELAY_DELAY_MS_6J0N.setSliderStyle(juce::Slider::Rotary); knob_DELAY_DELAY_MS_6J0N.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_DELAY_DELAY_MS_6J0N.setLookAndFeel(&lnf); knob_DELAY_DELAY_MS_6J0N.setDoubleClickReturnValue(true,250.0f); addAndMakeVisible(knob_DELAY_DELAY_MS_6J0N); lbl_DELAY_DELAY_MS_6J0N.setText("Delay Time",juce::dontSendNotification); lbl_DELAY_DELAY_MS_6J0N.setJustificationType(juce::Justification::centred); lbl_DELAY_DELAY_MS_6J0N.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_DELAY_MS_6J0N);
    knob_DELAY_FEEDBACK_6J0N.setSliderStyle(juce::Slider::Rotary); knob_DELAY_FEEDBACK_6J0N.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_DELAY_FEEDBACK_6J0N.setLookAndFeel(&lnf); knob_DELAY_FEEDBACK_6J0N.setDoubleClickReturnValue(true,40.0f); addAndMakeVisible(knob_DELAY_FEEDBACK_6J0N); lbl_DELAY_FEEDBACK_6J0N.setText("Delay Feedback",juce::dontSendNotification); lbl_DELAY_FEEDBACK_6J0N.setJustificationType(juce::Justification::centred); lbl_DELAY_FEEDBACK_6J0N.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_FEEDBACK_6J0N);
    knob_DELAY_MIX_6J0N.setSliderStyle(juce::Slider::Rotary); knob_DELAY_MIX_6J0N.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_DELAY_MIX_6J0N.setLookAndFeel(&lnf); knob_DELAY_MIX_6J0N.setDoubleClickReturnValue(true,30.0f); addAndMakeVisible(knob_DELAY_MIX_6J0N); lbl_DELAY_MIX_6J0N.setText("Delay Mix",juce::dontSendNotification); lbl_DELAY_MIX_6J0N.setJustificationType(juce::Justification::centred); lbl_DELAY_MIX_6J0N.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_MIX_6J0N);
    knob_GAIN_GAIN_DB_6TF3.setSliderStyle(juce::Slider::Rotary); knob_GAIN_GAIN_DB_6TF3.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_GAIN_GAIN_DB_6TF3.setLookAndFeel(&lnf); knob_GAIN_GAIN_DB_6TF3.setDoubleClickReturnValue(true,0.0f); addAndMakeVisible(knob_GAIN_GAIN_DB_6TF3); lbl_GAIN_GAIN_DB_6TF3.setText("Gain Gain",juce::dontSendNotification); lbl_GAIN_GAIN_DB_6TF3.setJustificationType(juce::Justification::centred); lbl_GAIN_GAIN_DB_6TF3.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_GAIN_GAIN_DB_6TF3);
    knob_COMPRESSOR_THRESHOLD_7R4Q.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_THRESHOLD_7R4Q.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_COMPRESSOR_THRESHOLD_7R4Q.setLookAndFeel(&lnf); knob_COMPRESSOR_THRESHOLD_7R4Q.setDoubleClickReturnValue(true,-18.0f); addAndMakeVisible(knob_COMPRESSOR_THRESHOLD_7R4Q); lbl_COMPRESSOR_THRESHOLD_7R4Q.setText("Compressor Threshold",juce::dontSendNotification); lbl_COMPRESSOR_THRESHOLD_7R4Q.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_THRESHOLD_7R4Q.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_THRESHOLD_7R4Q);
    knob_COMPRESSOR_RATIO_7R4Q.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_RATIO_7R4Q.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_COMPRESSOR_RATIO_7R4Q.setLookAndFeel(&lnf); knob_COMPRESSOR_RATIO_7R4Q.setDoubleClickReturnValue(true,4.0f); addAndMakeVisible(knob_COMPRESSOR_RATIO_7R4Q); lbl_COMPRESSOR_RATIO_7R4Q.setText("Compressor Ratio",juce::dontSendNotification); lbl_COMPRESSOR_RATIO_7R4Q.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_RATIO_7R4Q.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_RATIO_7R4Q);
    knob_COMPRESSOR_ATTACK_7R4Q.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_ATTACK_7R4Q.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_COMPRESSOR_ATTACK_7R4Q.setLookAndFeel(&lnf); knob_COMPRESSOR_ATTACK_7R4Q.setDoubleClickReturnValue(true,10.0f); addAndMakeVisible(knob_COMPRESSOR_ATTACK_7R4Q); lbl_COMPRESSOR_ATTACK_7R4Q.setText("Compressor Attack",juce::dontSendNotification); lbl_COMPRESSOR_ATTACK_7R4Q.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_ATTACK_7R4Q.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_ATTACK_7R4Q);
    knob_COMPRESSOR_RELEASE_7R4Q.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_RELEASE_7R4Q.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_COMPRESSOR_RELEASE_7R4Q.setLookAndFeel(&lnf); knob_COMPRESSOR_RELEASE_7R4Q.setDoubleClickReturnValue(true,150.0f); addAndMakeVisible(knob_COMPRESSOR_RELEASE_7R4Q); lbl_COMPRESSOR_RELEASE_7R4Q.setText("Compressor Release",juce::dontSendNotification); lbl_COMPRESSOR_RELEASE_7R4Q.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_RELEASE_7R4Q.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_RELEASE_7R4Q);
    knob_COMPRESSOR_MAKEUP_7R4Q.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_MAKEUP_7R4Q.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_COMPRESSOR_MAKEUP_7R4Q.setLookAndFeel(&lnf); knob_COMPRESSOR_MAKEUP_7R4Q.setDoubleClickReturnValue(true,0.0f); addAndMakeVisible(knob_COMPRESSOR_MAKEUP_7R4Q); lbl_COMPRESSOR_MAKEUP_7R4Q.setText("Compressor Makeup",juce::dontSendNotification); lbl_COMPRESSOR_MAKEUP_7R4Q.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_MAKEUP_7R4Q.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),10.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_MAKEUP_7R4Q);
    knob_INPUT_GAIN.setSliderStyle(juce::Slider::Rotary); knob_INPUT_GAIN.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_INPUT_GAIN.setLookAndFeel(&lnf); knob_INPUT_GAIN.setDoubleClickReturnValue(true,0.0); addAndMakeVisible(knob_INPUT_GAIN); lbl_INPUT_GAIN.setText("INPUT",juce::dontSendNotification); lbl_INPUT_GAIN.setJustificationType(juce::Justification::centred); lbl_INPUT_GAIN.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold)); addAndMakeVisible(lbl_INPUT_GAIN);
    knob_OUTPUT_GAIN.setSliderStyle(juce::Slider::Rotary); knob_OUTPUT_GAIN.setTextBoxStyle(juce::Slider::TextBoxBelow,false,88,14); knob_OUTPUT_GAIN.setLookAndFeel(&lnf); knob_OUTPUT_GAIN.setDoubleClickReturnValue(true,0.0); addAndMakeVisible(knob_OUTPUT_GAIN); lbl_OUTPUT_GAIN.setText("OUTPUT",juce::dontSendNotification); lbl_OUTPUT_GAIN.setJustificationType(juce::Justification::centred); lbl_OUTPUT_GAIN.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold)); addAndMakeVisible(lbl_OUTPUT_GAIN);
}
VelvetAudioProcessorEditor::~VelvetAudioProcessorEditor() { stopTimer(); setLookAndFeel(nullptr); }
void VelvetAudioProcessorEditor::timerCallback() {
    float rIL=processorRef.inputLevelL.load(std::memory_order_relaxed);
    float rIR=processorRef.inputLevelR.load(std::memory_order_relaxed);
    float rOL=processorRef.outputLevelL.load(std::memory_order_relaxed);
    float rOR=processorRef.outputLevelR.load(std::memory_order_relaxed);
    inLvlL=std::max(rIL,inLvlL*0.88f); inLvlR=std::max(rIR,inLvlR*0.88f);
    outLvlL=std::max(rOL,outLvlL*0.88f); outLvlR=std::max(rOR,outLvlR*0.88f);
    if(rOL>=1.0f||rOR>=1.0f) clipLed=true;
    repaint();
}
void VelvetAudioProcessorEditor::mouseDown(const juce::MouseEvent& e) {
    if(clipLed&&std::abs(e.x-680)<9&&std::abs(e.y-52)<9){clipLed=false;repaint();}
}
void VelvetAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colour(0xff1a0f08));
    g.setColour(juce::Colour(0xff2a1a10).withAlpha(0.55f));
    g.fillRect(0,44,140,378);
    g.fillRect(610,44,140,378);
    g.setColour(juce::Colour(0xfffb923c).withAlpha(0.18f));
    g.fillRect(140,44,1,378);
    g.fillRect(609,44,1,378);
    g.setColour(juce::Colour(0xff2a1a10)); g.fillRect(0,0,750,44);
    g.setColour(juce::Colour(0xfffb923c).withAlpha(0.3f)); g.fillRect(0,43,750,1);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.5f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold));
    g.drawText("ARCHERGATE",16,4,750-32,14,juce::Justification::left);
    g.setColour(juce::Colour(0xfffb923c)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),14.f,juce::Font::bold));
    g.drawText("VELVET",16,18,750-32,20,juce::Justification::centred);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.35f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),8.5f,juce::Font::bold));
    g.drawText("IN",0,50,140,12,juce::Justification::centred);
    g.drawText("OUT",610,50,140,12,juce::Justification::centred);
    g.setColour(juce::Colour(0xff2a1a10)); g.fillRect(0,422,750,28);
    g.setColour(juce::Colour(0xfffb923c).withAlpha(0.15f)); g.fillRect(0,422,750,1);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.4f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),8.5f,juce::Font::plain));
    g.drawText("ARCHERGATE",10,430,120,12,juce::Justification::left);
    g.drawText("v1.0.0",698,430,44,12,juce::Justification::right);
    g.setColour(juce::Colour(0xff2a1a10)); g.fillRect(140,50,470,20);    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.6f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold));    g.drawText("DELAY",150,50,450,20,juce::Justification::centredLeft,false);
    g.setColour(juce::Colour(0xff2a1a10)); g.fillRect(140,174,470,20);    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.6f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold));    g.drawText("GAIN",150,174,450,20,juce::Justification::centredLeft,false);
    g.setColour(juce::Colour(0xff2a1a10)); g.fillRect(140,298,470,20);    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.6f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold));    g.drawText("COMPRESSOR",150,298,450,20,juce::Justification::centredLeft,false);
    auto drawMeter=[&](int mx,float lvlL,float lvlR){
        const int mH=150;
        g.setColour(juce::Colour(0xff111111)); g.fillRect(mx,262,10,mH); g.fillRect(mx+14,262,10,mH);
        g.setColour(juce::Colour(0x18ffffff)); g.drawRect(mx,262,10,mH,1); g.drawRect(mx+14,262,10,mH,1);
        auto drawBar=[&](int bx,float lv){
            if(lv<0.0001f) return;
            int fh=juce::jlimit(0,mH,(int)(mH*(juce::Decibels::gainToDecibels(lv)+60.0f)/63.0f));
            float fr=(float)fh/mH;
            juce::Colour c=fr<0.65f?juce::Colour(0xff33bb44):fr<0.85f?juce::Colour(0xffffcc00):juce::Colour(0xffff3333);
            g.setColour(c.withAlpha(0.9f)); g.fillRect(bx,262+mH-fh,10,fh);
        };
        drawBar(mx,lvlL); drawBar(mx+14,lvlR);
    };
    drawMeter(58,inLvlL,inLvlR);
    drawMeter(668,outLvlL,outLvlR);
    g.setColour(clipLed?juce::Colour(0xffff2222):juce::Colour(0xff441111));
    g.fillEllipse(680-4.5f,52-4.5f,9.0f,9.0f);
    if(clipLed){ g.setColour(juce::Colour(0xffff8888).withAlpha(0.6f)); g.fillEllipse(680-2.5f,52-2.5f,5.0f,5.0f); }
}
void VelvetAudioProcessorEditor::resized() {
    knob_INPUT_GAIN.setBounds(24,170,92,70); lbl_INPUT_GAIN.setBounds(24,240,92,14);
    knob_OUTPUT_GAIN.setBounds(634,170,92,70); lbl_OUTPUT_GAIN.setBounds(634,240,92,14);
    knob_DELAY_DELAY_MS_6J0N.setBounds(237,74,92,70); lbl_DELAY_DELAY_MS_6J0N.setBounds(237,144,92,14);
    knob_DELAY_FEEDBACK_6J0N.setBounds(329,74,92,70); lbl_DELAY_FEEDBACK_6J0N.setBounds(329,144,92,14);
    knob_DELAY_MIX_6J0N.setBounds(421,74,92,70); lbl_DELAY_MIX_6J0N.setBounds(421,144,92,14);
    knob_GAIN_GAIN_DB_6TF3.setBounds(329,198,92,70); lbl_GAIN_GAIN_DB_6TF3.setBounds(329,268,92,14);
    knob_COMPRESSOR_THRESHOLD_7R4Q.setBounds(191,322,92,70); lbl_COMPRESSOR_THRESHOLD_7R4Q.setBounds(191,392,92,14);
    knob_COMPRESSOR_RATIO_7R4Q.setBounds(283,322,92,70); lbl_COMPRESSOR_RATIO_7R4Q.setBounds(283,392,92,14);
    knob_COMPRESSOR_ATTACK_7R4Q.setBounds(375,322,92,70); lbl_COMPRESSOR_ATTACK_7R4Q.setBounds(375,392,92,14);
    knob_COMPRESSOR_RELEASE_7R4Q.setBounds(467,322,92,70); lbl_COMPRESSOR_RELEASE_7R4Q.setBounds(467,392,92,14);
    knob_COMPRESSOR_MAKEUP_7R4Q.setBounds(191,412,92,70); lbl_COMPRESSOR_MAKEUP_7R4Q.setBounds(191,482,92,14);
}
