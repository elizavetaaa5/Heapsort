// Подключаемые библиотеки
#include <iostream>

using namespace std; /* Using namespace std в C++ — это директива, которая позволяет использовать
все идентификаторы из пространства имён std без указания префикса std:: */


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
        Heapify(Array, n, largest); // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
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