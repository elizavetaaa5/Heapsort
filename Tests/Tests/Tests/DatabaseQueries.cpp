// Подключаемые библиотеки
#include <string>

// Использованные пространства имен
using namespace std;
using namespace System::Data;
using namespace System::Data::OleDb;
using namespace System;

// <summary> SetArraysToDB - функция, сохраняющая массивы в базу данных </summary>
// <param name="UnsortedArray - неотсортированный массив"></param>
// <param name="SortedArray - отсортированный массив"></param>
void SetArraysToDB(string UnsortedArray, string SortedArray) {

	auto p = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lea05\\Desktop\\GraphicalHeapsort\\Tests\\Tests\\Arrays.mdb");

	p->Open();
	// Добавление строки в таблицу
	string stringQuery = "INSERT INTO [Таблица массивов] (UnsortedArray, SortedArray) VALUES ('" + UnsortedArray + "', '" + SortedArray + "')";

	String^ Query = gcnew String(stringQuery.data());

	auto Command = gcnew OleDbCommand(Query);
	Command->Connection = p;
	Command->ExecuteNonQuery();

	p->Close();

}