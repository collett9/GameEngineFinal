#pragma once
#include "gameEvent.h"
class battleEvent :
	public gameEvent
{
public:
	battleEvent(gameObject * attacker, gameObject * attackee);
	~battleEvent();
};

