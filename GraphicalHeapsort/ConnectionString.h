#pragma once /* #pragma once Ч это директива препроцессора, котора€ указывает компил€тору включить файл
заголовка только один раз при компил€ции файла исходного кода */

// ѕодключаемые библиотеки
#include <string>

// »спользованные пространства имен
using namespace std;
using namespace System;

// ќбъ€влени€ функций, наход€щихс€ в файле .cpp
string ToStdstring(String^ Line);


