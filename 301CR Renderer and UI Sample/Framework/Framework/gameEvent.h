#pragma once
#include "gameObject.h"
// could be the issue???? circular
#include <vector>
#include <string>

// this class is for all events that will be dealt with by the event handler

class gameEvent
{
public:

	std::string nameOfEvent;

	enum eventTypes
	{
		movement,
		audio,
		another,
		attack,
		potion


	};

	eventTypes eventType;

	std::vector <gameObject*> gameObjectsInvolved;

	// collection of the void pointers that contain the memory addresses of the data needed for each event to solve
	struct bin {

		std::vector<void*> eventVoidPointerVector;
	};

	bin* testBin = new bin;

	//std::vector <void*> dateToStore;


	enum whichSubsystem
	{
		Physics,
		Renderer,
		Audio,
		Battle

	};

	std::vector <whichSubsystem> whichSubsystemsInvovlved;


	gameEvent();
	void clearMemory();
	~gameEvent();
};

