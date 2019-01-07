#pragma once
#include <vector>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
//#include "physicsSync.h"


class gameObject
{
public:
	int gameObjectId;

	b2Vec2 position;
	float rotation = 0;

	float density;
	float friction;
	float linearDamping;
	bool IsStatic;
	bool canBeSelected;
	bool isSelected = false;

	float sizeY, sizeX;

	sf::RectangleShape gameObjectShape;
	sf::Color colourOfObject;
	sf::Text gameObjectText;
	sf::Texture* gameObjectTexture;
	std::string gameObjectName;
	std::string UIDescription;

	bool toBeRemoved = false;
	
	enum typeOfObject
	{
		Environment,
		Enemy,
		Door

	};

	typeOfObject whatType;

	//void renderCreation(sf::Vector2f size, sf::Color colour, sf::Vector2f position, float outLineSize, sf::Color outlineColour);
	//void physicsCreation(float positionX, float positionY, float sizeX, float sizeY, float desnity, float friction, float linearDamping, physicsSync physicsWorld, bool isStatic);


	gameObject();
	void setup(b2Vec2 Position, float Rotation, float SizeX, float SizeY, sf::Color Colour, float Density, float Friction, float LinearDamping, bool isStatic);
	void setupForGui(b2Vec2 Position, float SizeX, float SizeY, sf::Color Colour);
	void setNameOfObject(std::string name);
	void setObjectImage(std::string fileName);

	~gameObject();
};

