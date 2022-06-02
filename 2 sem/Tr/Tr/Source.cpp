/* 4. �������� ������ : � ���������� ������� ������� : ����� ������, ����� �����������, ����� ����������,
����� �����������, ����� � ����, ���� ������.������� ������ : ������, ��������� �� ������ � ��������������,
����� ����������� ������� � 7.00 �� 9.00.��������� : ����� ����������� : ������ 0 - 59, ���� 0 -23.
�������� ������� ����������� � ���������� ����� ������� �� ���������� ����. */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"LinkedDeque.h"

int main() noexcept
{
	setlocale(LC_ALL, "russian");
	printf("\nA - ������� ����� ����; B - ��� ������ ������� ������ ��� ��� ����; � - ����� ���������� ��.;\n D - ���� �� �����; E -���� � ����������; F - ���������� ������ ;G - ����-�� �����.\n��� ������..\n");

	LinkedDeque a;
	LinkedDeque b;

	bool c = 0;
	char ch;

	do {
		ch = getchar();
		ch = toupper(ch);

		getchar();

		switch (ch) {
		case 'A':
			if (c == 1)
			{
				printf("�� ��� ������� ����, ����� � �����..\n");
				break;
		}
			init(a);
			c = 1;
			
			break;

		case 'B':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			print(a);
			getchar();
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
			getchar();
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
			getchar();

			break;
		case 'F':
			

			c = 0;
			getchar();
			break;
		case 'G': return 0;
		default:
			printf("��� ����� �������\nPress any key");
			getchar();
		}
	} while (ch != 'G');

	return 0;
}

