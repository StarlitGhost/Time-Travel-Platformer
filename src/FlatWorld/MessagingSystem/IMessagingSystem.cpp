#include "MessagingSystem/IMessagingSystem.h"

using namespace FlatWorld;

void FlatWorld::IMessagingSystem::SendMessage(IMessagingSystem* obj, std::string msg, void* data, unsigned int size)
{
	this->ReceiveMessage(msg, data, size);
}
