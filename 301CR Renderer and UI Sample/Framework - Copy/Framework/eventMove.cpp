#include "eventMove.h"


eventMove::eventMove(float xSpeed, float ySpeed, gameObject* gameObjectInvolved)
{


	whichSubsystemsInvovlved.push_back(Physics);


	nameOfEvent = "movement";
	eventType = movement;

	gameObjectsInvolved.push_back(gameObjectInvolved);

	//testBin->eventVoidPointerVector.resize(2);

	void* temp1 = new void*;
	void* temp2 = new void*;

	memcpy(temp1, &xSpeed, sizeof(float));
	memcpy(temp2, &ySpeed, sizeof(float));
	

	testBin->eventVoidPointerVector.push_back(temp1);
	testBin->eventVoidPointerVector.push_back(temp2);

}

eventMove::~eventMove()
{


}