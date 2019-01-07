#pragma once
#include "gameEvent.h"
class audioEvent :
	public gameEvent
{
public:
	std::string soundFileName;

	//audioEvent(std::string fileName);
	//audioEvent(char fileName[]);
	audioEvent(int soundId);
	~audioEvent();
};

