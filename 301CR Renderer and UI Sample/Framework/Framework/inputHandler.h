#pragma once
#include <SFML\Graphics.hpp>
#include "renderer.h"


class inputHandler
{
public:

	renderer* rendererEvent = nullptr;
	sf::Event eventToHandle;

	enum buttons
	{
		upArrow,
		downArrow,
		leftArrow,
		rightArrow,
		W,
		space,
		escape,


		closed,
		resized


	};

	buttons whatWasPressed;

	buttons whichKey();
	void setUpEvent(sf::Event whichEvent);
	void setUpRenderer(renderer* rendererToUse);
	inputHandler();
	~inputHandler();
};

