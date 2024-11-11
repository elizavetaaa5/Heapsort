//Директивы препроцессора
#include <iostream>
#include <filesystem>
#include <string>

//Подключаемые библиотеки проекта
#include "MenuItems.h"

using namespace std; //позволяет использовать все идентификаторы  из пространства имён std без указания префикса std::


template <typename T> //Объявление шаблона

//Функция на проверку ввода с использованием шаблона
T GetInput(void) {
	T UserInput{};
	cin >> UserInput;
	if (cin.fail()) {
		cout << "Ошибка обработки ввода. Введите корректные данные: ";
		while (cin.fail()) {
			cin.clear();               //Функция, убирающая статус ошибки
			cin.ignore(INT_MAX, '\n'); //Функция, игнорирующая следующие символы в потоке ввода до int_max или enter
			cin >> UserInput;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return UserInput;
}

/// <summary>GetInt - Функция на проверку целочисленного ввода с использованием шаблонной функции</summary>
int GetInt(void) {
	return GetInput<int>();
}

/// <summary>GetMainMenuItem - Функция на проверку ввода пункта главного меню с использованием функции на проверку ввода целого числа</summary>
MainMenuItem GetMainMenuItem(void) {
	return static_cast<MainMenuItem>(GetInt());
}

/// <summary>GetSecondMenuItem - Функция на проверку ввода пункта второго меню с использованием функции на проверку ввода целого числа</summary>
SecondMenuItem GetSecondMenuItem(void) {
	return static_cast<SecondMenuItem>(GetInt());
}


/// <summary>GetWriteDataItem - Функция на проверку ввода пункта меню для выбора записи с использованием функции на проверку ввода целого числа </summary>
WriteDataMenuItem GetWriteDataMenuItem(void) {
	return static_cast<WriteDataMenuItem>(GetInt());
}


/// <summary>GetExistFileItem - Функция на проверку ввода пункта меню для выбора места для записи с использованием функции на проверку ввода целого числа </summary>
ExistFile GetExitsFileItem(void) {
	return static_cast<ExistFile>(GetInt());
}
