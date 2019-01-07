#include "gameObject.h"


// creating a game object, making a physics object as well as a sfml object
gameObject::gameObject()
{
	
	
}

// setting up a physical game object
void gameObject::setup(b2Vec2 Position, float Rotation, float SizeX, float SizeY, sf::Color Colour, float Density, float Friction, float LinearDamping, bool isStatic)
{

	position = Position;
	rotation = Rotation;

	gameObjectShape.setSize(sf::Vector2f(SizeX * 2, SizeY * 2));
	gameObjectShape.setFillColor(Colour);
	gameObjectShape.setPosition(sf::Vector2f(Position.x, Position.y));

	sizeX = SizeX;
	sizeY = SizeY;

	density = Density;
	friction = Friction;
	linearDamping = LinearDamping;
	IsStatic = isStatic;

	colourOfObject = Colour;
}

//setting up a non-physical game object
void gameObject::setupForGui(b2Vec2 Position, float SizeX, float SizeY, sf::Color Colour)
{
	position = Position;
	sizeX = SizeX;
	sizeY = SizeY;

	gameObjectShape.setSize(sf::Vector2f(SizeX * 2, SizeY * 2));
	gameObjectShape.setFillColor(Colour);
	gameObjectShape.setPosition(sf::Vector2f(Position.x, Position.y));

	gameObjectText.setString(gameObjectName);

	colourOfObject = Colour;
	

}

void gameObject::setNameOfObject(std::string name)
{
	gameObjectName = name;
}

void gameObject::setObjectImage(std::string fileName)
{
	gameObjectTexture = new sf::Texture;
	if (!gameObjectTexture->loadFromFile(fileName))
	{
		std::cout << "Couldn't load image: " << fileName << "from directory!";
	}

	gameObjectShape.setTexture(gameObjectTexture);

	gameObjectShape.setFillColor(sf::Color::White);
}

gameObject::~gameObject()
{
}
