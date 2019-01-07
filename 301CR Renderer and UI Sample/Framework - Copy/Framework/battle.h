#pragma once
#include "gameEvent.h"
#include "Enemy.h"
#include "player.h"

class battle
{
public:
	bool battleStage = 0;

	void battleEventSolver(gameEvent * eventToSolve);


	battle();
	~battle();
};

