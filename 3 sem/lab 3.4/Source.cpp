#include<iostream>
#include"tools.h"
#include"task_class.h"
#include"task_massiv.h"
using namespace std;
void work_with_massiv()
{
	cout << "1-�������� ������� � ������\n2-����� ���-�� ������������� ��������� �������\n3-";
}
void work_with_class()
{

}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "1-������� � �������� �������\n2-������� � �������� ������\n";
	while (try_read_int(a) != 1 && (a != 1 || a != 2))
		cout << "������� ����� 1 ��� 2!\n";
	if (a == 1)
		work_with_massiv();
	else
		work_with_class();
}
