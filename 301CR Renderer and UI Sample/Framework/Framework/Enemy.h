#pragma once
#include "gameObject.h"
class Enemy :
	public gameObject
{
public:
	//int level;
	int health;
	int baseAttackPower;

	Enemy();
	void EnemySetup(b2Vec2 position);
	~Enemy();
};

