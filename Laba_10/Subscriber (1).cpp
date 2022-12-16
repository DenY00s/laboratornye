#include "Subscriber.h"

namespace dn {
	Subscriber::Subscriber(std::string firstName, std::string lastName) : m_firstName(firstName), m_lastName(lastName)
	{
		std::cout
			<< "Подписчик: "
			<< m_firstName << ' '
			<< m_lastName << ' '
			<< "создан"
			<< std::endl;
	};

	Subscriber::~Subscriber()
	{
		std::cout
			<< "Подписчик: "
			<< m_firstName << ' '
			<< m_lastName << ' '
			<< "удалён"
			<< std::endl;
	}
}