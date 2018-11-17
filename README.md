# juce_viewport_sample
[Viewport class](https://docs.juce.com/master/classViewport.html) sample code.

simple flow:
1. create a component(VLL) within Viewport member which want to use scrollbar component(LabelListComponent).
2. in constructor(VLL), addAndMakeVisible() and Viewport().setViewedComponent()
3. add this component(VLL) to maincomponent(MainContentComponent) class and addAndMakeVisible() it.
