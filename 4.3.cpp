#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
double m()//work with massive;
{
	cout << "������� ������ �������" << endl;
	int n;
	double min;
	cin >> n;
	vector<double> mas(n);
	cout << "������� ���� ������" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		if (i == 0)
			min = mas[i];
		else
			if (min > mas[i])
				min = mas[i];
	}
	return min;
}
int main()
{
	setlocale(LC_ALL, "Russian");


	int a = m();
	int b = m();
	int c = m();
	cout << "������������ ����������� �������� ����� " << max(a, max(b, c))<<endl;
	if ((max(a, max(b, c)) == a) && (max(a, max(b, c)) == b) && (max(a, max(b, c)) == c))
		cout << "����������� �������� ���� ���� �������� �����" << endl;
	else
		if ((max(a, max(b, c)) == a) && (max(a, max(b, c)) == b))
			cout << "����������� �������� �������� � � b ����� � �������� ������������� " << endl;
		else
			if ((max(a, max(b, c)) == a) && (max(a, max(b, c)) == c))
				cout << "����������� �������� �������� � � � ����� � �������� ������������� " << endl;
			else
				if ((max(a, max(b, c)) == c) && (max(a, max(b, c)) == b))
					cout << "����������� �������� �������� � � � ����� � �������� ������������� " << endl;
}