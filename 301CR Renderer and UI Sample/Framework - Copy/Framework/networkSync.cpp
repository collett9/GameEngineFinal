#include "networkSync.h"

using namespace std;


networkSync::networkSync()
{

	if (enet_initialize() != 0)
	{
		cout << "Enet failed to initialise!" << "\n\n";
	}

	/* Much of this will be familiar from the server code. What differs
	is the inclusion of an Peer. This is basically ENet's way of tracking
	what you're connected to. Since our Client will be initialising the
	connection, they need a peer to store information about the server they're
	connecting to. */
	client = enet_host_create(NULL, 1, 2, 0, 0);

	if (client == NULL)
	{
		cout << "Client failed to initialise!" << "\n\n";
	}

	enet_address_set_host(&address, "localhost");
	address.port = 1234;

	peer = enet_host_connect(client, &address, 2, 0);

	if (peer == NULL) {
		cout << "No available peers for initializing an ENet connection.\n";
	}

}

void networkSync::networkUpdate()
{
	while (enet_host_service(client, &enetEvent, 0) > 0)
	{
		switch (enetEvent.type) {

		case ENET_EVENT_TYPE_RECEIVE:

			if (enetEvent.packet->dataLength == sizeof(Vector2))
			{
			ottherPlayer = true;
				newPosition = new Vector2;
				cout << "Movement Packet received!\n";
				memcpy(newPosition, enetEvent.packet->data, enetEvent.packet->dataLength);
				cout << newPosition->x << "," << newPosition->y << "\n";
			}

			if (enetEvent.packet->dataLength == sizeof(std::string))
			{
				newStage = new int;
				cout << "Level Change Packet recieved\n";
				memcpy(newStage, enetEvent.packet->data, enetEvent.packet->dataLength);

			}
			break;
		}
	}

	
}

void networkSync::givePosition(float x, float y)
{
	Vector2 newVector2;
	newVector2.x = x;
	newVector2.y = y;


	dataPacket = enet_packet_create(&newVector2, sizeof(newVector2), ENET_PACKET_FLAG_RELIABLE);
	enet_host_broadcast(client, 0, dataPacket);
}

void networkSync::giveLevel(int stageToSwitchTo)
{
	dataPacket = enet_packet_create(&stageToSwitchTo, sizeof(int), ENET_PACKET_FLAG_RELIABLE);
	enet_host_broadcast(client, 0, dataPacket);
}

void networkSync::disconnect()
{

	if (peer != NULL)
	{
		enet_peer_disconnect_now(peer, 0);
	}
	enet_host_destroy(client);
	atexit(enet_deinitialize);
}


networkSync::~networkSync()
{
}
