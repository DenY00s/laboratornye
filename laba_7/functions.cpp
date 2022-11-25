#include <iostream>
#include "functions.hpp"

namespace functions
{
	//функция чтения из консоли
	void read(int A[S][N])
	{
		
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < N; j++)
			{
				 std::cin >> A[i][j]; 
			}
		}
	}

	//функция записи в консоль
	void print(int A[S][N])
	{
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < N; j++)
			{
				std::cout << A[i][j];

				if (j != N - 1) std::cout << ' '; 
			}
			std::cout << std::endl;
		}
	}

	//функция, которая печатает линию
	void printLine()
	{
		std::cout << "_________________" << std::endl;
	}

	//функция, которая проверяет является ли число простым
	bool isPrime(int number)
	{
		if (number < 2)
		{
			return false;
		}
		for (int d = 2; d <= sqrt(number); d++)
		{
			if (number % d == 0)
				return false;
		}
		return true;
	}

	//функция, которая возвращает сумму элементов строки
	int getSumOfRow(int A[S][N], int rowIndex)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += A[rowIndex][i];
		}
		return sum;
	}

	//функция, которая возвращает норму столбца
	int getNorm(int A[S][N], int columnIndex)
	{
		int norm = 0;

		for (int i = 0; i < S; i++)
		{
			norm += (int)pow((float)A[i][columnIndex], 2.f);
		}

		return sqrt(norm);
	}

	//функция, которая меняет местами значения в переменных
	void swap(int& left, int& right)
	{
		int pomenyat = left;
		left = right;
		right = pomenyat;
	}

	//функция, которая меняет местами столбцы матрицы
	void swapColums(int A[S][N], int firstColumnIndex, int secondColumnIndex)
	{
		for (int i = 0; i < S; i++)
		{
			swap(A[i][firstColumnIndex], A[i][secondColumnIndex]);
		}
	}

	//функция, сортирующая столбцы матрицы по невозрастанию нормы
	void sort(int A[S][N])
	{
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (getNorm(A, i) < getNorm(A, j))
				{
					swapColums(A, i, j);
				}
			}
		}
	}
}