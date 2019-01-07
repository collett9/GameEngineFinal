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
		}
	}
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
