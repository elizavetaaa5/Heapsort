//Директивы препроцессора
#include <iostream>

//Подключаемые библиотеки проекта
#include "Functions.h"
#include "InputValidation.h"
#include "MenuItems.h"
#include "Testing.h"

using namespace std; //позволяет использовать все идентификаторы  из пространства имён std без указания префикса std::

/// <summary>ShowGreeting - Функция вывода текста приветствия </summary>
void ShowGreeting(void) {
	cout << "Добро пожаловать в программу Пирамидной сортировки!" << endl << endl;
	cout << "Разработали:" << endl;
	cout << "Леготкина Елизавета Алексеевна," << endl;
	cout << "Мелюшенок Ксения Сергеевна" << endl;
	cout << "Группа: 434" << endl;
	cout << "Лабораторная работа №2" << endl;
	cout << "Вариант: 2" << endl << endl;
}

/// <summary>Entering - Функция выбора способа заполнения массива </summary>
void Entering(void) {

	SecondMenuItem UserChoice = static_cast<SecondMenuItem>(0);

	do {

		cout << "[1] - Заполнить массив вручную" << endl;
		cout << "[2] - Заполнить массив случайными значениями" << endl;
		cout << "Выберите пункт меню: ";

		UserChoice = GetSecondMenuItem();

		switch (UserChoice) {
		case ManualArray:
			ManualEntering();
			break;
		case RandomArray:
			RandomEntering();
			break;
		default:
			cout << "Введённый пункт не найден. Повторите ввод." << endl;
			break;
		}
	} while ((UserChoice != ManualArray) && (UserChoice != RandomArray));

}


/// <summary>StartStarting - Функция главного меню</summary>
void StartProgram(void) {

	MainMenuItem UserChoice = static_cast<MainMenuItem>(0);

	do {
		cout << " ____________|ГЛАВНОЕ МЕНЮ|____________ " << endl;
		cout << "|                                      |" << endl;
		cout << "| 1 - Выполнить программу              |" << endl;
		cout << "| 2 - Выполнить тестирование программы |" << endl;
		cout << "| 3 - Завершить работу программы       |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "Выберите пункт меню: ";

		UserChoice = GetMainMenuItem();
		switch (UserChoice) {
		case Solving:
			Entering();
			break;

		case Test:
			Testing();
			break;

		case Quit:
			cout << "Завершение работы" << endl;
			break;

		default:
			cout << "Введённый пункт не найден. Повторите ввод:" << endl;
			break;
		}
	} while (UserChoice != Quit);
}

