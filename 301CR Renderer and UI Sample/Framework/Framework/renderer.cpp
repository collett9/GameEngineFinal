#include "renderer.h"
#include <iostream>

sf::Font font;

renderer::renderer(std::string windowName, int Width, int Height)
{
	//pointerWindow.
	//pointerWindow.setSize(sf::Vector2u(Width, Height));
	//pointerWindow.setTitle(windowName);

	//gameWindow = &pointerWindow;
	
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error: Failed to load font!" << std::endl;

	}

	gameWindow = new sf::RenderWindow(sf::VideoMode(Width, Height), windowName);
}



void renderer::updateRenderer(std::vector<gameObject*> gameObjectsVector, std::vector<b2Vec2> positionVectors, std::vector<float> rotationVectors, std::vector <b2Vec2> sizeVectors)
{

	for (int i = 0; i < gameObjectsVector.size(); i++)
	{
		gameObjectsVector[i]->gameObjectShape.setPosition(sf::Vector2f(positionVectors[i].x, positionVectors[i].y));
		gameObjectsVector[i]->gameObjectShape.setOrigin(sf::Vector2f(sizeVectors[i].x, sizeVectors[i].y));
		gameObjectsVector[i]->gameObjectShape.setRotation(glm::degrees(rotationVectors[i]));

	}

}

void renderer::updateRendererForGui(std::vector<gameObject*> gameObjectsVector)
{

	//for (int i = 0; i < gameObjectsVector.size(); i++)
	//{
	//	gameObjectsVector[i]->gameObjectShape.setPosition(gameObjectsVector[i]->position);
	////	gameObjectsVector[i]->gameObjectShape.setPosition(sf::Vector2f(gameObjectsVector[i]->position, positionVectors[i].y));
	//	gameObjectsVector[i]->gameObjectShape.setOrigin(sf::Vector2f(sizeVectors[i].x, sizeVectors[i].y));
	//	gameObjectsVector[i]->gameObjectShape.setRotation(glm::degrees(rotationVectors[i]));

	//}

}

void renderer::textRenderer(std::vector<gameObject*> gameObjectVector)
{
	for (int i = 0; i < gameObjectVector.size(); i++)
	{
		
		gameObjectVector[i]->gameObjectText.setFont(font);
		gameObjectVector[i]->gameObjectText.setFillColor(sf::Color::Black);
		gameObjectVector[i]->gameObjectText.setPosition(sf::Vector2f(gameObjectVector[i]->position.x, gameObjectVector[i]->position.y));
		//gameObjectVector[i]->gameObjectText.setString(gameObjectVector[i]->gameObjectName);
		gameObjectVector[i]->gameObjectText.setString(gameObjectVector[i]->UIDescription);
	}
}

void renderer::renderToScreen(std::vector<gameObject*> gameObjectVector)
{

	gameWindow->clear(sf::Color(25,25,25,255));

	for (int i = 0; i < gameObjectVector.size(); i++)
	{
		gameWindow->draw(gameObjectVector[i]->gameObjectShape);
		gameWindow->draw(gameObjectVector[i]->gameObjectText);
	}

	textRenderer(gameObjectVector);

	gameWindow->display();
}
	


renderer::~renderer()
{
}
