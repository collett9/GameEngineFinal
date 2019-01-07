#include "physicsSync.h"


// adds physics object to the scene, currently only adds a box ADD MORE TYPES
void physicsSync::addPhysicsObject(float positionX, float positionY, float hitBoxSizeX, float hitBoxSizeY, float density, float friction, float linearDamping, bool isStatic, int nameOfObject)
{
	if (isStatic == true)
	{
		b2BodyDef bodyDef;
		//bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(positionX, positionY);
		physicsBodies.push_back(world->CreateBody(&bodyDef));

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(hitBoxSizeX, hitBoxSizeY);


		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		physicsBodies.back()->CreateFixture(&fixtureDef);
		physicsBodies.back()->SetLinearDamping(linearDamping);

		void* egge1 = new void*;
		memcpy(egge1, &nameOfObject, sizeof(nameOfObject));
		physicsBodies.back()->SetUserData(egge1);
		
		//sizeVectors.push_back(b2Vec2(hitBoxSizeX, hitBoxSizeY));
	}

	else if (isStatic == false)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(positionX, positionY);
		physicsBodies.push_back(world->CreateBody(&bodyDef));

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(hitBoxSizeX, hitBoxSizeY);


		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		physicsBodies.back()->CreateFixture(&fixtureDef);
		physicsBodies.back()->SetLinearDamping(linearDamping);
		void* egge1 = new void*;
		memcpy(egge1, &nameOfObject, sizeof(nameOfObject));
		physicsBodies.back()->SetUserData(egge1);

		//sizeVectors.push_back(b2Vec2(hitBoxSizeX, hitBoxSizeY));
	}


}

void physicsSync::physicsSetup()
{
	for (int i = 0; i < positionVectors.size(); i++)
	{
		// change this later to get all of the data before it comes here CHANGED THIS
		//addPhysicsObject(positionVectors[i].x, positionVectors[i].y, sizeVectors[i].x, sizeVectors[i].y, 0.5, 0.5, 0.5, false);
	}

	//setting up the position vectors for the first frame
	//positionVectors.resize(physicsBodies.size());
	//rotationVectors.resize(physicsBodies.size());

	for (int i = 0; i < physicsBodies.size(); i++)
	{
		//positionVectors[i] = physicsBodies[i]->GetPosition();
		rotationVectors[i] = physicsBodies[i]->GetAngle();
	}


	
	world->SetContactListener(&listener);


}



// updates the physics and outputs the positions and rotations of the various physics objects
void physicsSync::physicsUpdate(float32 timeStep, int32 velocityIterations, int32 positionIterations)
{
	world->Step(timeStep, velocityIterations, positionIterations);

	positionVectors.resize(physicsBodies.size());
	rotationVectors.resize(physicsBodies.size());

	for (int i = 0; i < physicsBodies.size(); i++)
	{

		positionVectors[i] = b2Vec2(physicsBodies[i]->GetPosition().x , physicsBodies[i]->GetPosition().y );
		rotationVectors[i] = physicsBodies[i]->GetAngle();

		// stop gameObjects rotating!
		//rotationVectors[i] = 0;
	}

	
	
	bool testedForCollisions = false;



}

void physicsSync::physicsEventSolver(gameEvent* gameEventToSolve)
{

	if (gameEventToSolve->eventType == gameEvent::movement)
	{
//		


		float finalSpeedX = *(float*)gameEventToSolve->testBin->eventVoidPointerVector[0];
		float finalSpeedY = *(float*)gameEventToSolve->testBin->eventVoidPointerVector[1];


		physicsBodies[gameEventToSolve->gameObjectsInvolved[0]->gameObjectId]->SetLinearVelocity(b2Vec2(finalSpeedX, finalSpeedY));
		gameEventToSolve->whichSubsystemsInvovlved.pop_back();





	

	}

}


physicsSync::physicsSync(float GravityX, float GravityY)
{
	gravityX = GravityX;
	gravityY = GravityY;

}

physicsSync::~physicsSync()
{
}
