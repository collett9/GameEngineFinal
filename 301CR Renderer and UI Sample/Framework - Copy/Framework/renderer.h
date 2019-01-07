#pragma once
#include "gameObject.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include <string>
#include <glm\glm.hpp>




class renderer
{
public:

	sf::RenderWindow pointerWindow;
	sf::RenderWindow* gameWindow;

	renderer(std::string windowName, int Width, int Height);



	void updateRenderer(std::vector<gameObject*> gameObjectVector, std::vector<b2Vec2> positionVectors, std::vector<float> rotationVectors, std::vector<b2Vec2> sizeVectors);

	void updateRendererForGui(std::vector<gameObject*> gameObjectsVector);

	void textRenderer(std::vector<gameObject*> gameObjectVector);

	void renderToScreen(std::vector <gameObject*> gameObjectVector);


	~renderer();
};

