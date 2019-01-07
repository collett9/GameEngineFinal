#include "potionEvent.h"



potionEvent::potionEvent(gameObject * characterTakingPotion)
{
	whichSubsystemsInvovlved.push_back(Battle);

	nameOfEvent = "Player drinking potion!";

	eventType = potion;

	gameObjectsInvolved.push_back(characterTakingPotion);
}


potionEvent::~potionEvent()
{
}
