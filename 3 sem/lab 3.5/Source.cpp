#include<iostream>
#include<string>
#include"class_worker.h"
#include"other.h"
#include"tools.h"
using namespace std;
void first()
{
	int a,k=1,b,t=0,d=0;
	string s="1", cat;
	vector<boss> osn;
	vector<string> ob,prava,tran,teh;
	float plata;
	string fam, otch, name, work, name_boss, fam_boss,otch_boss;
	vector<worker> vec;
	cout << "����:\n";
	cout << "1-������� ����\n2-�������� ����������\n3-������� ������ ���� ����������� ������ �� ������\n4-����� �� ����� ������������ ����������(� ��� ������� ���������)\n5-��������� ������ � ��������\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2 && a!=3 && a!=4 && a!=5))
		cout << "�� ����� ���-�� ��������, ��������� ����\n";
	while (1)
	{
		if (k == 0)
			break;
		switch (a)
		{
		case(1):
			cout << "1-������� ����\n2-�������� ����������\n3-������� ������ ����������� ������ �� ������(� ��� ������� ��� ������ 1 �� ���)\n4-������� ����������\n5-��������� ������ � ��������\n";
			break;
		case(2):
			cout << "�� ������ �������� ������ ��������a ��� �������� ����������?\n1-���������\n2-�������� ����������\n";
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
				cout << "������� 1, ���� ��������� ��������� �������������\n2, ���� ��������� �����������\n3, ���� ��������� ��������\n";
				while (try_read_int(d) != 1 || (d != 1 && d != 2 && d!=3))
					cout << "�� ����� ���-�� ��������, ��������� ����\n";
					switch (d)
					{
					case(1):
						work = "admin";
						break;
					case(2):
						work = "programist";
						break;
					case(3):
						work = "driver";
						break;
					}	
				worker Bob(plata, fam, otch, name, work);
				cout << "�������� �����, � �������� ������ ��������� ���������� � ����������(������� �������, ��� � ��������):\n";
					cout << "������ ������:\n";
					if (osn.size() == 0)
						cout << "������ �� ����������\n";
					else
					{
						for (int i = 0; i < osn.size(); i++)
							cout << i + 1 << "-" << osn[i].get_fam() << " " << osn[i].get_name() << " " << osn[i].get_otch() << endl;
						cout << "�������� ����� ������� �����:\n";
						while (try_read_int(t) != 1 || t<1 || t>osn.size())
							cout << "�� ����� ���-�� ��������, ��������� ����\n";
						t--;
						osn[t].set_worker(Bob);
						switch (d)
						{
						case(1):
							cout << "������� ������������ �������������, ����� �������� ��������� ������� '-'\n";
							ob.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if(s!="-")
								ob.push_back(s);
							}
							if (1)
							{
								adm A(plata, fam, otch, name, work, ob);
								osn[t].set_adm(A);
							}
							break;
						case(2):
							cout << "������� ������� ������������\n";
							cin >>cat;
							cout << "������� ����������, �������� ������� �����������, ����� �������� ��������� ������� '-'\n";
							teh.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if (s != "-")
									teh.push_back(s);
							}
							if (1)
							{
								proger A(plata, fam, otch, name, work, cat, teh);
								osn[t].set_proger(A);
							}
							break;
						case(3):
							cout << "������� ��������� ���� ��������, ����� �������� ��������� ������� '-'\n";
							prava.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if (s != "-")
									prava.push_back(s);
							}
							cout << "������� ��������� ���������� ��������, ����� �������� ��������� ������� '-'\n";
							tran.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if (s != "-")
									tran.push_back(s);
							}
							if (1)
							{
								vodila A(plata, fam, otch, name, work, prava,tran);
								osn[t].set_driver(A);
							}
							break;
						}
					}
			}
			break;
		case(3):
			cout << "�������� �����, � �������� ������ ������� �����������:\n";
			if (osn.size() == 0)
				cout << "������ �� ����������\n";
			else
			{
				for (int i = 0; i < osn.size(); i++)
					cout << i + 1 << "-" << osn[i].get_fam() << " " << osn[i].get_name() << " " << osn[i].get_otch() << endl;
				cout << "�������� ����� ������� �����:\n";
				while (try_read_int(t) != 1 || t<1 || t>osn.size())
					cout << "�� ����� ���-�� ��������, ��������� ����\n";
				t--;
				osn[t].viv_workers();
				cout << "�� ������ ����������� ������ ������ ������ �� ���?\n1-��\n2-���";
				while (try_read_int(b) != 1 || (b != 1 && b != 2))
					cout << "�� ����� ���-�� ��������, ��������� ����\n";
				if (b == 1)
				{
					cout << "������� ����� ������� ����������:\n";
					while (try_read_int(d) != 1 || d<1 || d>osn[t].vec_size())
						cout << "�� ����� ���-�� ��������, ��������� ����\n";
					d--;
					if(osn[t].get_work() == "admin")
					{
						cout << "������ - ��������� �������������\n";
						cout << "��� - " << osn[t].get_adm(d).get_fam() << " " << osn[t].get_adm(d).get_name() << " " << osn[t].get_adm(d).get_otch() << endl;
						cout << "�������� - " << osn[t].get_adm(d).get_plata() << endl;
						osn[t].get_adm(d).get_obr();
				    }
					else
						if (osn[t].get_work() == "driver")
						{
							cout << "������ - ��������� �������������\n";
							cout << "��� - " << osn[t].get_driver(d).get_fam() << " " << osn[t].get_driver(d).get_name() << " " << osn[t].get_driver(d).get_otch() << endl;
							cout << "�������� - " << osn[t].get_driver(d).get_plata() << endl;
							osn[t].get_driver(d).get_prava();
							osn[t].get_driver(d).get_tran();
						}
						else
						{
							cout << "������ - �����������\n";
							cout << "��� - " << osn[t].get_proger(d).get_fam() << " " << osn[t].get_proger(d).get_name() << " " << osn[t].get_proger(d).get_otch() << endl;
							cout << "�������� - " << osn[t].get_proger(d).get_plata() << endl;
							cout << " ������� ������������ - " << osn[t].get_proger(d).get_cat() << endl;
							osn[t].get_proger(d).get_teh();
						}
				}
			}
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