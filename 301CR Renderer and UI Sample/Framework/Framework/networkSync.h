#pragma once
#include <enet\enet.h>
#include <iostream>

class networkSync
{
public:

	ENetAddress address;
	ENetHost* client;
	ENetPeer* peer;
	ENetEvent enetEvent;

	ENetPacket* dataPacket;

	networkSync();
	void networkUpdate();
	void disconnect();
	~networkSync();
};

