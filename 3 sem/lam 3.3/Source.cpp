#include"tools.h"
#include"WeirdStack.h"
#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������ 1, ���� ������ ��������� ������ ������� � 2, ���� ������\n";
	int a;
	while (!try_read_int(a))
	{
		printf("�� ������ �� �����!\n");
	}

	WeirdStack<int> b;
	switch (a)
	{
	case 1:
		b + 101;
		cout << b--;
		break;

	case 2:
		
		break;

	default:
		printf("�� ����� �� 1 � �� 2..\n");
		main();
	}
}