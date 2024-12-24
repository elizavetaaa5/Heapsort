// Подключаемые библиотеки
#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>

// Использованные пространства имен
using namespace std;
using namespace System;

/// <summary> ToStdstring - функция, выполняющая конвертацию System::String^ в std::string </summary>
/// <param name="Line - строка типа System::String^"></param>
string ToStdstring(String^ Line) {

	return msclr::interop::marshal_as<string>(Line);

}
