#pragma once //это директива препроцессора,  которая указывает компилятору включить файл заголовка только один раз при компиляции файла  исходного кода

//Объявление переменных перечислимого типа - вспомогательных переменных для пунктов меню
enum MainMenuItem { Solving = 1, Test, Quit };

enum SecondMenuItem { ManualArray = 1, RandomArray };

enum ExistFile { Overwriting = 1, NewFile };

enum WriteDataMenuItem { Writing = 1, Cancelling };
