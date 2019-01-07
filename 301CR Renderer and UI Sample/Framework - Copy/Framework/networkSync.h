#pragma once
#include <enet\enet.h>
#include <iostream>


struct Vector2 {
	float x;
	float y;
};

class networkSync
{
private:

public:
	Vector2 * newPosition = nullptr;
	char newStage[25] = "aaaaaaaaaaaaaaaaaaaaaaaa";

	ENetAddress address;
	ENetHost* client;
	ENetPeer* peer;
	ENetEvent enetEvent;

	std::string* newLevel;

	ENetPacket* dataPacket;

	bool isConnected;

	bool ottherPlayer = 0;

	

	networkSync();
	void networkUpdate();
	void givePosition(float x, float y);
	void giveLevel(int stageToSwitchTo);
	void disconnect();
	~networkSync();
};

