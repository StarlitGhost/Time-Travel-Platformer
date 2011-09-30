#pragma once

#include <string>

namespace FlatWorld
{
	class IMessagingSystem
	{
	public:
		void SendMessage(IMessagingSystem* obj, std::string msg)
		{
			SendMessage(obj, msg, 0, 0);
		}
		template <typename T>
		void SendMessage(IMessagingSystem* obj, std::string msg, T tData)
		{
			SendMessage(obj, msg, &tData, (unsigned int)sizeof(T));
		}
		template <>
		void SendMessage<char*>(IMessagingSystem* obj, std::string msg, char* cData)
		{
			SendMessage(obj, msg, cData, (unsigned int)strlen(cData) + 1);
		}
		void SendMessage(IMessagingSystem* obj, std::string msg, void* data, unsigned int size);

		virtual void ReceiveMessage(std::string msg, void* data, unsigned int size) = 0;

	};
}
