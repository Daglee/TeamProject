#pragma once
#include "Message.h"
#include "MessageStorage.h"

//exposed interface
class Postman 
{
public:
	virtual void broadcastMessage(Message* message) = 0;
	virtual void sendMessage(Message* message, std::string bufferID) = 0;


};