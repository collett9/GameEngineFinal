#include "inputHandler.h"



inputHandler::buttons inputHandler::whichKey()
{
	rendererEvent->gameWindow->pollEvent(eventToHandle);

	if (eventToHandle.type == sf::Event::Closed) {
		return closed;

	}

	if (eventToHandle.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			return leftArrow;
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			return rightArrow;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			return upArrow;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			return downArrow;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			return space;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			return W;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			return escape;
		}
	}
	if (eventToHandle.type == sf::Event::Resized)
	{
		sf::FloatRect visibleArea(0, 0, eventToHandle.size.width, eventToHandle.size.height);
		rendererEvent->gameWindow->setView(sf::View(visibleArea));
		return resized;
	}

}

void inputHandler::setUpEvent(sf::Event whichEvent)
{
	eventToHandle = whichEvent;
}

void inputHandler::setUpRenderer(renderer * rendererToUse)
{
	 rendererEvent = rendererToUse;
}

inputHandler::inputHandler()
{
}


inputHandler::~inputHandler()
{
}
