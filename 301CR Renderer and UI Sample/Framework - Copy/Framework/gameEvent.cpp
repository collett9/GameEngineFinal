#include "gameEvent.h"



gameEvent::gameEvent()
{
	


}

void gameEvent::clearMemory()
{

	for (int i = 0; i <testBin->eventVoidPointerVector.size(); i++)
	{
		delete testBin->eventVoidPointerVector[i];
	}
	delete testBin;
}


gameEvent::~gameEvent()
{


	
}
