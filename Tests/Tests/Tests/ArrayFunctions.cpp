// Подключаемые библиотеки
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <windows.h>
#include <oledb.h>
#include <sstream>
#include <msclr\marshal_cppstd.h>
// Подключаемые файлы
#include "Heapsort.h"
#include "DatabaseQueries.h"
using namespace std; /* Using namespace std в C++ — это директива, которая позволяет использовать
все идентификаторы из пространства имён std без указания префикса std:: */

using namespace System::Data;
using namespace System::Data::OleDb;
using namespace System;

/// <summary>
/// Функция добавления массивов в базу данных
/// </summary>
/// <param name="num" - количество массивов для добавления></param>


void AddArrayToDB(int num) {

	// Запуск таймера
	auto start = std::chrono::steady_clock::now();

	// Добавление в таблицу num строчек
	for (int i = 0; i < num; i++) {
		int size = rand() % 101 + 1;
		int* UnsortedArray = new int[size];
		int* SortedArray = new int[size];
		for (int i = 0; i < size; i++) {
			UnsortedArray[i] = rand() % 20000 - 10000;
		}
		for (int i = 0; i < size; i++) {
			SortedArray[i] = UnsortedArray[i];
		}
		HeapSort(SortedArray, size);
		string UnsortedLine = "";
		string SortedLine = "";

		for (int i = 0; i < size; i++) {
			UnsortedLine += to_string(UnsortedArray[i]) + ' ';
		}
		for (int i = 0; i < size; i++) {
			SortedLine += to_string(SortedArray[i]) + ' ';
		}

		SetArraysToDB(UnsortedLine, SortedLine);
	}

	// Остановка таймера
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	auto diff_milsec = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	double diff_sec = static_cast<double>(diff_milsec) / 1000;
	cout << "Тест выполнен успешно" << endl;
	cout << "Время выполнения теста (в секундах): " << diff_sec << endl;
}

void GetArray() {

	// Запуск таймера
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < 100; i++) {

		auto p = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lea05\\Desktop\\GraphicalHeapsort\\Tests\\Tests\\Arrays.mdb");

		p->Open();
		// Добавление строки в таблицу
		String^ stringQuery = "SELECT * FROM [Таблица массивов];";

		String^ Query = gcnew String(stringQuery);

		OleDbCommand^ Command = gcnew OleDbCommand(Query, p);

		OleDbDataReader^ reader = Command->ExecuteReader();

		reader->Read();

		String^ UnsortedArray = (reader["UnsortedArray"])->ToString();

		p->Close();

		string arrayString;

		arrayString = msclr::interop::marshal_as<string>(UnsortedArray);

		// Преобразование строки в массив целых чисел
		vector<string> array;
		stringstream ss(arrayString);
		string number;
		while (getline(ss, number, ',')) {
			array.push_back(number);
		}
		int size = static_cast<int>(array.size());
		int* Array = new int[size];
		int number_1 = 0;
		for (int i = 0; i < size; i++) {
			number_1 = stoi(array[i]);
			Array[i] = number_1;
		}
		HeapSort(Array, size);

	}
	// Остановка таймера
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	auto diff_milsec = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	double diff_sec = static_cast<double>(diff_milsec) / 1000;
	cout << "Тест выполнен успешно" << endl;
	//cout << "Время выполнения теста для 1 массива (в секундах): " << diff_sec / 100 << endl;
	cout << "Время выполнения теста (в секундах): " << diff_sec << endl;
}

void DeleteArray() {
	// Запуск таймера
	auto start = std::chrono::steady_clock::now();

	auto p = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lea05\\Desktop\\GraphicalHeapsort\\Tests\\Tests\\Arrays.mdb");

	p->Open();
	// Добавление строки в таблицу
	string stringQuery = "DELETE FROM [Таблица массивов];";

	String^ Query = gcnew String(stringQuery.data());

	OleDbCommand^ Command = gcnew OleDbCommand(Query, p);

	Command->ExecuteReader();

	// Остановка таймера
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	auto diff_milsec = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	double diff_sec = static_cast<double>(diff_milsec) / 1000;
	cout << "Тест выполнен успешно" << endl;
	cout << "Время выполнения теста для 1 массива (в секундах): " << diff_sec / 100 << endl;
	cout << "Время выполнения теста (в секундах): " << diff_sec << endl;
}

// Конец файла