#include "serverClient.h"


void serverClient::serverUpdate()
{

	while (enet_host_service(server, &enetEvent, 0) > 0)
	{
		switch (enetEvent.type)
		{
		case ENET_EVENT_TYPE_CONNECT:

			cout << "A client connected from address " << enetEvent.peer->address.host << ":" << enetEvent.peer->address.port << ".\n";

			/* This event type has an associated peer: the client which has
			connected to the server. We can store some data about this peer
			for as long as it remains in scope using the "data" variable. */

			enetEvent.peer->data = "This is a client";

			otherPlayer = true;

			break;
		case ENET_EVENT_TYPE_DISCONNECT:

			cout << "The client from address " << enetEvent.peer->address.host << ":" << enetEvent.peer->address.port << " disconnected \n";

			enetEvent.peer->data = NULL;

			otherPlayer = false;
			break;

		case ENET_EVENT_TYPE_RECEIVE:
			newPosition = new Vector2;
			cout << "Packet received!\n";
			memcpy(newPosition, enetEvent.packet->data, enetEvent.packet->dataLength);
			cout << newPosition->x << "," << newPosition->y << "\n";
			//enemy.setPosition(sf::Vector2f(newPosition->x, newPosition->y));
		
			break;
		}
	}
}

void serverClient::killServer()
{

	enet_host_destroy(server);
	atexit(enet_deinitialize);

}

//create a packet used for movement

void serverClient::givePosition(float x, float y)
{
	Vector2 newVector2;
	newVector2.x = x;
	newVector2.y = y;

	dataPacket = enet_packet_create(&newVector2, sizeof(newVector2), ENET_PACKET_FLAG_RELIABLE);
	enet_host_broadcast(server, 0, dataPacket);

	

}

serverClient::serverClient()
{
	if (enet_initialize() != 0)
	{
		cout << "Enet failed to initialise!" << "\n\n";
	}

	address.host = ENET_HOST_ANY;
	address.port = 1234;

	server = enet_host_create(&address, 32, 2, 0, 0);


	if (server == NULL)
	{
		cout << "Server failed to initialise!" << "\n\n";
	}

}


serverClient::~serverClient()
{
}
