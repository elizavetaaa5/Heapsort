//Директивы препроцессора
#include <iostream>                 
#include <random>                   
#include <string>                   
#include <filesystem>
#include <fstream>


//Подключаемые библиотеки проекта
#include "MenuItems.h"
#include "InputValidation.h"

#define RangeForSize 10
#define MinimumForSize 6

#define RangeForElements 100
#define MinimumForElements 50

//Пространства имен
using namespace std;
using namespace filesystem;

/// <summary>IsFileExist - Функция выбора адреса для записи данных</summary>
string IsFileExist(void) {

    ExistFile UserChoice = static_cast<ExistFile>(0);
    string FilePath;

    bool TryOtherFile = false;
    bool IsDataSaved = false;

    do {
        cout << "Введите относительный или абсолютный путь файла: ";
        getline(cin, FilePath);

        if (fstream(FilePath)) {

            cout << "Файл уже существует" << endl;

            do {
                cout << "[1] - Перезаписать существующий файл" << endl;
                cout << "[2] - Выбрать другой файл" << endl;
                cout << "Выберите пункт меню: ";

                UserChoice = GetExitsFileItem();
                if ((UserChoice != NewFile) && (UserChoice != Overwriting)) {
                    cout << "Выбранный пункт не найден. Повторите ввод: " << endl;
                }

            } while ((UserChoice != NewFile) && (UserChoice != Overwriting));

            if (UserChoice == NewFile) {
                TryOtherFile = true;
                continue;
            }
        }

        /*
    ifstream: для чтения с файла
    ofstream : для записи в файл
    fstream : совмещает запись и чтение
    */

    //Открытие для записи и объявление переменной хранящей в себе статус ошибки
        ofstream MyFile(FilePath.c_str());
        error_code ec{};

        if (!is_regular_file(FilePath, ec)) {
            cout << "Адрес содержит недопустимые значения" << endl;
            continue;
        }

        if (!MyFile) {
            cout << "Запись в этот файл недоступна" << endl;
            MyFile.close();
            continue;
        }
        IsDataSaved = true;
    } while (!IsDataSaved);

    return FilePath;
}

/// <summary>TheListToFile - Функция записи данных в файл</summary>
/// <param name="FileArray"> - Записываемый в файл массив</param>
/// <param name="SizeOfArray"> - Записываемый в файл размер массива</param>
void TheListToFile(int* FileArray, int SizeOfArray) {

    WriteDataMenuItem UserChoice = static_cast<WriteDataMenuItem>(0);
    string PathName = "";
    ofstream File;

    cout << "Записать данные в файл?" << endl;
    cout << "[1] - Записать данные в файл" << endl;
    cout << "[2] - Продолжить без записи" << endl;
    cout << "Выберите пункт меню: ";
   
    do {
        UserChoice = GetWriteDataMenuItem();
        switch (UserChoice) {
        case Writing:
            cout << "Сохранение в файл" << endl;
            PathName = IsFileExist();
            /*
       ios_base::in     - открыть файл для чтения
       ios_base::out    - открыть файл для записи
       ios_base::ate    - при открытии переместить указатель в конец файла
       ios_base::app    - открыть файл для записи в конец файла
       ios_base::trunc	 - удалить содержимое файла, если он существует
       ios_base::binary - открытие файла в двоичном режиме
       */
            File.open(PathName.c_str(), ios_base::trunc | ios_base::out);
            if (File.is_open()) {
                File << SizeOfArray << endl;
                File << "[ ";
                for (int i = 0; i < SizeOfArray; i++) File << FileArray[i] << " ";
                File << "]";
                cout << "Данные сохранены" << endl;
                File.close();
            }
            else {
                cout << "Файл недоступен для записи" << endl;
                File.close();
            }
            break;
        case Cancelling:
            continue;
            break;

        default:
            cout << "Введённый пункт отсутствует. Повторите ввод: ";
            break;
        }

    } while ((UserChoice != Writing) && (UserChoice != Cancelling));
}

/// <summary>ShowSortedArray - Функция вывода отсортированного массива</summary>
/// <param name="SortedArray"> - Отсортированный массив</param>
/// <param name="SizeOfArray"> - Размер массива</param>
void ShowSortedArray(int* SortedArray, int SizeOfArray) {
    cout << "Отсортированный массив: [ ";
    for (int i = 0; i < SizeOfArray; i++) cout << SortedArray[i] << " ";
    cout << "]" << endl;
}

/// <summary>Heapify - Функция для построения кучи</summary>
/// <param name="Array"> - массив </param>
/// <param name="n"> - число </param>
/// <param name="i"> - корень </param>
void Heapify(int Array[], int n, int i) {
    int largest = i; // Инициализируем largest как корень
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && Array[left] > Array[largest])
        largest = left;

    // Если правый дочерний элемент больше largest
    if (right < n && Array[right] > Array[largest])
        largest = right;

    // Если largest не корень
    if (largest != i) {
        swap(Array[i], Array[largest]); // Обмениваем
        Heapify(Array, n, largest); // Рекурсивно хипируем затронутое поддерево
    }
}

/// <summary>HeapSort - Функция для выполнения пирамидальной сортировки</summary>
/// <param name="Array"> - массив </param>
/// <param name="n"> - число </param>
void HeapSort(int Array[], int n) {

    // Построение кучи (перевернутой бинарной)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(Array, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(Array[0], Array[i]); // Перемещаем текущий корень в конец
        Heapify(Array, i, 0); // Вызываем heapify на уменьшенной куче
    }
}


/// <summary>RandomEntering - Функция создания случайного массива</summary>
void RandomEntering(void) {

    int ArraySize = rand() % RangeForSize + rand() % MinimumForSize;
    cout << "Рандомайзер выбрал размер массива = " << ArraySize << endl;

    int* Array = new int[ArraySize];

    for (int i = 0; i < ArraySize; i++) {
        Array[i] = rand() % RangeForElements - MinimumForElements;
    }

    cout << "Рандомайзер заполнил массив: [ ";
    for (int i = 0; i < ArraySize; i++) {
        cout << Array[i] << " ";
    }
    cout << "]" << endl;

    HeapSort(Array, ArraySize);
    ShowSortedArray(Array, ArraySize);
    TheListToFile(Array, ArraySize);
}

/// <summary>ManualEntering - Функция заполнения массива с клавиатуры</summary>
void ManualEntering(void) {

    int ArraySize = 0;
    cout << "Введите размер массива: ";
    do {
        ArraySize = GetInt();
        if (ArraySize <= 0) cout << "Ошибка ввода. Повторите ввод: ";
    } while (ArraySize <= 0);

    int* Array = new int[ArraySize];

    for (int i = 0; i < ArraySize; i++) {
        cout << "Введите " << i + 1 << " элемент: ";
        Array[i] = GetInt();
    }

    cout << "Введенный массив: " << endl;
    cout << "[ ";
    for (int i = 0; i < ArraySize; i++) cout << Array[i] << " ";
    cout << "]" << endl;

    HeapSort(Array, ArraySize);
    ShowSortedArray(Array, ArraySize);
    TheListToFile(Array, ArraySize);
}

