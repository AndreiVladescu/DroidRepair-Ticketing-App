#pragma once
#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <stdio.h>

#include "../SharedLibs/Enum_Packets.h"
#include "SQLServer.h"

using namespace std;

class Server
{
public:
	Server(int PORT);
	bool ListenForNewConnection();

	std::vector<std::string> usernames = {};
	SQLServer* sqlServer = SQLServer::getInstance();
private:
#pragma region Winsock
	SOCKET Connections[100];
	std::thread connectionThreads[100];

	addrinfo* result;
	addrinfo hints;
	SOCKET ListenSocket;
	int iResult;

	int ConnectionCounter = 0;
#pragma endregion

	bool GetInt(int id, int& value);
	bool SendInt(int id, int value);
	bool SendBool(int id, bool value);
	bool GetBool(int id, bool& value);
	bool SendPacketType(int id, const PACKET_HEADER& packetType);
	bool GetPacketType(int id, PACKET_HEADER& packetType);
	bool SendString(int id, const std::string& value);
	bool GetString(int id, std::string& value);

	bool ProcessPacket(int index, PACKET_HEADER packetType);

	bool LoginClient(int index);

	bool CloseConnection(int index);

	static void ClientHandler(int index);
};

static Server* serverPtr;