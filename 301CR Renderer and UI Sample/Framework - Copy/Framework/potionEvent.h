#pragma once
#include "gameEvent.h"
class potionEvent :
	public gameEvent
{
public:
	potionEvent(gameObject * characterTakingPotion);
	~potionEvent();
};

