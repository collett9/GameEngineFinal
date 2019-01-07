#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

class imageLoader
{
public:
	imageLoader();
	~imageLoader();

	sf::Texture* loadTexture(std::string fileNameOfImage);
};

