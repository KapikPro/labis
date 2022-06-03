/* 4. �������� ������ : � ���������� ������� ������� : ����� ������, ����� �����������, ����� ����������,
����� �����������, ����� � ����, ���� ������.������� ������ : ������, ��������� �� ������ � ��������������,
����� ����������� ������� � 7.00 �� 9.00.��������� : ����� ����������� : ������ 0 - 59, ���� 0 -23.
�������� ������� ����������� � ���������� ����� ������� �� ���������� ����. */

#define DEBUG 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LinkedDeque.h"
#include "ArrayDeque.h"

int main()
{
	FILE* f;
	if ((f = fopen("fin.txt", "r")) == NULL)
	{
		printf("������ �������� �����\n");
		exit(0);
	}
	setlocale(LC_ALL, "russian");
	printf("\nA - ������� ����� ���� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ���� �;�- �������� ����� �� ���� ��.\nD - ���� �� �����; E -���� � ����������; F - ���������� ������ ;V-����� ������;G - ����-�� �����.\n��� ������..\n");

	LinkedDeque a;
	LinkedDeque b;


	bool c = 0;
	char ch;
	printf("������� ����� ��� ������ ��������:\n");
	do {

		scanf("%c", &ch);
		if (ch == '\n' || ch == ' ')
			continue;
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
			if (o == 2)
				fread_info(j,f);
			else
				read_info(j);
			c = 1;
			init(a, j);
			//getchar();
			break;

		case 'B':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			print(a);
			print(b);
			//getchar();
			break;

		case 'C':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			solve(a, b);
			break;
		case 'D':
			if (c == 0)
			{
				printf("�� �� ������� ����, ������� � ��������..\n");
				break;
			}
			NodeInfo x;
			if (!feof(f))
			{
				fread_info(x, f);
				push_back(a, x);
			}
			else
			{
				printf("������ ��������� � ����� ���..\n");
			}

			//getchar();
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
			//getchar();
			break;

		case 'F':
			c = 0;
			clear(a);
			clear(b);
			printf("����� �������\n");
			//getchar();
			break;
		case'V':
			printf("\nA - ������� ����� ���� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ����; � - ����� ���������� ��.;\n D - ���� �� �����; E -���� � ����������; F - ���������� ������ ;G - ����-�� �����.\n��� ������..\n");
			break;
		case 'G':
			return 0;
		default:
			printf("��� ����� �������\n");
			//getchar();
		}
		printf("������� ����� ��� ������ ��������:\n");
	} while (ch != 'G');
	fclose(f);
	return 0;
}

