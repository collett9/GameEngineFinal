#include "level.h"


level::level(int SizeX, int SizeY, std::string fileName)
{
	levelData.resize(SizeX);
	for (int i = 0; i < SizeX; i++)
	{
		levelData[i].resize(SizeX);

	}

	setupImage(fileName);


	// setting up the grid of level data positions
	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (i == 0 || i == SizeX-1 || j == 0 || j == SizeY-1)
			{
				//levelData[i][j].whichChunk = wall;
			}

			/*else
			{
				levelData[i][j].whichChunk = nothing;
			}*/

			levelData[i][j].actualPositionX = i * sizeBetweenObjects + sizeBetweenObjects/2;
			levelData[i][j].actualPositionY = j * sizeBetweenObjects+ sizeBetweenObjects/2;
		}
	}

	

}

level::~level()
{
}

// goes through an image and fetches colour data, translating it into map data --- perhaps move this elsewhere later
void level::setupImage(std::string fileName)
{
	sf::Image testImage;

	testImage.loadFromFile(fileName);
	
	sf::Vector2f testVec2 = sf::Vector2f(testImage.getSize());


	for (int i = 0; i < testVec2.x; i++)
	{
		for (int j = 0; j < testVec2.y; j++)
		{
			sf::Color tempColour = testImage.getPixel(i, j);

			float temp1 = (float)tempColour.r;
			float temp2 = (float)tempColour.g;
			float temp3 = (float)tempColour.b;

			sf::Vector3f tempColourVector = sf::Vector3f(temp1, temp2, temp3);

			if (tempColourVector == sf::Vector3f(0.0f, 0.0f, 0.0f))
			{
				levelData[i][j].whichChunk = wall;
			}

			else if(tempColourVector == sf::Vector3f(0.0f, 255.0f, 0.0f))
			{
				levelData[i][j].whichChunk = playerLocation;
			}

			else if (tempColourVector == sf::Vector3f(255.0f, 0.0f, 0.0f))
			{
				levelData[i][j].whichChunk = enemyLocation;
			}

			else if (tempColourVector == sf::Vector3f(0.0f, 70.0f, 0.0f))
			{
				levelData[i][j].whichChunk = goblinLocation;
			}

			else if (tempColourVector == sf::Vector3f(180.0f, 75.0f, 25.0f))
			{
				levelData[i][j].whichChunk = ogreLocation;
			}

			else if (tempColourVector == sf::Vector3f(255.0f, 255.0f, 0.0f))
			{
				levelData[i][j].whichChunk = doorLocation;
			}

			else
			{
				levelData[i][j].whichChunk = nothing;
			}
		}
	}

	


}

void level::roomLayout(std::string fileName)
{
	if (fileName == "../Levels/level0.png")
	{
		doorEntrances.push_back("../Levels/level1.png");
		doorEntrances.push_back("../Levels/level2.png");
		doorEntrances.push_back("../Levels/level3.png");
	}

	if (fileName == "../Levels/level1.png")
	{
		doorEntrances.push_back("../Levels/level0.png");
	}

	if (fileName == "../Levels/level2.png")
	{
		doorEntrances.push_back("../Levels/level0.png");
	}

	if (fileName == "../Levels/level3.png")
	{
		doorEntrances.push_back("../Levels/level0.png");
	}

}
