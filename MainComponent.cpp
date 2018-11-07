/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

#define test_cnt 20
//==============================================================================

LabelListComponent::LabelListComponent()
{
	for (auto i = 0; i < test_cnt; ++i)
	{
		Label *portNum = new Label();
		addAndMakeVisible(portNum);
		portNum->setComponentID(String(i));
		portNum->setText("Port " + (String)i, dontSendNotification);
		portNum->setColour(Label::backgroundColourId, Colour (0x32ffffff));  
		portNum->setColour(Label::outlineColourId, Colours::darkgrey);
		l.add(portNum);
	}
	setSize(600, 400);
}

void LabelListComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	juce::Rectangle<int> mainBounds(getLocalBounds()); // W, H
	for (auto i = 0; i < test_cnt; ++i)
	{
		l[i]->setBounds(mainBounds.removeFromTop(getHeight()/test_cnt));
	}
}

VLL::VLL()
{
	addAndMakeVisible(v);
	v.setViewedComponent(&ll);

	addAndMakeVisible(label);
	label.setText("test", dontSendNotification);
	label.setColour(Label::backgroundColourId, Colour (0x32ffffff));  
	label.setColour(Label::outlineColourId, Colours::darkgrey);
}

void VLL::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	juce::Rectangle<int> mainBounds(getLocalBounds()); // W, H
	label.setBounds(mainBounds.removeFromTop(mainBounds.getHeight() / 3));
	v.setBounds(mainBounds.removeFromTop(mainBounds.getHeight()));
}

MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
	addAndMakeVisible(vll);
	//vll.setSize(getWidth(), getHeight());
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    //g.fillAll (Colour (0xff001F36));

    //g.setFont (Font (16.0f));
    //g.setColour (Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	juce::Rectangle<int> mainBounds(getLocalBounds()); // W, H
	vll.setBounds(mainBounds.removeFromTop(getHeight() / 2));
}

bool MainContentComponent::keyPressed(const KeyPress &key)
{
	if (key == KeyPress(KeyPress::F6Key))
	{
		DialogWindow::LaunchOptions opt;
		opt.content.setOwned(new VLL());
		opt.content->setSize(getWidth(), getHeight());
		opt.dialogTitle = "Test Setting";
		opt.dialogBackgroundColour = Colours::lightgrey;
		opt.escapeKeyTriggersCloseButton = true;
		opt.useNativeTitleBar = true;
		opt.resizable = false;

		testDlgWin = opt.launchAsync();

		if (testDlgWin != nullptr)
			testDlgWin->centreWithSize((getWidth() - 200), (getHeight() - 200));
	}
	return false;
}