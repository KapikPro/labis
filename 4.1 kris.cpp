#include<iostream>
using namespace std;
void o(int a[5], int l, int &k)
{
	for (int i = 0; i != 5; ++i)
	{
		if (a[i] < l)
		{
			a[i] = 0;
			k = k + 1;
		}
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a[5], b[5], k = 0, l = 0;
	cout << "������� ������ �" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cin >> a[i];
	}
	cout << "������� ������ b" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cin >> b[i];
	}
	cout << "���������� ������ �: " << endl;
	o(a,0, k);
	cout << "���������� ������ b: " << endl;
	o(b, -10, l);
	
	if (k > l)
	{
		cout << "� ������� � ���-�� ����� ������";
	}
	else
		if(l>k)
	{
		cout << "� ������� b ���-�� ����� ������";
	}
		else
			cout << "���-�� ����� � �������� ���������";
}