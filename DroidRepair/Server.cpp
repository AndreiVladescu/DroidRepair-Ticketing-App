#include "Server.h"

Server::Server(int PORT)
{
	WSADATA wsaData;

	ListenSocket = INVALID_SOCKET;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(0);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, std::to_string(PORT).c_str(), &hints, &result);
	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		exit(0);
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		exit(0);
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Bind failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}

	freeaddrinfo(result);

	//listen for incoming connection
	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}

	serverPtr = this;
}

bool Server::ListenForNewConnection()
{
	SOCKET ClientSocket = INVALID_SOCKET;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET)
	{
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return false;
	}

	else // sucessfull connection
	{
		std::cout << "Client connected" << std::endl;
		Connections[ConnectionCounter] = ClientSocket;
		//Getusername(ConnectionCounter);

		connectionThreads[ConnectionCounter] = std::thread(ClientHandler, ConnectionCounter);
		ConnectionCounter++;
		return true;
	}
}

bool Server::SendInt(int id, int value)
{
	int returnCheck = send(Connections[id], (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetInt(int id, int& value)
{
	int returnCheck = recv(Connections[id], (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendBool(int id, bool value)
{
	int returnCheck = send(Connections[id], (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetBool(int id, bool& value)
{
	int returnCheck = recv(Connections[id], (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendPacketType(int id, const PACKET_HEADER& packetType)
{
	int returnCheck = send(Connections[id], (char*)&packetType, sizeof(PACKET_HEADER), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetPacketType(int id, PACKET_HEADER& packetType)
{
	int returnCheck = recv(Connections[id], (char*)&packetType, sizeof(PACKET_HEADER), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendString(int id, const std::string& value)
{
	/*if (!SendPacketType(id, P_ChatMessage))
		return false;*/

	int bufferLength = value.size();
	if (!SendInt(id, bufferLength))
		return false;

	int returnCheck = send(Connections[id], value.c_str(), bufferLength, NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetString(int id, std::string& value)
{
	int bufferLength = 0;
	if (!GetInt(id, bufferLength))
		return false;

	char* buffer = new char[bufferLength + 1]; // +1 to allow for terminating '/0'

	int returnCheck = recv(Connections[id], buffer, bufferLength, NULL);
	buffer[bufferLength] = '\0';
	value = buffer;
	delete[] buffer;

	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::ProcessPacket(int index, PACKET_HEADER packetType)
{
	switch (packetType)
	{
	case Login_Client_Request:
	{
		if (!LoginClient(index)) {
			cout << "Failed login from " << index << endl;
		}
		break;
	}

	default:
		std::cout << "Unrecognized packet: " << packetType << std::endl;
		break;
	}
	return true;
}

bool Server::LoginClient(int index)
{
	string email, passwd;
	if (!GetString(index, email))
		return false;
	if (!GetString(index, passwd))
		return false;

	bool rb;
	rb = sqlServer->AuthenticateUser(email, passwd);


	SendBool(index, rb);
	if (rb) {
		cout << "Client " << index << " connected" << endl;
	}

	SendPacketType(index, Login_Server_Response);
	SendBool(index, true);


	//userIDs[index];
	return true;
}

bool Server::SendClientTickets(int index)
{


	return true;
}

bool Server::LinkClientToConnection(int index, string email)
{
	// Link user socket index to database id
	// = dynamic_cast<IUser*> (
	users[index] = new User;
	users[index]->setID(this->sqlServer->GetUserID(email));
	users[index]->setEmail(email);
	users[index]->setRole(this->sqlServer->GetUserRole(email));
	return true;
}

bool Server::CloseConnection(int index)
{
	if (users[index] != nullptr) {
		delete users[index];
		users[index] = nullptr;
	}
	if (closesocket(Connections[index]) == SOCKET_ERROR)
	{
		std::cout << "Failed closing Error: " << WSAGetLastError() << std::endl;
		return false;
	}

	return true;
}


//Bulk of work
void Server::ClientHandler(int index)
{
	PACKET_HEADER packetType;
	while (true)
	{
		//Receive Messages
		if (!serverPtr->GetPacketType(index, packetType))
			break;
		if (!serverPtr->ProcessPacket(index, packetType))
			break;
	}

	std::cout << "Lost contact with client: id = " << index << std::endl;
	serverPtr->CloseConnection(index);
}
