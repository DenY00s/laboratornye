#pragma once
#include <iostream>

namespace dn {
	class Subscriber
	{
	private:
		std::string m_firstName;
		std::string m_lastName;
	public:
		Subscriber(std::string firstName, std::string lastName);
		~Subscriber();
	};
}