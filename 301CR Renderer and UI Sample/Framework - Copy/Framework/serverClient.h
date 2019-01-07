#pragma once
#include <iostream>
#include <enet\enet.h>

using namespace std;
class serverClient
{
public:

	ENetAddress address;
	ENetHost* server;
	ENetEvent enetEvent;

	ENetPacket* dataPacket;

	void serverUpdate();
	void killServer();
	serverClient();
	~serverClient();
};

