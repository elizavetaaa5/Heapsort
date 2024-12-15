#pragma once //это директива препроцессора, которая указывает компилятору включить файл заголовка только дин раз при компиляции файла исходного кода

//Директивы препроцессора
#include <string>

using namespace std;

//Объявление функций, описанных в Functions.cpp
string IsFileExist(void);
void TheListToFile(int* FileArray, int SizeOfArray);
void RandomEntering(void);
void Heapify(int Array[], int n, int i);
void HeapSort(int Array[], int n);
void ShowSortedArray(int* SortedArray, int SizeOfArray);
void ManualEntering(void);