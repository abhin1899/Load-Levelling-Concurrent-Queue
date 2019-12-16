#include "Message.h"

Message::Message(int client_id, string message, int message_id) : client_id(client_id), message(message), message_id(message_id) {};

Message::Message() = default;

string Message::getMessage()
{
	return message;
}

int Message::getMessageID()
{
	return message_id;
}
 
 int Message::getClientID()
{
	return client_id;
}
 
 