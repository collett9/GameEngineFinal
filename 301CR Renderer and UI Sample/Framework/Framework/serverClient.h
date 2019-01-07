#pragma once
#include <iostream>
#include <enet\enet.h>


struct Vector2 {
	float x;
	float y;
};

using namespace std;
class serverClient
{
public:


	ENetAddress address;
	ENetHost* server;
	ENetEvent enetEvent;

	ENetPacket* dataPacket;

	bool otherPlayer = 0;

	Vector2* newPosition = nullptr;

	//char* egg[];




	void serverUpdate();
	void killServer();

	void givePosition(float x, float y);
	void giveLevel(char fileNameToUse[22]);

	serverClient();
	~serverClient();
};

