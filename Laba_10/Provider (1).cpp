#include "Provider.h"

namespace dn {
	Provider::Provider(std::string name) : m_name(name)
	{
		std::cout << "Провайдер: " << m_name << ' ' << "создан" << std::endl;
	}

	Provider::~Provider()
	{
		std::cout << "Провайдер: " << m_name << ' ' << "удалён" << std::endl;

		for (int i = 0; i < m_subscribers.size(); i++)
		{
			delete m_subscribers[i];
		}
	}
	
	void Provider::addSubscriber(Subscriber* subscriber)
	{
		m_subscribers.push_back(subscriber);
	}
}