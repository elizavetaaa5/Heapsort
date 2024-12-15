#pragma once //это директива препроцессора,  которая указывает компилятору включить файл заголовка только один раз при компиляции файла  исходного кода

//Подключаемые библиотеки проекта
#include "MenuItems.h"

using namespace std;

template <typename T> //Объявление шаблона

//Объявление функций для проверки корректности ввода пунктов меню
T GetInput(void); 
int GetInt(void);
MainMenuItem GetMainMenuItem(void);
SecondMenuItem GetSecondMenuItem(void);
WriteDataMenuItem GetWriteDataMenuItem(void);
ExistFile GetExitsFileItem(void);
