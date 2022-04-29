#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <stdio.h>

#include "Server.h"
#include "SQLServer.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 27015


int main(void)
{
	//auto sqlServer = SQLServer::getInstance();
	//string email = "technician3@mail.com";
	//string passwd = "abcde";

	//sqlServer->AuthenticateUser(email, passwd);
	//return 0;
	//
	Server server(DEFAULT_PORT);

	for (int i = 0; i < 100; i++)
	{
		server.ListenForNewConnection();
	}

	return 0;
}