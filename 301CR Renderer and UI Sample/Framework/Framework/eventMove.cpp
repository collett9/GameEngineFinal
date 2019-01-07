#include "eventMove.h"


eventMove::eventMove(float xSpeed, float ySpeed, gameObject* gameObjectInvolved)
{


	whichSubsystemsInvovlved.push_back(Physics);
	//whichSubsystemsInvovlved.push_back(Renderer);

	//float* xSpeedNew = new float(10.0f);

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
	//dateToStore.push_back(&XSpeed);
	//dateToStore.push_back(&YSpeed);

	//delete temp1;
	//delete temp2;

	

	//voidPointerData = &xSpeed;
	//voidPointerData2 = ySpeed;
}

eventMove::~eventMove()
{
	//delete testBin;


}