#pragma once
enum PACKET
{
	P_ChatMessage,
	P_DirectMessage
};

typedef enum PACKET_HEADER {
	Login_Client_Request,
	Login_Server_Response,
};