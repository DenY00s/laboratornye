#include <iostream>
#include "functions.hpp"

int main()
{

	int A[S][N];
	functions::read(A);

	functions::printLine();


	functions::print(A);


	for (size_t i = 0; i < S; i++)
	{
		for (size_t j = 0; j < N; j++)
		{

			if (functions::isPrime(A[i][j]) && functions::getSumOfRow(A, i) == 0)
			{

				functions::sort(A);

				functions::printLine();
				functions::print(A);
				functions::printLine();

				return 0;
			}
		}
	}
}
