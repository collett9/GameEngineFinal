#include "wallObject.h"


wallObject::wallObject(b2Vec2 wallPosition)
{
	//position = wallPosition;

	//setting up the parameters for this wall;
	setup(wallPosition, 0, 25, 25, sf::Color::Black, 0, 0, 0, 1);

}

wallObject::~wallObject()
{
	delete this;
}
