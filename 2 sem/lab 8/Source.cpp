#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include<algorithm>
using namespace std;
int check(double a, double b, double (*f)(double))
{
	if (f(a) * f(b) > 0)
		return 0;
	else
		return 1;
}
double f1(double t)
{
	double o = (1.5 - (pow(t, 0.5) + pow(t, (1.0/3))) / pow(2.7, 1.5) - t);
	return o;
}
double f2(double t)
{
	double o = (0.5 * (2 - sin((1 + t) / t) - 0.5 * (log(pow(t, 0.5)))) - t);
	return o;
}
void m_otr(double (*f)(double), double a, double b,double *z,int n, int* it)
{

	double x, y1=a,y2=b;
	int c = 0, u=0;
	double e = 0.1; 
	while(c<n)
	{
		a = y1;
		b = y2;
		do 
		{
			x = (a + b) / 2;
			u++;
			if (f(b) * f(x) > 0)
				b = x;
			else
				a = x;
		} while (b - a >= e);
		z[c] = x;
		it[c] = u;
		u = 0;
		c++;
		e = e / 10;
	}
}
void m_hord(double (*f)(double), double a, double b, double* z, int n , int* it)
{
	double x, y1 = a, y2 = b;
	int c = 0, u = 0;
	double e = 0.1,d;
	while (c < n)
	{
		do {
			x = a - (f(a) / ((f(b) - f(a)) / (b - a)));
			u++;
			if (f(b) * f(x) > 0)
			{
				
				d = x - b;
				b = x;
			}
			else
			{
				d = x - a;
				a = x;
			}
		} while (abs(d) >= e);
		z[c] = x;
		it[c] = u;
		u = 0;
		c++;
		e = e / 10;
		a = y1;
		b = y2;
	}
}
void out(double* x1, double* x2,int n, int* it1,int* it2)
{
	cout << "\n";
	int c = 0;
	double e;
	cout << "e            �����(1)      ��  �����(2)      ��\n";

	while (c < n)
	{
		e = pow(10, -(c+1));
		
		printf("%1.10f %1.10f %3d %1.10f %3d\n",e,x1[c],it1[c],x2[c],it2[c]);
		//� ������������� ���-��� ������ � ��� � �� ����������
		//���� ��� �� ��������,�� � ����� ������ � ��� �� ���� � ������� ��� ��� ��������
		c++;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	double x1[10], x2[10];
	int it1[10], it2[10];

	int n;
	cout << "������� �,b � n\n";
	cin >> a >> b >> n;
	while (true)
		if ((n < 1 || n>10) || (a >= b || a < 0 || a>2 || b < 0 || b>2))
		{
			cout << "������� ������������ ������� ������, ������� �� ��� ���\n";
			cin >> a >> b >> n;
		}
		else
			break;
	if (check(a, b, f1) == 0)
		cout << "� ������ f1 ����� �� ������ ������� ���\n";
	else
	{
		m_otr(f1, a, b, x1, n, it1);
		m_hord(f1, a, b, x2, n,it2);
		cout << "������ �������\n";
		out(x1, x2,n, it1, it2);
	}
	cout << "\n\n";
	if (check(a, b, f2) == 0)
		cout << "� ������ f2 ����� �� ������ ������� ���\n";
	else
	{
		m_otr(f2, a, b, x1, n, it1);
		m_hord(f2, a, b, x2, n, it2);
		cout << "������ �������\n";
		out(x1, x2,n, it1, it2);
	}
	

}