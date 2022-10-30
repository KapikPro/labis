#include"Room.h"
#include "RoomWithWallpaper.h" 
#include<iostream>
#include<sstream>
#include<cmath>
#include<string>

using namespace std;

int str_to_int(string n)
{
	stringstream a;
	int b;
	a << n;
	a >> b;
	return b;
}

int check(string n)
{
	int k = 1;
	for (int i = 0; i < n.size(); i++)
	{
		if (i == 0 && n[i] == '-')
			k = 2;
		else
			if ((((int)n[i] < 48) || ((int)n[i] > 57)))
			{
				k = 0;
				break;
			}
	}
	if (k == 1)
		if (str_to_int(n) == 0)
			return 3;
	if (k == 1)
		return 1;
	else
		if (k == 2)
			return 2;
		else
			return 0;
}

int main()
{
	string s;
	int l, w, h, c = 0;
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		cout << "������� �����\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "�� ����� ������������ �����, ��������� ����\n";
				cin >> s;
				if (check(s) == 1)
				{
					l = str_to_int(s);
					break;
				}
			}
		else
			l = str_to_int(s);
		cout << "������� ������ �������\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "�� ����� ������������ �����, ��������� ����\n";
				cin >> s;
				if (check(s) == 1)
				{
					w = str_to_int(s);
					break;
				}
			}
		else
			w = str_to_int(s);
		cout << "������� ������ �������\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "�� ����� ������������ �����, ��������� ����\n";
				cin >> s;
				if (check(s) == 1)
				{
					h = str_to_int(s);
					break;
				}
			}
		else
			h = str_to_int(s);
		cout << "������� ��� �� ���������� ����(�� ���� ����� �� ������ ������ ����)\n";
		cout << "������ ������ ���� ����� �������� ������ �������, � ��� ������ ����� �������� ������ ���������� �� ������\n";
		cin >> s;
		if (check(s) != 1 && check(s) != 3)
			while (1)
			{
				cout << "�� ����� ������������ �����, ��������� ����\n";
				cin >> s;
				if (check(s) == 1)
				{
					c = str_to_int(s);
					if (c * 0.5 * min(l, w) <= l * w)
						break;
					else
						cout << "�� ����� ������� ����� ����..\n";
				}

			}
		if (str_to_int(s) * 0.5 * min(l, w) > l * w)
		{
			cout << "�� ����� ������� ����� ����..\n";
			while (1)
			{
				cout << "�� ����� ������������ �����, ��������� ����\n";
				cin >> s;
				if (check(s) == 1)
				{
					c = str_to_int(s);
					if (c * 0.5 * min(l, w) <= l * w)
						break;
					else
						cout << "�� ����� ������� ����� ����..\n";
				}
			}
		}
		else
			c = str_to_int(s);
		Room a = Room(l, w, h, c);
		while (1)
		{
			cout << "\n0-���������� ������ � ��������\n1-���������� ������ �������\n2-���������� ������� ���� �������\n3-����� ���� ���������� �������\n4-������ ������������ ��������� �����\n\n";
			cin >> s;
			if (check(s) == 3)
				break;
			else
				if (check(s) != 1)
					while (1)
					{
						cout << "�� ����� ������������ �����, ��������� ����\n";
						cin >> s;
						if (check(s) == 1)
							if (str_to_int(s) <= 4 && str_to_int(s) > 0)
							{
								h = str_to_int(s);
								break;
							}
					}
				else
					h = str_to_int(s);
			if (h == 1)
				cout << "����� ������� ����� " << a.get_volume() << endl;
			else
				if (h == 2)
					cout << "������� ���� ������� ����� " << a.get_area() << endl;
				else
					if (h == 3)
					{
						cout << "����� ���������� �������:" << endl;
						cout << "����� ������� ����� " << a.get_length() << endl;
						cout << "������ ������� ����� " << a.get_width() << endl;
						cout << "������ ������� ����� " << a.get_height() << endl;
						cout << "���������� ���� � ������� ����� " << a.get_windows_count() << endl;
					}
					else
						if (h == 4)
						{
							RoomWithWallpaper b = RoomWithWallpaper(l, w, a.get_height(), c);
							cout << "������� ���� � ����� " << b.walls_area() << endl;
							cout << "����������� ���-�� ����� � ������ ���� " << b.get_wallpaper_area() << endl;
						}

		}
		cout << "���� ������ ��������� ������ ��������� ������� 0, � ���� ������ ����� ������ ������\n";
		cin >> s;
		if (check(s) == 3)
			break;
	}
	return 0;
}


