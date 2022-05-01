#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

class MainWindow;

#include "Enum_Packets.h"
#include "Ticket.h"
//#include "SharedFunctions.cpp"

using namespace std;

#define DEFAULT_PORT 27015
#define LOCALHOST "127.0.0.1"

class Client
{
public:
    Client(const char* serverAddress, int PORT, MainWindow* ptr);
	bool Connect();
	inline void StartSubRoutine() { clientThread = std::thread(ClientHandler); }

	bool SendString(const std::string& value);
	bool GetBool(bool& value);

	bool LoginResponse();
    friend bool Login(MainWindow* ui);
    friend class MainWindow;
    friend void  TransferTickets(Client* clientPtr, MainWindow* windowPtr);
private:
	bool ProcessPacket(PACKET_HEADER packetType);
	static void ClientHandler();

	bool SendInt(const int& value) const;
	bool GetInt(int& value);
	bool SendBool(bool value);
	bool SendPacketType(const PACKET_HEADER& packetType);
	bool GetPacketType(PACKET_HEADER& packetType);
	bool GetString(std::string& value);
	bool CloseConnection();
    bool GetVectorTicket(vector<Ticket>& ticketVector);
    bool SendVectorTicket(vector<Ticket> ticketVector);
    bool GetTicket(Ticket& ticket);
    bool SendTicket(Ticket ticket);

	int iResult;
	SOCKET ServerConnection;
	addrinfo* result = NULL;
	addrinfo* ptr = NULL;
	addrinfo hints;
	std::thread clientThread;
    vector<Ticket> ticketVector;

    MainWindow* mainWindowPtr;
};

static string serverIP;
static Client* clientPtr;
