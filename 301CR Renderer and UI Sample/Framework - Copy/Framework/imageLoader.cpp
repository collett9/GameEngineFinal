#include "imageLoader.h"



imageLoader::imageLoader()
{
}


imageLoader::~imageLoader()
{
}

sf::Texture* imageLoader::loadTexture(std::string fileNameOfImage)
{
	sf::Texture* textureToUse = new sf::Texture;

	if (!textureToUse->loadFromFile(fileNameOfImage))
	{
		std::cout << "Cannot load image: " << fileNameOfImage << "!";
	}



	return textureToUse;
}
