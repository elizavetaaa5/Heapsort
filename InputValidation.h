#pragma once //��� ��������� �������������,  ������� ��������� ����������� �������� ���� ��������� ������ ���� ��� ��� ���������� �����  ��������� ����

//������������ ���������� �������
#include "MenuItems.h"

using namespace std;

template <typename T> //���������� �������

//���������� ������� ��� �������� ������������ ����� ������� ����
T GetInput(void); 
int GetInt(void);
MainMenuItem GetMainMenuItem(void);
SecondMenuItem GetSecondMenuItem(void);
WriteDataMenuItem GetWriteDataMenuItem(void);
ExistFile GetExitsFileItem(void);
