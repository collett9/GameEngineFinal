#include "audioEvent.h"



audioEvent::audioEvent(int soundId)
{

	whichSubsystemsInvovlved.push_back(Audio);

	nameOfEvent = "Playing audio sample";

	eventType = audio;

	void* temp1 = new void*;



	memcpy(temp1, &soundId, sizeof(int));

	testBin->eventVoidPointerVector.push_back(temp1);
}

audioEvent::~audioEvent()
{
}
