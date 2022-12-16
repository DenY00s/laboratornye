#pragma once
#include "Subscriber.h"
#include <vector>

namespace dn {
	class Provider
	{
	private:
		std::string m_name;
		std::vector<Subscriber*> m_subscribers;
	public:
		Provider(std::string m_name);
		~Provider();
		void addSubscriber(Subscriber* subscriber);
	};
}