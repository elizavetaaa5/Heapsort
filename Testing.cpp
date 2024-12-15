//��������� �������������
#include <iostream>

//������������ ���������� �������
#include "Functions.h"

using namespace std; //��������� ������������ ��� �������������� �� ������������ ��� std ��� �������� �������� std::

/// <summary>CompletionArrayOfArrays - ������� ��� ���������� ������� ����������� �� ������</summary>
/// <param name="ArrayOfArrays"> - ������ ���������� �� ������</param>
/// <param name="FirstOfArray"> - ������ ��������� �� ������</param>
/// <param name="SecondOfArray"> - ������ ��������� �� ������</param>
/// <param name="ThirdOdArray"> - ������ ��������� �� ������</param>
/// <param name="FourthOfArray"> - ��������� ��������� �� ������</param>
/// <param name="FifthOfArray"> - ����� ��������� �� ������</param>
void CompletionArrayOfArrays(int** ArrayOfArrays, int* FirstOfArray, int* SecondOfArray, int* ThirdOdArray, int* FourthOfArray, int* FifthOfArray) {
	ArrayOfArrays[0] = FirstOfArray;
	ArrayOfArrays[1] = SecondOfArray;
	ArrayOfArrays[2] = ThirdOdArray;
	ArrayOfArrays[3] = FourthOfArray;
	ArrayOfArrays[4] = FifthOfArray;
}

/// <summary>Testing - ������� ������������ ����������</summary>
void Testing(void) {

	bool IsTestFine = true; //�������� �������� true, ����� ����� ��������� ��� ������

	int size = 5; //������� ��������

	int* FirstOfArray = new int[size] { 5, 9, -4, 2, 13};
	int* SecondOfArray = new int[size] { 16, 5, 12, -5, -1};
	int* ThirdOdArray = new int[size] { 1, 7, 3, 0, -7};
	int* FourthOfArray = new int[size] { 2, 1, 18, -1, 0};
	int* FifthOfArray = new int[size] { 2, 1, 0, -1, 8};

	int** ArrayOfArrays = new int* [size];
	CompletionArrayOfArrays(ArrayOfArrays, FirstOfArray, SecondOfArray, ThirdOdArray, FourthOfArray, FifthOfArray);

	for (int i = 0; i < size; i++) HeapSort(ArrayOfArrays[i], size);

	int* TrueFirstOfArray = new int[size] { -4, 2, 5, 9, 13};  //������ ��������� �� ������ � �������� ��������� ����������
	int* TrueSecondOfArray = new int[size] { -5, -1, 5, 12, 16};
	int* TrueThirdOdArray = new int[size] { -7, 0, 1, 3, 7};
	int* TrueFourthOfArray = new int[size] { -1, 0, 1, 2, 18 };
	int* TrueFifthOfArray = new int[size] { -1, 0, 1, 2, 8};

	int** ArrayOfTrueArrays = new int* [size]; //������ ���������� �� ������
	CompletionArrayOfArrays(ArrayOfTrueArrays, TrueFirstOfArray, TrueSecondOfArray, TrueThirdOdArray, TrueFourthOfArray, TrueFifthOfArray);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ArrayOfArrays[i][j] != ArrayOfTrueArrays[i][j]) {
				cout << "������ ��� ������������ � ������� " << i + 1 << "." << endl
					<< "���������: " << ArrayOfTrueArrays[i][j] << endl
					<< "��������: " << ArrayOfArrays[i][j] << endl;
				IsTestFine = false;
			}
		}
	}

	if (IsTestFine) cout << "����� ��������� �������." << endl;

}