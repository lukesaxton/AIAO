//
//  VCMModules.cpp
//  AIMO
//
//  Created by Luke Saxton on 18/01/2017.
//
//

#include "VCMModules.hpp"
//=================================================================================================
//
//      GRID MODULE
//
//=================================================================================================

GridModule::GridModule(const int gridSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        buttons.add(new GridButton());
        addAndMakeVisible(buttons.getLast());
    }
}

GridModule::~GridModule()
{
    
}

void GridModule::setMapIn (const String newMapIn)
{
    
}

void GridModule::setMapOut (const String newMapOut)
{
    
}
void GridModule::addressedMidiCallback(const String address, MidiMessage message)
{
    
}

const int GridModule::getGridSize()
{
    return buttons.size();
}

void GridModule::paint(Graphics& g)
{
    g.fillAll(Colours::darkgrey);
}

void GridModule::resized()
{
    int buttonsPerRow = 0;

    switch (buttons.size()){
        case 64:
            buttonsPerRow = 8;
            break;
        case 49:
            buttonsPerRow = 7;
            break;
        case 36:
            buttonsPerRow = 6;
            break;
        case 25:
            buttonsPerRow = 5;
            break;
        case 9:
            buttonsPerRow = 3;
            break;
        case 2:
            buttonsPerRow = 2;
            break;
        case 1:
            buttonsPerRow = 1;
            break;
        default:
            buttonsPerRow = 4;
            break;
    }
    
    if (buttons.size() > 0)
    {
        float buttonWidth = getWidth() / buttonsPerRow;
        
        buttons[0]->setBounds(0, 0, buttonWidth, buttonWidth);
        
        for (int i = 1; i < buttons.size(); ++i)
        {
            buttons[i]->setBounds(buttons[i-1]->getBounds().translated(buttonWidth, 0));
            if (buttons[i]->getRight() > getWidth())
            {
                buttons[i]->setTopLeftPosition(0, (i/buttonsPerRow) * buttonWidth);
            }
        }
    }

    
    
}