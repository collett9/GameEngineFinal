#pragma once
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>

class level
{
public:


	int sizeX;
	int sizeY;


	enum chunk
	{
		nothing,
		wall,
		playerLocation,
		enemyLocation,
		goblinLocation,
		largeGoblinLocation,
		ogreLocation,
		doorLocation
	};

	struct levelChunk
	{
		chunk whichChunk;
		int positionInGridX;
		int positionInGridY;
		float actualPositionX;
		float actualPositionY;

	};

	std::vector <std::vector<levelChunk>> levelData;

	std::vector <std::string> doorEntrances;

	std::string fileNameUsed;



	//level(int SizeX, int SizeY);

	level(int SizeX, int SizeY, std::string fileName);

	~level();

	void setupImage(std::string fileName);

	void roomLayout(std::string fileName);


	sf::Image testImage;

	float sizeBetweenObjects = 50;
};

