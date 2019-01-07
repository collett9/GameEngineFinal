#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"
#include <string>
#include "physicsSync.h"
#include <iostream>
#include "gameObject.h"
#include <vector>
#include <glm\glm.hpp>
#include "renderer.h"
#include "gameEvent.h"
#include "eventMove.h"
#include "wallObject.h"
#include "level.h"
#include "audioSystem.h"
#include "audioEvent.h"
#include "Enemy.h"
#include "GUI.h"
#include "GUIElement.h"
#include "inputHandler.h"
#include "ogre.h"
#include "Goblin.h"
#include "player.h"
#include "battle.h"
#include "battleEvent.h"
#include "door.h"
#include "potionEvent.h"
#include "imageLoader.h"
#include "networkSync.h"
#include "serverClient.h"

class game
{
public:
	
	//physicsSync test = physicsSync(0.0f, 0.0f);

	physicsSync *physics = nullptr;

	audioSystem *audioSystemGame = nullptr;

	renderer *rendererGame = nullptr;

	renderer *rendererBattle = nullptr;

	inputHandler *input = nullptr;

	battle *battleGame = nullptr;

	networkSync networkConnection;
	//serverClient serverGame;

	int player2Id = 999;

	bool isGameWindowOpen;


	std::vector <gameObject*> gameObjectsVector;
	std::vector <gameObject*> battleMenuObjectVector;
	std::vector <gameEvent*> gameEventsVector;

	bool battleScreen = false;

	GUI gui;

	float32 timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	int enemyToFightInBattle;

	sf::Event e;

	//void levelSetup(int SizeX, int SizeY);

	void setUp(std::string windowName, int Width, int Height);
	void gameObjectsSetup();
	void gameObjectsCollide();
	void addOtherPlayer();
	void levelSetup(int SizeX, int SizeY, std::string imageFileName);
	void update();
	void eventHandler();
	void guiHandler();
	void inputHandlerGame();
	void render();

	game();
	~game();
};

