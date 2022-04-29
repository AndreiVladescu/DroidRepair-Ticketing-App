#include "Client.h"
#include <conio.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

Client* myClient;

#define DEFAULT_PORT 27015
#define LOCALHOST "127.0.0.1"

void Login()
{
	string email, password;
	bool userLogged = false;
	bool passAccepted = false;
	while (userLogged == false) {
		myClient->SendPacketType(Login_Client_Request);
		cout << "Provide email:" << endl;
		getline(cin, email);
		myClient->SendString(email);
		cout << "Provide password:" << endl;
		getline(cin, password);
		myClient->SendString(password);

		//PACKET_HEADER packetType;
		//myClient->GetPacketType(packetType);
		myClient->GetBool(userLogged);
	}

	//cout << "Connection established between server and client" << endl;
}

int main(int argc, char** argv)
{
	myClient = new Client(LOCALHOST, DEFAULT_PORT);

	if (!myClient->Connect())
	{
		system("pause");
		return 1;
	}

	//SecureUsername();
	Login();
	myClient->StartSubRoutine();

	//Receive and create messages
	//std::string buffer;
	//while (true)
	//{
	//	std::getline(std::cin, buffer); // get line from cmd console

	//	/*if (buffer[0] == '@')
	//	{
	//		buffer.erase(0, 1);
	//		if (!myClient->SendDirectMessage(buffer))
	//			break;
	//	}
	//	else
	//	{*/
	//	if (!myClient->SendString(buffer))
	//		break; // leave as server conn lost
	////}
	//}

	_getch();


	// cleanup
	WSACleanup();

	return 0;
}