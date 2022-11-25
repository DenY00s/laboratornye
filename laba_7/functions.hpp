#pragma once

#define S 3
#define N 3

namespace functions {
	//функция чтения из консоли
	void read(int A[S][N]);

	//функция записи в консоль
	void print(int A[S][N]);

	//функция, которая печатает линию
	void printLine();

	//функция, которая проверяет является ли число простым
	bool isPrime(int number);

	//функция, которая возвращает сумму элементов строки
	int getSumOfRow(int A[S][N], int rowIndex);

	//функция, которая возвращает норму столбца
	int getNorm(int A[S][N], int columnIndex);

	//функция, которая меняет местами значения в переменных
	void swap(int& left, int& right);

	//функция, которая меняет местами столбцы матрицы
	void swapColums(int A[S][N], int firstColumnIndex, int secondColumnIndex);

	//функция, сортирующая столбцы матрицы по невозрастанию нормы
	void sort(int A[S][N]);
}