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
	cout << a;
	int b = m();
	cout << b;
	int c = m();
	cout << c;
	cout << "������������ �������� ����� " << max(a, max(b, c));
	

}