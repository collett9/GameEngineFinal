#include "battleEvent.h"


battleEvent::battleEvent(gameObject * attacker, gameObject * attackee)
{
	gameObjectsInvolved.push_back(attacker);
	gameObjectsInvolved.push_back(attackee);


	whichSubsystemsInvovlved.push_back(Battle);

	eventType = attack;

	nameOfEvent = ("Player is attacking or being attacked!");
}

battleEvent::~battleEvent()
{
}
