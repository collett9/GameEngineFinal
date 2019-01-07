#pragma once
#include "gameObject.h"
#include <string>
class GUIElement :
	public gameObject
{
public:
	std::string buttonText;

	void setupGUIText(std::string textToInput);

	GUIElement();
	~GUIElement();
};

