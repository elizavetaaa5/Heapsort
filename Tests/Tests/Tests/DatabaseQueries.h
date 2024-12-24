#pragma once /* #pragma once Ч это директива препроцессора, котора€ указывает компил€тору включить файл
заголовка только один раз при компил€ции файла исходного кода */

// ѕодключаемые библиотеки
#include <string>

using namespace std; /* Using namespace std в C++ Ч это директива, котора€ позвол€ет использовать
все идентификаторы из пространства имЄн std без указани€ префикса std:: */


// ќбъ€влени€ функций, расположенных в файле .cpp
void SetArraysToDB(string UnsortedArray, string SortedArray);