/* 4. �������� ������ : � ���������� ������� ������� : ����� ������, ����� �����������, ����� ����������,
����� �����������, ����� � ����, ���� ������.������� ������ : ������, ��������� �� ������ � ��������������,
����� ����������� ������� � 7.00 �� 9.00.��������� : ����� ����������� : ������ 0 - 59, ���� 0 -23.
�������� ������� ����������� � ���������� ����� ������� �� ���������� ����. */

#define DEBUG 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"LinkedDeque.h"

int main() noexcept
{
	setlocale(LC_ALL, "russian");
	printf("\nA - ������� ����� ���� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ����; � - ����� ���������� ��.;\n D - ���� �� �����; E -���� � ����������; F - ���������� ������ ;G - ����-�� �����.\n��� ������..\n");

	LinkedDeque a;
	LinkedDeque b;

	bool c = 0;
	char ch;

	do {
		ch = getchar();
		ch = toupper(ch);

		switch (ch)
		{
		case 'A':
			if (c == 1)
			{
				printf("�� ��� ������� ����, ����� � �����..\n");
				break;
			}
			printf("������� 1, ���� ������ ������ ��� � ���������� � 2, ���� �� �����\n");
			int o;
			NodeInfo j;
			scanf("%d", &o);
			if (o == 1)
				fread_info(j);
			else
				read_info(j);
			c = 1;
			init(a, j);
			break;

		case 'B':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			print(a);
			break;

		case 'C':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			print(b);
			getchar();
			break;
		case 'D':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			NodeInfo x;
			fread_info(x);
			push_back(a, x);
			break;
		case 'E':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}

			NodeInfo y;
			read_info(y);
			push_back(a, y);

			break;

		case 'F':
			c = 0;
			break;

		case 'G':
			return 0;

		default:
			printf("��� ����� �������\nPress any key");
		}
	} while (ch != 'G');

	return 0;
}

