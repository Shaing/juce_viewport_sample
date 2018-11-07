/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class LabelListComponent   : public Component
{
public:
    //==============================================================================
    LabelListComponent();
	~LabelListComponent(){}

    //void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
	OwnedArray<Label> l;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LabelListComponent)
};

class VLL : public Component
{
public:
    //==============================================================================
    VLL();
	~VLL(){}

    //void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
	Viewport v;
	Label label;
	LabelListComponent ll;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VLL)
};


class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
	VLL vll;
	SafePointer<DialogWindow> testDlgWin;
	bool keyPressed(const KeyPress &key) override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};



#endif  // MAINCOMPONENT_H_INCLUDED
