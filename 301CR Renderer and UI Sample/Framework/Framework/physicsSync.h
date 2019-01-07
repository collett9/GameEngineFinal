#pragma once
#include <vector>
#include "Box2D\Box2D.h"
#include "gameEvent.h"
#include "eventMove.h"
#include <iostream>


//collision listener class for use in .cpp file (CHANGE THIS)
class physicsSync
{

public:

	class MyContactListener : public b2ContactListener
	{
	public:

		b2Fixture * fixture1;
		b2Fixture * fixture2;

		int data1;
		int data2;
		int data3;
		int data4;

		

		void BeginContact(b2Contact* contact)
		{

			fixture1 = contact->GetFixtureA();
			fixture2 = contact->GetFixtureB();

			b2Body* body1 = fixture1->GetBody();
			b2Body* body2 = fixture2->GetBody();

			data1 = *(int*)body1->GetUserData();
			data2 = *(int*)body2->GetUserData();

			int soundIdToUse = *(int*)body1->GetUserData();

		}

		void EndContact(b2Contact* contact)
		{
			fixture1 = contact->GetFixtureA();
			fixture2 = contact->GetFixtureB();

			b2Body* body1 = fixture1->GetBody();
			b2Body* body2 = fixture2->GetBody();

			data3 = *(int*)body1->GetUserData();
			data4 = *(int*)body2->GetUserData();


		}

	};

	float gravityX, gravityY;

	b2World* world = new b2World(b2Vec2(gravityX, gravityY));

	std::vector <b2Vec2> positionVectors;
	std::vector <float> rotationVectors;
	std::vector <b2Vec2> sizeVectors;

	std::vector <b2Fixture*> fixturesHit;
	b2Contact *egg;

	MyContactListener listener;
	std::vector <b2Body*> physicsBodies;

	void addPhysicsObject(float positionX, float positionY, float hitBoxSizeX, float hitBoxSizeY, float density, float friction, float linearDamping, bool isStatic, int nameOfObject);

	void physicsSetup();

	//void addPhysicsObject(float positionX, float positionY, float hitBoxSizeX, float hitBoxSizeY, float density, float friction, float linearDamping, bool isStatic);

	void physicsUpdate(float32 timeStep, int32 velocityIterations, int32 positionIterations);

	void physicsEventSolver(gameEvent * gameEventToSolve);


	physicsSync(float GravityX, float GravityY);

	

	~physicsSync();
};

