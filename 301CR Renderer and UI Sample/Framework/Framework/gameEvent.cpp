#include "gameEvent.h"



gameEvent::gameEvent()
{
	


}


//free memoryy used by the void pointers within this game event
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
