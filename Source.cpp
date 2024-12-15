/*************************************\
* ФИО: Леготкина E.А и Мелюшенок К.С  *
* Группа: 434                         *
* Контрольная работа 2                *
* Вариант: 2                          *
* Название: Heapsort.cpp              *
\*************************************/

//Директивы препроцессора
#include <iostream>
#include <Windows.h>

//Подключаемые библиотеки проекта
#include "MenuInterface.h"

/// <summary>main - Главная функция, точка входа в программу</summary>
int main(void) {

	SetConsoleCP(1251);			// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

	ShowGreeting();
	StartProgram();

	system("PAUSE");
	return EXIT_SUCCESS;
}