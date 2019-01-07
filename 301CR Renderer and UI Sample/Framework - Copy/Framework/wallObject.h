#pragma once
#include "gameObject.h"
class wallObject :
	public gameObject
{
public:

	wallObject(b2Vec2 wallPosition);
	~wallObject();
};

