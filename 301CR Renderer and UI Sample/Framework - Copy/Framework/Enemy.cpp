#include "Enemy.h"



Enemy::Enemy()
{
}

void Enemy::EnemySetup(b2Vec2 position)
{
	setup(position, 0, 25, 25, sf::Color::Red, 0, 0, 0, 1);
	whatType = gameObject::Enemy;
}

Enemy::~Enemy()
{
}
