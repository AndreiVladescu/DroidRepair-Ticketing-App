#include "Client.h"

Client::Client(const char* serverAddress, int PORT, MainWindow* windowPtr)
{
	WSADATA wsaData;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(0);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(serverAddress, std::to_string(PORT).c_str(), &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
	}

	clientPtr = this;
    this->mainWindowPtr = windowPtr;
}

bool Client::Connect()
{
	bool connected = false;

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{

		// Create a SOCKET for connecting to server
		ServerConnection = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ServerConnection == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return false;
		}

		// Connect to server.
		iResult = connect(ServerConnection, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			std::cout << "Could not connect to server, error: " << WSAGetLastError() << std::endl;
			closesocket(ServerConnection);
			ServerConnection = INVALID_SOCKET;
			continue;
		}
		else
		{
			connected = true;
			break;

		}
	}

	return connected;
}

bool Client::ProcessPacket(PACKET_HEADER packetType)
{
	switch (packetType)
	{
	case Login_Server_Response:
	{
		if (!LoginResponse())
			return false;

		break;
	}
    case Send_Ticket_Vector_Response:
    {
        //TransferTickets(this, this->mainWindowPtr);
        this->GetVectorTicket(this->ticketVector);
        TransferTickets(this, this->mainWindowPtr);
        break;
    }
	default:
        std::cout << "Unrecognized packet: " << packetType << std::endl;
	}
	return true;
}

bool Client::LoginResponse()
{
	bool rb;
	GetBool(rb);
	if (rb) {
		cout << "Connected" << endl;
	}
	else {
		cout << "Didn't work" << endl;
	}
	return true;
}

void Client::ClientHandler()
{
	PACKET_HEADER packetType;
	while (true)
	{
		//get type
		if (!clientPtr->GetPacketType(packetType))
			break;
		//procees package type
		if (!clientPtr->ProcessPacket(packetType))
			break;
	}

	//lost connection or error occured

	std::cout << "Lost connection to the server" << std::endl;
	if (clientPtr->CloseConnection())
	{
		std::cout << "Socket to server was closed successfully" << std::endl;
	}
}

bool Client::SendString(const std::string& value)
{
	int bufferLength = value.size();
	if (!SendInt(bufferLength))
		return false;

	int returnCheck = send(ServerConnection, value.c_str(), bufferLength, NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::SendInt(const int& value) const
{
	int returnCheck = send(ServerConnection, (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::GetInt(int& value)
{
	int returnCheck = recv(ServerConnection, (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::SendPacketType(const PACKET_HEADER& packetType)
{
	int returnCheck = send(ServerConnection, (char*)&packetType, sizeof(PACKET_HEADER), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::GetPacketType(PACKET_HEADER& packetType)
{
	int returnCheck = recv(ServerConnection, (char*)&packetType, sizeof(PACKET_HEADER), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::GetString(std::string& value)
{
	int bufferLength = 0;
	if (!GetInt(bufferLength))
		return false;

	char* buffer = new char[bufferLength + 1]; // +1 to allow for terminating '/0'
	buffer[bufferLength] = '\0';

	int returnCheck = recv(ServerConnection, buffer, bufferLength, NULL);
	value = buffer;
	delete[] buffer;

	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::SendBool(bool value)
{
	int returnCheck = send(ServerConnection, (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::GetBool(bool& value)
{
	int returnCheck = recv(ServerConnection, (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Client::SendVectorTicket(vector<Ticket> ticketVector)
{
    int elCount = ticketVector.size();
    if (!SendInt(elCount))
        return false;

    for (int i = 0; i < elCount; i++) {
        SendTicket(ticketVector[i]);
    }

        return true;
}

bool Client::GetVectorTicket(vector<Ticket>& ticketVector)
{
    int elCount;
    if (!GetInt(elCount))
        return false;

    ticketVector.reserve(elCount);

    while (elCount--) {
        Ticket tempTicket;

        GetTicket(tempTicket);

        ticketVector.push_back(tempTicket);
    }

    return true;
}


bool Client::SendTicket(Ticket ticket)
{
    if (!SendInt(ticket.getID()))
        return false;

    if (!SendInt(ticket.getClientID()))
        return false;

    if (!SendInt(ticket.getTechnicianID()))
        return false;

    if (!SendString(ticket.getCategory()))
        return false;

    if (!SendString(ticket.getProblem()))
        return false;

    if (!SendString(ticket.getSolution()))
        return false;

    if (!SendString(ticket.getClientEmail()))
        return false;

    return true;
}

bool Client::GetTicket(Ticket& ticket)
{
    int tempInt;
    string tempString;
    if (!GetInt(tempInt))
        return false;

    ticket.setID(tempInt);

    if (!GetInt(tempInt))
        return false;

    ticket.setClientID(tempInt);

    if (!GetInt(tempInt))
        return false;

    ticket.setTechnicianID(tempInt);

    if (!GetString(tempString))
        return false;

    ticket.setCategory(tempString);

    if (!GetString(tempString))
        return false;

    ticket.setProblem(tempString);

    if (!GetString(tempString))
        return false;

    ticket.setSolution(tempString);

    if (!GetString(tempString))
        return false;

    ticket.setClientEmail(tempString);

    return true;
}

bool Client::CloseConnection()
{
	if (closesocket(ServerConnection == SOCKET_ERROR))
	{
		if (WSAGetLastError() == WSAENOTSOCK)
			return true;

		std::cout << "Failed to close the socket. Winsock Error: " << std::to_string(WSAGetLastError()) << std::endl;
		return false;
	}

	return true;
}
