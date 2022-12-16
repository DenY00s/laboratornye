#include "Provider.h"

int main() {
	setlocale(LC_ALL, "Russian");

	dn::Provider* provider = new dn::Provider("Ростелеком");

	dn::Subscriber* subscriber1 = new dn::Subscriber("Иван", "Иванов");
	dn::Subscriber* subscriber2 = new dn::Subscriber("Дмитрий", "Петров");
	dn::Subscriber* subscriber3 = new dn::Subscriber("Василий", "Сидоров");

	provider->addSubscriber(subscriber1);
	provider->addSubscriber(subscriber2);
	provider->addSubscriber(subscriber3);

	delete provider;
}