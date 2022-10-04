#include"tools.h"
#include"WeirdStack.h"
#include"Second_task.h"
#include<iostream>
#include<exception>
using namespace std;

void work_with_weird_stack()
{
	WeirdStack b;
	int d = 0;
	cout << "������� 1, ���� ������ �������������� ++( �������� 1 � ����)\n 2, ���� ������ �������������� ������� --(�������� �������� �� �����)\n 3, ���� ������ ���������� ������ �� ������\n";
	while (d != 1)
	{
		long c;
		while (!try_read_int(c))
		{
			printf("�� ������ �� �����!\n��������� ����\n");
		}
		switch (c)
		{
		case 1:
			++b;
			cout << "����� �����:\n";
			for (int i = 0; i < b.get_size(); i++)
			{
				cout << "1 ";
			}
			cout << endl;
			break;
		case 2:
			--b;
			cout << "����� �����:\n";
			for (int i = 0; i < b.get_size(); i++)
			{
				cout << "1 ";
			}
			cout << endl;
			break;
		case 3:
			d = 1;
			break;
		default:
			cout << "�� ����� ������������ �����, ��������� ����\n";
		}
	}
}

void work_with_long_int()
{
	int d = 0;
	while (d != 1)
	{
		
		long a;
		cout << "������� ������ �����:\n";
		while (!try_read_int(a))
		{
			printf("�� ������ �� �����!\n��������� ����\n");
		}
		LongInt b1(a);
		cout << "������� ������ �����:\n";
		while (!try_read_int(a))
		{
			printf("�� ������ �� �����!\n��������� ����\n");
		}
		LongInt b2(a);
		cout << "�������:\n1-�������������� �������� �����\n2-�������������� ��������� �����\n3-��������� ������ � ������ ��������\n";
		long c;
		while (!try_read_int(c))
		{
			printf("�� ������ �� �����!\n��������� ����\n");
		}
		switch (c)
		{
		case 1:
			cout << "a + b = " << (b1+b2).get_number() << endl;
			break;
		case 2:
			cout << "a * b = " << (b1*b2).get_number() << endl;
			break;
		case 3:
			d = 1;
			break;
		default:
			cout << "�� ����� ������������ �����, ��������� ����\n";
		}
	}
}

int main();

void parse_cmd(int cmd)
{
	switch (cmd)
	{
	case 1:
		work_with_weird_stack();
		break;

	case 2:
		work_with_long_int();
		break;

	default:
		printf("�� ����� �� 1 � �� 2\n");
	}
	main();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		long cmd;
		cout << "������� 1, ����� �������������� ������ �������, ��� 2 ,����� �������������� ������\n";
		while (!try_read_int(cmd))
			printf("�� ������ �� �����!\n ��������� vv��\n");

		parse_cmd(cmd);
	}
	catch (exception ex)
	{
		cout << "������: " << ex.what() <<endl << "��������� ����� ������������!" << endl << endl;
		main();
	}

	return 0;
}