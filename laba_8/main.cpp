#include <iostream>

int main() {
	// переменная типа long long
	long long value = LLONG_MAX;

	// размер long long: 8 байт
	for (int i = 0; i < 8; i++)
	{
		// приводим значение к указателю unsigned char, чтобы получить указатель на первый байт
		unsigned char* uc_ptr = (unsigned char*) &value;

		// перемещаем указатель вперёд на количество итераций
		uc_ptr += i;

		// производим разыименование указателя и приведение символьного значения к целому
		int byteValue = (int) *uc_ptr;

		// выводим полученное значение
		std::cout << "byte " << i + 1 << ": " << byteValue << std::endl;
	}
}
