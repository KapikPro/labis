#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void min(vector<double> mas)
{
	int min=mas[0];
	for (int i = 1; i < mas.size(); i++)
		if (min > mas[i])
			min = mas[i];
	cout << "���������� �������� ����� ������� =" << min<<endl;
	if (min == 0)
		cout << "���������� �������� ����� ������� = 0, ������� �� ������ �� ��������" << endl;
	else
		cout << "���������� ����������� �������� =" << min + abs(min) << endl;
	cout << endl;
}
int main()
{
	setlocale(LC_ALL,"Russian");
	int i, n;
	cout << "������� ���������� ��������� � ������� �" << endl;
	cin >> n;
	vector<double> a(n);
	cout << "������� ������ �" << endl;
	for (i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	min(a);
	cout << "������� ���������� ��������� � ������� b" << endl;
	cin >> n;
	vector<double> b(n);
	cout << "������� ������ b" << endl;
	for (i = 0; i <b.size() ; i++)
	{
		cin >> b[i];
	}
	min(b);
}