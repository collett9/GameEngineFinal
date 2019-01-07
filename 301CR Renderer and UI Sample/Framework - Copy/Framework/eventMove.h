#pragma once
#include "gameEvent.h"
class eventMove :
	public gameEvent
{
public:
	float XSpeed;
	float YSpeed;

	//void* voidptr1 = new void*;
	//void* voidptr2 = new void*;

	//eventMove(float xSpeed, float ySpeed);
	eventMove(float xSpeed, float ySpeed, gameObject * gameObjectInvolved);
	~eventMove();
};

