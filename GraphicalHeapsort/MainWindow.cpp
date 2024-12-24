// ѕодключаемые формы
#include "MainWindow.h"

// ѕодключенные пространства имен
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute] /* STAThreadAttribute в C++ указывает,
			что потокова€ модель дл€ приложени€
			€вл€етс€ однопотоковым подразделением (STA).
			Ётот атрибут должен присутствовать на
			точке входа любого приложени€, использующего
			Windows Forms. ≈сли он отсутствует,
			компоненты Windows могут работать неправильно. */

	// <summary> WinMain - точка входа в программу </summary>
	/* <param name = "arg - массив указателей, который хранит все переданные аргументы командной строки 
	в виде строк"></param>*/
	void __clrcall WinMain(System::String^ arg) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GraphicalHeapsort::MainWindow MainForm;
	Application::Run(% MainForm);

}

