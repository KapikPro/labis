#include<iostream>
#include"tools.h"
#include"task_class.h"
#include"task_massiv.h"
#include<vector>
using namespace std;
struct buss
{
	int num_bus;
	string fam;
	int sost;

};
void work_with_massiv()
{
	int a = 0, b = 0, k = 0, t3, p = 0;
	double t1;
	float t2;
	cout << "�������� ������ ��� ��������:\n1-double\n2-float\n3-int\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2 && a != 3))
		cout << "������� ����� 1, 2,3 ��� 4!\n";
	vector<double> v1;
	vector<float> v2;
	vector<int> v3;
	cout << "1-�������� ������� � ������\n2-����� �������\n3-�������� ��� ������������� �������� ������� �� ���������� � ����������� �������� ������� �� �����������\n4-����� ���-�� ������������� ��������� �������\n5-����� ����� ������� ��������� �������, ������������� ����� ������������ �� ������ ��������.\n6-������������� ���������\n";
	while (true)
	{
		if (p == 1)
			break;
		cout << "�������� ��������:\n";
		while (try_read_int(b) != 1 || (b != 1 && b != 2 && b != 3 && b != 4 && b!=5 && b!=6))
			cout << "������� 1,2,3 ��� 4\n";
		switch (b)
		{
		case(1):
			cout << "������� �����:\n";
			if (a == 1)
			{
				while (try_read_double(t1) != 1)
					cout << "�� ����� ������������ �����, ��������� ����\n";
				v1.resize(k + 1);
				v1[k] = t1;
				k++;
			}
			if (a == 2)
			{
				while (try_read_float(t2) != 1)
					cout << "�� ����� ������������ �����, ��������� ����\n";
				v2.resize(k + 1);
				v2[k] = t2;
				k++;
			}
			if (a == 3)
			{
				while (try_read_int(t3) != 1)
					cout << "�� ����� ������������ �����, ��������� ����\n";
				v3.resize(k + 1);
				v3[k] = t3;
				k++;
			}
			break;
		case(2):
			cout << "����� �������:\n";
			if (a == 1)
			{
				if (v1.size() == 0)
					cout << "������ ����\n";
				else
					for (auto i : v1)
						cout << i << " ";
				cout << endl;
			}
			if (a == 2)
			{
				if (v2.size() == 0)
					cout << "������ ����\n";
				else
					for (auto i : v2)
						cout << i << " ";
				cout << endl;
			}
			if (a == 3)
			{
				if (v3.size() == 0)
					cout << "������ ����\n";
				else
					for (auto i : v3)
						cout << i << " ";
				cout << endl;
			}
			break;
		case(3):
			condition_3(v1);
			condition_3(v2);
			condition_3(v3);
			cout << "������ �����������\n";
			break;
		case(4):
			if (a == 1)
				cout << "���������� ������������� ��������� ����� " << condition_1(v1) << endl;
			if (a == 2)
				cout << "���������� ������������� ��������� ����� " << condition_1(v2) << endl;
			if (a == 3)
				cout << "���������� ������������� ��������� ����� " << condition_1(v3) << endl;
			break;
		case(5):
			if (a == 1)
				cout << "����� ������� ���������, ������������� ����� ������������ �� ������ �������� " << condition_2(v1) << endl;
			if (a == 2)
				cout << "����� ������� ���������, ������������� ����� ������������ �� ������ �������� " << condition_2(v2) << endl;
			if (a == 3)
				cout << "����� ������� ���������, ������������� ����� ������������ �� ������ �������� " << condition_2(v3) << endl;
			break;
		case(6):
			p = 1;
			break;
		}
	}
}
void work_with_class()
{
	buss bus;

	ListNode<buss> node(bus);
	LinkedList<buss> list;

	int a = 0, b = 0, k = 0, p = 0, t=0, f=0, j=0;
	cout << "��������:\n1-�������� � ������ �������\n2-�������� ������ ���������( � �������� � ���, ��� ���)\n3-������� ������ ��������(� ����� ��� �� ��������)\n4-����������� ������ ������������� ��������\n5-������������� ���������\n";
	while (true)
	{
		if (p == 1)
			break;
		cout << "�������� ��������:\n";
		while (try_read_int(b) != 1 || (b != 1 && b != 2 && b != 3 && b != 4 && b != 5))
			cout << "������� 1,2,3 ��� 4\n";
		switch (b)
		{
		case(1):
			cout << "������� ����� ��������:\n";
			while (true)
			{
				while (try_read_int(k) != 1)
					cout << "�� ����� ������������ ��� ������������ ����� ��������, ��������� ����\n";
				if (list.first() == nullptr)
				{
					break;
				}
				else
					if (list.first() == list.first()->get_next())
					{
						if (list.first()->get_value().num_bus == k)
						{
							t = 1;
							break;
						}
						if (t == 1)
						{
							t = 0;
							cout << "�� ����� ������������ ��� ������������ ����� ��������, ��������� ����\n";
						}
						else
							break;
					}
					else
						for (auto i = list.first(); (i->get_next() != list.first()->get_next() || j == 0); i = i->get_next())
						{
							j++;
							if (i->get_value().num_bus == k)
							{
								t = 1;
								break;
							}
						}
				j = 0;
				if (t == 1)
				{
					t = 0;
					cout << "�� ����� ������������ ��� ������������ ����� ��������, ��������� ����\n";
				}
				else

					break;

			}
			bus.num_bus = k;
			t = 0;
			cout << "�������� ������� ��������(�� ����������):\n";
			cin >> bus.fam;
			cout << "���� ������� ������� ����, ������� 1, ���� �� �� � ����� ������� 2\n";
			while (try_read_int(bus.sost) != 1 || (bus.sost != 1 && bus.sost != 2))
				cout << "�� ����� ������������ �����, ��������� ����\n";
			list.push_back(bus);
			break;
		case(2):
			if (list.first() == nullptr)
				cout << "������ ��������� ����\n";
			else
				if (list.first() == list.first()->get_next())
					if (list.first()->get_value().sost == 2)
						cout << list.first()->get_value().num_bus << " ������ � �����\n";
					else
						cout << list.first()->get_value().num_bus << " ������ �� ��������\n";
				else
					for (auto i = list.first(); (i->get_next() != list.first()->get_next() || j == 0); i = i->get_next())
					{
						j++;
						if (i->get_value().sost == 2)
							cout << i->get_value().num_bus << " ������ � �����\n";
						else
							cout << i->get_value().num_bus << " ������ �� ��������\n";
					}
			j = 0;
			break;
		case(3):
			cout << "������� ����� ��������, ������ �������� ������ �������:\n";
			while (true)
			{
				while (try_read_int(k) != 1)
					cout << "�� ����� ������������ �����, ��������� ����\n";
				if (list.first() == nullptr)
				{
					cout << "������ ������\n";
					break;
				}
				else
					if (list.first() == list.first()->get_next())
					{
						
						
							if (list.first()->get_value().num_bus == k)
							{
								t = 1;
							}
							if (t == 0)
							{
								cout << "�� ����� �������������� ��� ������������ ����� ��������, ��������� ����\n";
							}
							else
								t=0;
						
						if (list.first()->get_value().num_bus == k)
						{
							cout << "���� �� ������, ����� ������� ��� ����, ������� 1, ���� �� ����� � ����� ������� 2\n";
							while (try_read_int(f) != 1 || (f != 1 && f != 2))
								cout << "�� ����� ������������ �����, ��������� ����\n";
							bus.num_bus = list.first()->get_value().num_bus;
							bus.fam = list.first()->get_value().fam;
							bus.sost = f;
							list.first()->set_value(bus);

						}
						break;
					}
					else
						for (auto i = list.first(); (i->get_next() != list.first()->get_next() || j == 0); i = i->get_next())
						{
							j++;
							if (i->get_value().num_bus == k)
							{
								cout << "���� �� ������, ����� ������� ��� ����, ������� 1, ���� �� ����� � ����� ������� 2\n";
								while (try_read_int(f) != 1 || (f != 1 && f != 2))
									cout << "�� ����� ������������ �����, ��������� ����\n";
								bus.num_bus = i->get_value().num_bus;
								bus.fam = i->get_value().fam;
								bus.sost = f;
								i->set_value(bus);
								t = 1;
								break;
							}
						}
				if (t == 1)
				{
					t = 0;
					break;
				}
				else
					cout << "�� ����� �������������� ����� ��������\n";
			}

				j = 0;
		       break;
		case(4):
			cout << "������� ����� ��������, ������ �������� ������ �����������:\n";
			while (true)
			{
				if (list.first() == nullptr)
				{
					cout << "������ ������\n";
					break;
				}
				while (try_read_int(k) != 1)
					cout << "�� ����� ������������ �����, ��������� ����\n";
				for (auto i = list.first(); (i->get_next() != list.first()->get_next() || j == 0); i = i->get_next())
				{
					j++;
					if (i->get_value().num_bus == k)
					{
						cout << "����� �������� - " << i->get_value().num_bus << endl;
						cout << "������� �������� - " << i->get_value().fam << "\n";
						cout << "c�������� �������� - ";
						if (i->get_value().sost == 1)
							cout << "�� ��������" << endl;
						else
							cout << "� �����" << endl;
						t = 1;
						break;
					}
					
				}
				if (t == 1)
					{
						t = 0;
						break;
					}
					else
						cout << "�� ����� �������������� ����� ��������\n";
			}
				j = 0;
			break;
		case(5):
			p = 1;
			break;
		}
	}
}
int main()
 {
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "1-������� � �������� �������\n2-������� � �������� ������\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2))
		cout << "������� ����� 1 ��� 2!\n";
	if (a == 1)
		work_with_massiv();
	else
		work_with_class();
	main();
	cout << endl;
}
