#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
void check(vector<vector<int>> mas,vector<int> b)
{
	bool rez;
	for (int i = 0; i < mas.size(); i++)
	{
		rez = 1;
		for (int j = 0; j < mas[i].size() - 1; j++)
			if (mas[i][j] == mas[i][j + 1])
			{
				b[i] = 2;
				break;
			}
			else
			  if (mas[i][j] > mas[i][j + 1])
				  rez = 0;
			  else
				  if ((rez == 0 && mas[i][j] < mas[i][j + 1]) || (j>1 && rez==0 && mas[i][j-1] < mas[i][j]))
				  {
					  b[i] = 2;
					  break;
				  }
		if (b[i] != 2)
		{
			if (rez == 1)
				b[i] = 1;
			else
				b[i] = 0;
		}
	}
	cout << "����� ������� b" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == 2)
			cout << i + 1 << ") ��� ������ ������" << endl;
		else
			cout << i + 1 << ")" << b[i] << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ����� � �������� �������" << endl;
	int n, k;
	cin >> n >> k;
	cout << "������� ���� ������" << endl;
	vector<vector<int>> mas(n, vector<int>(k));
	for (int i = 0; i < mas.size(); i++)
		for (int j = 0; j < mas[i].size(); j++)
			cin >> mas[i][j];
	vector<int> b(n);
	check(mas, b);
}