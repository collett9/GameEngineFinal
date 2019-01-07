#include "GUI.h"


//creating the generic GUI from gameobjects
void GUI::BattleGUISetup()
{


	addNewGUIElementWithText(b2Vec2(100.0, 450.0f), 100.0f, 50.0f, sf::Color::Red, true, "Attack!");
	addNewGUIElementWithText(b2Vec2(100.0, 600.0f), 100.0f, 50.0f, sf::Color::Red, true, "Potion!");

	//addNewGUIElement(b2Vec2(1000.0, 600.0f), 100.0f, 50.0f, sf::Color::Red, false);

}

void GUI::addNewGUIElement(b2Vec2 position, float sizeX, float sizeY, sf::Color colour, bool isSelectabble)
{
	GUIElement* newElement = new GUIElement;
	//newElement->gameObjectName = "wegg"; //CHEAP!
	newElement->setupForGui(position, sizeX, sizeY, colour);
	newElement->gameObjectId = tempID;
	newElement->canBeSelected = isSelectabble;
	gameObjectsInGUI.push_back(newElement);

	tempID = tempID + 1;

	
}

void GUI::addNewGUIElementWithText(b2Vec2 position, float sizeX, float sizeY, sf::Color colour, bool isSelectabble, std::string boxText)
{
	GUIElement* newElement = new GUIElement;
	newElement->gameObjectName = boxText;
	newElement->UIDescription= boxText;
	newElement->setupForGui(position, sizeX, sizeY, colour);
	newElement->gameObjectId = tempID;
	newElement->canBeSelected = isSelectabble;
	gameObjectsInGUI.push_back(newElement);

	tempID = tempID + 1;

}


void GUI::GUIHandlerFirstElement(std::vector<gameObject*> GUIElements)
{
	bool foundIt = false;
	for (int i = 0; i < GUIElements.size(); i++)
	{
		if (GUIElements[i]->canBeSelected == true && foundIt == false)
		{
			currentlySelectedElement = i;
			foundIt = true;
		}
	}

}

void GUI::GUIHandlerNextElement(std::vector<gameObject*> GUIElements)
{
	bool foundIt = false;
	if (currentlySelectedElement < GUIElements.size())
	{
		for (int i = currentlySelectedElement+1; i < GUIElements.size(); i++)
		{
			if (GUIElements[i]->canBeSelected == true && foundIt == false)
			{
				currentlySelectedElement = i;
				foundIt = true;
			}
		}
	}

}

void GUI::GUIHandlerPreviousElement(std::vector<gameObject*> GUIElements)
{
	bool foundIt = false;
	if (currentlySelectedElement > 0)
	{
		for (int i = currentlySelectedElement - 1; i < GUIElements.size(); i= i -1)
		{
			if (GUIElements[i]->canBeSelected == true && foundIt == false)
			{
				currentlySelectedElement = i;
				foundIt = true;
			}
		}
	}

}

void GUI::GUIUpdate(std::vector<gameObject*> GUIElements)
{
	for (int i = 0; i < gameObjectsInGUI.size(); i++)
	{
		gameObjectsInGUI[i]->gameObjectShape.setFillColor(gameObjectsInGUI[i]->colourOfObject);
	}


	if (currentlySelectedElement < gameObjectsInGUI.size() && currentlySelectedElement >= 0)
	{
		gameObjectsInGUI[currentlySelectedElement]->gameObjectShape.setFillColor(sf::Color::Yellow);
	}


}

//clear the GUI and reset it. Useful for restarting fights.
void GUI::wipeGUI()
{
	gameObjectsInGUI.clear();
	BattleGUISetup();

}

void GUI::updateGUIElementText(gameObject * GUIElement, std::string updatedText)
{
	GUIElement->UIDescription = updatedText;

}


GUI::GUI()
{

}


GUI::~GUI()
{
}
