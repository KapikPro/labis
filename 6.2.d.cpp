#include<iostream>
#include <stdio.h>
#include <string.h>
#include<vector>
#include<string>
using namespace std;
void sl(string s,vector<string> &a)
{
	bool o = 0;
	string k;
	for (int i = 0; i < s.length(); i++)
	{
			if ((s[i] == ' ' || s[i] == '.') && k != "")
			{
				for (int i = 0; i < a.size(); i++)
					if (k == a[i])
					{
						o = 1;
						break;
					}
				if (o == 0)
				{
					a.push_back(k);
					k.clear();
				}
				else
					k.clear();
				o = 0;
			}
			else
				if (s[i] != ' ' && s[i] != '.')
					k += s[i];
	    
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> c;
	string s;
	cout << "������� ������ �����\n";
    getline(cin,s);
	sl(s, c);
	int i;
	cout << "������� ������ ����, ������� ����� �������\n";
	cin >> i;
	cout << "������� �����:\n";
	for (int l = 0; l < c.size(); l++)
	{
		if (c[l].length() == i)
			cout << c[l] << endl;
	}
}