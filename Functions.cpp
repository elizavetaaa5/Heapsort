//��������� �������������
#include <iostream>                 
#include <random>                   
#include <string>                   
#include <filesystem>
#include <fstream>


//������������ ���������� �������
#include "MenuItems.h"
#include "InputValidation.h"

#define RangeForSize 10
#define MinimumForSize 6

#define RangeForElements 100
#define MinimumForElements 50

//������������ ����
using namespace std;
using namespace filesystem;

/// <summary>IsFileExist - ������� ������ ������ ��� ������ ������</summary>
string IsFileExist(void) {

    ExistFile UserChoice = static_cast<ExistFile>(0);
    string FilePath;

    bool TryOtherFile = false;
    bool IsDataSaved = false;

    do {
        cout << "������� ������������� ��� ���������� ���� �����: ";
        getline(cin, FilePath);

        if (fstream(FilePath)) {

            cout << "���� ��� ����������" << endl;

            do {
                cout << "[1] - ������������ ������������ ����" << endl;
                cout << "[2] - ������� ������ ����" << endl;
                cout << "�������� ����� ����: ";

                UserChoice = GetExitsFileItem();
                if ((UserChoice != NewFile) && (UserChoice != Overwriting)) {
                    cout << "��������� ����� �� ������. ��������� ����: " << endl;
                }

            } while ((UserChoice != NewFile) && (UserChoice != Overwriting));

            if (UserChoice == NewFile) {
                TryOtherFile = true;
                continue;
            }
        }

        /*
    ifstream: ��� ������ � �����
    ofstream : ��� ������ � ����
    fstream : ��������� ������ � ������
    */

    //�������� ��� ������ � ���������� ���������� �������� � ���� ������ ������
        ofstream MyFile(FilePath.c_str());
        error_code ec{};

        if (!is_regular_file(FilePath, ec)) {
            cout << "����� �������� ������������ ��������" << endl;
            continue;
        }

        if (!MyFile) {
            cout << "������ � ���� ���� ����������" << endl;
            MyFile.close();
            continue;
        }
        IsDataSaved = true;
    } while (!IsDataSaved);

    return FilePath;
}

/// <summary>TheListToFile - ������� ������ ������ � ����</summary>
/// <param name="FileArray"> - ������������ � ���� ������</param>
/// <param name="SizeOfArray"> - ������������ � ���� ������ �������</param>
void TheListToFile(int* FileArray, int SizeOfArray) {

    WriteDataMenuItem UserChoice = static_cast<WriteDataMenuItem>(0);
    string PathName = "";
    ofstream File;

    cout << "�������� ������ � ����?" << endl;
    cout << "[1] - �������� ������ � ����" << endl;
    cout << "[2] - ���������� ��� ������" << endl;
    cout << "�������� ����� ����: ";
   
    do {
        UserChoice = GetWriteDataMenuItem();
        switch (UserChoice) {
        case Writing:
            cout << "���������� � ����" << endl;
            PathName = IsFileExist();
            /*
       ios_base::in     - ������� ���� ��� ������
       ios_base::out    - ������� ���� ��� ������
       ios_base::ate    - ��� �������� ����������� ��������� � ����� �����
       ios_base::app    - ������� ���� ��� ������ � ����� �����
       ios_base::trunc	 - ������� ���������� �����, ���� �� ����������
       ios_base::binary - �������� ����� � �������� ������
       */
            File.open(PathName.c_str(), ios_base::trunc | ios_base::out);
            if (File.is_open()) {
                File << SizeOfArray << endl;
                File << "[ ";
                for (int i = 0; i < SizeOfArray; i++) File << FileArray[i] << " ";
                File << "]";
                cout << "������ ���������" << endl;
                File.close();
            }
            else {
                cout << "���� ���������� ��� ������" << endl;
                File.close();
            }
            break;
        case Cancelling:
            continue;
            break;

        default:
            cout << "�������� ����� �����������. ��������� ����: ";
            break;
        }

    } while ((UserChoice != Writing) && (UserChoice != Cancelling));
}

/// <summary>ShowSortedArray - ������� ������ ���������������� �������</summary>
/// <param name="SortedArray"> - ��������������� ������</param>
/// <param name="SizeOfArray"> - ������ �������</param>
void ShowSortedArray(int* SortedArray, int SizeOfArray) {
    cout << "��������������� ������: [ ";
    for (int i = 0; i < SizeOfArray; i++) cout << SortedArray[i] << " ";
    cout << "]" << endl;
}

/// <summary>Heapify - ������� ��� ���������� ����</summary>
/// <param name="Array"> - ������ </param>
/// <param name="n"> - ����� </param>
/// <param name="i"> - ������ </param>
void Heapify(int Array[], int n, int i) {
    int largest = i; // �������������� largest ��� ������
    int left = 2 * i + 1; // ����� �������� �������
    int right = 2 * i + 2; // ������ �������� �������

    // ���� ����� �������� ������� ������ �����
    if (left < n && Array[left] > Array[largest])
        largest = left;

    // ���� ������ �������� ������� ������ largest
    if (right < n && Array[right] > Array[largest])
        largest = right;

    // ���� largest �� ������
    if (largest != i) {
        swap(Array[i], Array[largest]); // ����������
        Heapify(Array, n, largest); // ���������� �������� ���������� ���������
    }
}

/// <summary>HeapSort - ������� ��� ���������� ������������� ����������</summary>
/// <param name="Array"> - ������ </param>
/// <param name="n"> - ����� </param>
void HeapSort(int Array[], int n) {

    // ���������� ���� (������������ ��������)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(Array, n, i);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i > 0; i--) {
        swap(Array[0], Array[i]); // ���������� ������� ������ � �����
        Heapify(Array, i, 0); // �������� heapify �� ����������� ����
    }
}


/// <summary>RandomEntering - ������� �������� ���������� �������</summary>
void RandomEntering(void) {

    int ArraySize = rand() % RangeForSize + rand() % MinimumForSize;
    cout << "����������� ������ ������ ������� = " << ArraySize << endl;

    int* Array = new int[ArraySize];

    for (int i = 0; i < ArraySize; i++) {
        Array[i] = rand() % RangeForElements - MinimumForElements;
    }

    cout << "����������� �������� ������: [ ";
    for (int i = 0; i < ArraySize; i++) {
        cout << Array[i] << " ";
    }
    cout << "]" << endl;

    HeapSort(Array, ArraySize);
    ShowSortedArray(Array, ArraySize);
    TheListToFile(Array, ArraySize);
}

/// <summary>ManualEntering - ������� ���������� ������� � ����������</summary>
void ManualEntering(void) {

    int ArraySize = 0;
    cout << "������� ������ �������: ";
    do {
        ArraySize = GetInt();
        if (ArraySize <= 0) cout << "������ �����. ��������� ����: ";
    } while (ArraySize <= 0);

    int* Array = new int[ArraySize];

    for (int i = 0; i < ArraySize; i++) {
        cout << "������� " << i + 1 << " �������: ";
        Array[i] = GetInt();
    }

    cout << "��������� ������: " << endl;
    cout << "[ ";
    for (int i = 0; i < ArraySize; i++) cout << Array[i] << " ";
    cout << "]" << endl;

    HeapSort(Array, ArraySize);
    ShowSortedArray(Array, ArraySize);
    TheListToFile(Array, ArraySize);
}

