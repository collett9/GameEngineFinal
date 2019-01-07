#include "battle.h"


//solving combat events 
#include <iostream>

void battle::battleEventSolver(gameEvent * eventToSolve)
{
	Enemy *enemyToFight;
	player *playerCharacter;

	if (eventToSolve->eventType == gameEvent::attack)
	{
		if (eventToSolve->gameObjectsInvolved[0]->whatType == gameObject::Enemy)
		{
			enemyToFight = (Enemy*)eventToSolve->gameObjectsInvolved[0];
			playerCharacter = (player*)eventToSolve->gameObjectsInvolved[1];

			playerCharacter->health = playerCharacter->health - enemyToFight->baseAttackPower;

			std::cout << enemyToFight->gameObjectName << "did: " << std::to_string(playerCharacter->baseAttackPower) << " attack damage to: " << "Player" << "!" << std::endl;

			if (playerCharacter->health <= 0)
			{
				exit(0);
				//delete eventToSolve->gameObjectsInvolved[0];
			}

			eventToSolve->gameObjectsInvolved[1] = playerCharacter;
		}
		//eventToSolve->gameObjectsInvolved[1]

		if (eventToSolve->gameObjectsInvolved[1]->whatType == gameObject::Enemy)
		{
			enemyToFight = (Enemy*)eventToSolve->gameObjectsInvolved[1];
			playerCharacter = (player*)eventToSolve->gameObjectsInvolved[0];

			enemyToFight->health = enemyToFight->health - playerCharacter->baseAttackPower;

			std::cout << "Player did: " << std::to_string(playerCharacter->baseAttackPower) << " attack damage to: " << enemyToFight->gameObjectName << "!" << std::endl;

			eventToSolve->gameObjectsInvolved[0] = enemyToFight;

			if (enemyToFight->health <= 0)
			{
				eventToSolve->gameObjectsInvolved[0]->toBeRemoved = true;
				//delete eventToSolve->gameObjectsInvolved[0];
			}
			
			//updateGUIElementText(eventToSolve->gameObjectsInvolved[0], eventToSolve->gameObjectsInvolved)
		}

		

		battleStage = !battleStage;
		eventToSolve->whichSubsystemsInvovlved.pop_back();
	}

	if (eventToSolve->eventType == gameEvent::potion)
	{
		player *playerCharacter = (player*)eventToSolve->gameObjectsInvolved[0];

		if (playerCharacter->numberOfPotions > 0)
		{
			playerCharacter->health = playerCharacter->health + 100;
			playerCharacter->numberOfPotions = playerCharacter->numberOfPotions - 1;
		}

		if (playerCharacter->health > playerCharacter->maxHealth)
		{
			playerCharacter->health = playerCharacter->maxHealth;
		}


		eventToSolve->gameObjectsInvolved[0] = playerCharacter;

		eventToSolve->whichSubsystemsInvovlved.pop_back();

	}

}

battle::battle()
{
}


battle::~battle()
{
}
