#pragma once
#include "gameObject.h"
class player :
	public gameObject

{
public:
	int health = 200;
	int maxHealth = 200;
	int numberOfPotions = 5;
	int baseAttackPower = 50;

	player();
	~player();
};

