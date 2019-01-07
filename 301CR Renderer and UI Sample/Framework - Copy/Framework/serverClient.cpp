#include "serverClient.h"



void serverClient::serverUpdate()
{

	while (enet_host_service(server, &enetEvent, 0) > 0)
	{
		switch (enetEvent.type)
		{
		case ENET_EVENT_TYPE_CONNECT:

			cout << "A client connected from address " << enetEvent.peer->address.host << ":" << enetEvent.peer->address.port << ".\n";



			enetEvent.peer->data = "This is a client";

			break;
		case ENET_EVENT_TYPE_DISCONNECT:
			cout << "The client from address " << enetEvent.peer->address.host << ":" << enetEvent.peer->address.port << " disconnected \n";

			enetEvent.peer->data = NULL;

			break;
		}
	}
}

void serverClient::killServer()
{

	enet_host_destroy(server);
	atexit(enet_deinitialize);

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
