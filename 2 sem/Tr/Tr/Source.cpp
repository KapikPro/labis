/* 4. �������� ������ : � ���������� ������� ������� : ����� ������, ����� �����������, ����� ����������,
����� �����������, ����� � ����, ���� ������.������� ������ : ������, ��������� �� ������ � ��������������,
����� ����������� ������� � 7.00 �� 9.00.��������� : ����� ����������� : ������ 0 - 59, ���� 0 -23.
�������� ������� ����������� � ���������� ����� ������� �� ���������� ����. */

#define DEBUG 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LinkedDeque.h"
#include "ArrayDeque.h"
#include <string>
#include <Windows.h> 

int main()
{
	setlocale(LC_ALL, "russian");
	printf("�������� �����, ������� ������ ����������� ���:\n1- ��� �������� ����������� �������\n2- ��� �������� ��������� ��������\n");
	int d = 0;
	scanf("%d", &d);
	if (d == 1)
	{
		FILE* t;
		if ((t = fopen("log.txt", "w")) == NULL)
		{
			printf("������ �������� �����\n");
			exit(0);
		}
		fclose(t);
		FILE* f;
		if ((f = fopen("fin.txt", "r")) == NULL)
		{
			printf("������ �������� �����\n");
			exit(0);
		}

		printf("\nA - ������� ����� ��� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ���� ;�- �������� ����� �� ���� ��.;\nU-��������������� ����D - ���� �� �����; E -���� � ����������; F - ���������� ������ ;V-����� ������;Z-�������� n ��.\nG - ����-�� �����.��� ������..\n");

		LinkedDeque a;
		LinkedDeque b;
		LinkedDeque k;

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
					printf("�� ��� ������� ���, ����� � �����..\n");
					break;
				}
				printf("������� 1, ���� ������ ������ ��� � ���������� � 2, ���� �� �����\n");
				int o;
				NodeInfo j;

				scanf("%d", &o);
				if (o == 2)
					fread_info(j, f);
				else
					read_info(j);
				c = 1;
				init(a, j);
				//getchar();
				log(a);
				break;

			case 'B':
				if (c == 0)
				{
					printf("�� �� ������� ���, ������� � ��������..\n");
					break;
				}
				printf("������ ����:\n");
				print(a);
				printf("\n������ ����:\n");
				print(b);
				printf("\n������ ����:\n");
				print(k);
				//getchar();
				break;
			case 'Z':
				printf("������� ��������� �� ������ �������?/n");
				int n;
				scanf("%d", &n);
				for (int i = 0; i < n; i++)
				{
					pop_back(a);
				}
				log(a);
				break;
			case 'C':
				if (c == 0)
				{
					printf("�� �� ������� ���, ������� � ��������..\n");
					break;
				}
				solve(a, b, k);
				break;
			case 'D':
				if (c == 0)
				{
					printf("�� �� ������� ���, ������� � ��������..\n");
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
				log(a);
				//getchar();
				break;
			case 'E':
				if (c == 0)
				{
					printf("�� �� ������� ���, ������� � ��������..\n");
					break;
				}

				NodeInfo y;
				read_info(y);
				push_back(a, y);
				//getchar();
				log(a);
				break;
			case'U':
				reverse(a);
				printf("��� ���������\n");
				log(a);
				break;
			case 'F':
				c = 0;
				clear(a);
				clear(b);
				clear(k);
				printf("����� �������\n");
				//getchar();
				log(a);
				break;
			case'V':
				printf("\nA - ������� ����� ��� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ����; �- �������� ���� �� ���� ��;\n D - ���� �� �����; E -���� � ����������; F - ���������� ������; Z-  ������� N ���������\nG - ����-�� �����.��� ������..\n");
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
	else
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	{
	FILE* t;
	if ((t = fopen("log.txt", "w")) == NULL)
	{
		printf("������ �������� �����\n");
		exit(0);
	}
	fclose(t);
	FILE* f;
	if ((f = fopen("fin.txt", "r")) == NULL)
	{
		printf("������ �������� �����\n");
		exit(0);
	}

	printf("\nA - ������� ����� ��� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ���� ;�- �������� ����� �� ���� ��.;\nU-��������������� ����D - ���� �� �����; E -���� � ����������; F - ���������� ������ ;V-����� ������;Z-�������� n ��.\nG - ����-�� �����.��� ������..\n");


	bool c = 0;
	char ch;
	printf("������� ����� ��� ������ ��������:\n");
	do {
		ArrayDeque a;
		ArrayDeque b;
		ArrayDeque k;

		scanf("%c", &ch);
		if (ch == '\n' || ch == ' ')
			continue;
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			if (c == 1)
			{
				printf("�� ��� ������� ���, ����� � �����..\n");
				break;
			}
			printf("������� 1, ���� ������ ������ ��� � ���������� � 2, ���� �� �����\n");
			int o;
			ElemInfo j;

			scanf("%d", &o);
			if (o == 2)
				fread_info(j, f);
			else
				read_info(j);
			c = 1;
			init(a);
			init(b);
			init(k);
			//getchar();
			log(a);
			break;

		case 'B':
			if (c == 0)
			{
				printf("�� �� ������� ���, ������� � ��������..\n");
				break;
			}
			printf("������ ����:\n");
			print(a);
			printf("\n������ ����:\n");
			print(b);
			printf("\n������ ����:\n");
			print(k);
			//getchar();
			break;
		case 'Z':
			printf("������� ��������� �� ������ �������?/n");
			int n;
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				pop_back(a);
			}
			log(a);
			break;
		case 'C':
			if (c == 0)
			{
				printf("�� �� ������� ���, ������� � ��������..\n");
				break;
			}
			solve(a, b, k);
			break;
		case 'D':
			if (c == 0)
			{
				printf("�� �� ������� ���, ������� � ��������..\n");
				break;
			}
			ElemInfo x;
			if (!feof(f))
			{
				fread_info(x, f);
				push_back(a, x);
			}
			else
			{
				printf("������ ��������� � ����� ���..\n");
			}
			log(a);
			//getchar();
			break;
		case 'E':
			if (c == 0)
			{
				printf("�� �� ������� ���, ������� � ��������..\n");
				break;
			}

			ElemInfo y;
			read_info(y);
			push_back(a, y);
			//getchar();
			log(a);
			break;
		case'U':
			reverse(a);
			printf("��� ���������\n");
			log(a);
			break;
		case 'F':
			c = 0;
			clear(a);
			clear(b);
			clear(k);
			printf("����� �������\n");
			//getchar();
			log(a);
			break;
		case'V':
			printf("\nA - ������� ����� ��� �� 1��� ��������; B - ��� ������ ������� ������ ��� ��� ����; �- �������� ���� �� ���� ��;\n D - ���� �� �����; E -���� � ����������; F - ���������� ������; Z-  ������� N ���������\nG - ����-�� �����.��� ������..\n");
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
	return 0;
 }
}

