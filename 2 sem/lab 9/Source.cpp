#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include<algorithm>
using namespace std;
void input(int& n, double*& x)
{
    FILE* f;
    if ((f = fopen("fin.txt", "r")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    fscanf(f, "%d", &n);
    x = new double[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%lf", (x + i));
    }
    fclose(f);
}
void output(int count)
{
    FILE* f;
    if ((f = fopen("fout.txt", "w")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
  fprintf(f,"� ������ ������� %d ���������� ������\n", count);
    fclose(f);
}
int counting(int a,int b,double *x)
{
    int count = 0;
    if (b - a != 0 && b-a!=1)
    {
        count+=counting(a, (a+b) / 2-1, x);
        count+=counting((a+b) / 2, b, x);
    }
    else
        if (b - a == 1)
        {
           count+= counting(a, a, x);
           count+= counting(b, b, x);
        }
        else
        if (sin((*(x + a)) / 2) < 0)
            count++;
    return count;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n,kol=0,gl=0;
    double* x;
    input(n, x);
    int count = counting(0,n-1,x);
    output(count);
   
}