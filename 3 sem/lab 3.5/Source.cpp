#include<iostream>
#include<string>
#include"class_worker.h"
#include"other.h"
#include"tools.h"
using namespace std;
void first()
{
	int a,k=1,b,t=0;
	vector<boss> osn;
	vector<worker> baza;
	float plata;
	string fam, otch, name, work, name_boss, fam_boss,otch_boss;
	vector<worker> vec;
	cout << "����:\n";
	cout << "1-������� ����\n2-�������� ����������\n3-������� ������ ���� ����������� ������ �� ������ ��� ����������\n4-����� �� ����� ������������ ����������(� ��� ������� ���������)\n5-��������� ������ � ��������\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2 && a!=3 && a!=4 && a!=5))
		cout << "�� ����� ���-�� ��������, ��������� ����\n";
	while (1)
	{
		if (k == 0)
			break;
		switch (a)
		{
		case(1):
			cout << "1-������� ����\n2-�������� ����������\n3-������� ������ ����������� ������ �� ������ ��� ����������\n4-����� �� ����� ������������ ����������\n5-��������� ������ � ��������\n";
			break;
		case(2):
			cout << "�� ������ �������� ������ �������� ��� �������� ����������?\n1-���������\n2-�������� ����������\n";
			while (try_read_int(b) != 1 || (b != 1 && b != 2))
				cout << "�� ����� ���-�� ��������, ��������� ����\n";
			if (b == 1)
			{
				cout << "������� �������� ����������:\n";
				while (try_read_float(plata)!=1)
					cout << "�� ����� ���-�� ��������, ��������� ����\n";
				cout << "������� ������� ����������:\n";
				cin >> fam;
				cout << "������� ��� ����������:\n";
				cin >> name;
				cout << "������� �������� ����������:\n";
				cin >> otch;
				work = "boss";
				boss Alex(plata,fam,otch,name,work,vec);
				osn.push_back(Alex);
			}
			else
			{
				cout << "������� �������� ����������:\n";
				while (try_read_float(plata)!=1)
					cout << "�� ����� ���-�� ��������, ��������� ����\n";
				cout << "������� ������� ����������:\n";
				cin >> fam;
				cout << "������� ��� ����������:\n";
				cin >> name;
				cout << "������� �������� ����������:\n";
				cin >> otch;
				cout << "������� 1, ���� ��������� ���������\n2, ���� ��������� �����������\n3, ���� ��������� ��������\n";
				while (try_read_int(b) != 1 || (a != 1 && a != 2 && a!=3))
					switch (b)
					{
					case(1):
						break;
					case(2):
						break;
					case(3):
						break;
					}
					cout << "�� ����� ���-�� ��������, ��������� ����\n";
				worker Bob(plata, fam, otch, name, work);
				cout << "�������� �����, � �������� ������ ��������� ���������� � ����������(������� �������, ��� � ��������):\n";
				while (1)
				{
					cin >> fam_boss;
					cin >> name_boss;
					cin >> otch_boss;
					for (int i = 0; i < osn.size(); i++)
					{
						if (osn[i].get_name() == name_boss && osn[i].get_fam() == fam_boss && osn[i].get_otch() == otch_boss)
						{
							t = 1;
							osn[i].set_vec(Bob);
							break;
						}
					}
					if (t == 1)
					{
						t = 0;
						break;
					}
					else
						cout << "������ ����� �� ����������, ��������� ����\n";
				}
				
			}
			break;
		case(3):

			break;
		case(4):
			break;
		case(5):
			k = 0;
			break;
		}
	}
}
void second()
{

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "������� 1, ���� ������ �������� � ������� 5.1 ��� 2, ���� � ������� 5.2\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2))
		cout << "�� ����� ���-�� ��������, ��������� ����\n";
	switch (a)
	{
	case(1):
		first();
		break;
	case(2):
		second();
		break;
	}
	main();
}