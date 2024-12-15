//Директивы препроцессора
#include <iostream>

//Подключаемые библиотеки проекта
#include "Functions.h"

using namespace std; //позволяет использовать все идентификаторы из пространства имён std без указания префикса std::

/// <summary>CompletionArrayOfArrays - Функция для заполнения массива указателями на массив</summary>
/// <param name="ArrayOfArrays"> - Массив указателей на массив</param>
/// <param name="FirstOfArray"> - Первый указатель на массив</param>
/// <param name="SecondOfArray"> - Второй указатель на массив</param>
/// <param name="ThirdOdArray"> - Третий указатель на массив</param>
/// <param name="FourthOfArray"> - Четвертый указатель на массив</param>
/// <param name="FifthOfArray"> - Пятый указатель на массив</param>
void CompletionArrayOfArrays(int** ArrayOfArrays, int* FirstOfArray, int* SecondOfArray, int* ThirdOdArray, int* FourthOfArray, int* FifthOfArray) {
	ArrayOfArrays[0] = FirstOfArray;
	ArrayOfArrays[1] = SecondOfArray;
	ArrayOfArrays[2] = ThirdOdArray;
	ArrayOfArrays[3] = FourthOfArray;
	ArrayOfArrays[4] = FifthOfArray;
}

/// <summary>Testing - Функция тестирования сортировки</summary>
void Testing(void) {

	bool IsTestFine = true; //Принимет значение true, когда тесты завершены без ошибок

	int size = 5; //Размеры массивов

	int* FirstOfArray = new int[size] { 5, 9, -4, 2, 13};
	int* SecondOfArray = new int[size] { 16, 5, 12, -5, -1};
	int* ThirdOdArray = new int[size] { 1, 7, 3, 0, -7};
	int* FourthOfArray = new int[size] { 2, 1, 18, -1, 0};
	int* FifthOfArray = new int[size] { 2, 1, 0, -1, 8};

	int** ArrayOfArrays = new int* [size];
	CompletionArrayOfArrays(ArrayOfArrays, FirstOfArray, SecondOfArray, ThirdOdArray, FourthOfArray, FifthOfArray);

	for (int i = 0; i < size; i++) HeapSort(ArrayOfArrays[i], size);

	int* TrueFirstOfArray = new int[size] { -4, 2, 5, 9, 13};  //Первый указатель на массив с заведомо истинными значениями
	int* TrueSecondOfArray = new int[size] { -5, -1, 5, 12, 16};
	int* TrueThirdOdArray = new int[size] { -7, 0, 1, 3, 7};
	int* TrueFourthOfArray = new int[size] { -1, 0, 1, 2, 18 };
	int* TrueFifthOfArray = new int[size] { -1, 0, 1, 2, 8};

	int** ArrayOfTrueArrays = new int* [size]; //Массив указателей на массив
	CompletionArrayOfArrays(ArrayOfTrueArrays, TrueFirstOfArray, TrueSecondOfArray, TrueThirdOdArray, TrueFourthOfArray, TrueFifthOfArray);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ArrayOfArrays[i][j] != ArrayOfTrueArrays[i][j]) {
				cout << "Ошибка при тестировании в массиве " << i + 1 << "." << endl
					<< "Ожидалось: " << ArrayOfTrueArrays[i][j] << endl
					<< "Получено: " << ArrayOfArrays[i][j] << endl;
				IsTestFine = false;
			}
		}
	}

	if (IsTestFine) cout << "Тесты завершены успешно" << endl;

}