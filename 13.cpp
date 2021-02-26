#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;

void f1(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 200 - 100;
		cout << a[i] << endl;
	}
}

void f2(int *a, int n)

{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}


void f3(int* a, int n)
{
	ifstream fin;
	fin.open("C:\\Users\\User\\Desktop\\������������\\3 ����\\input1.txt"); // ��������� ������ � ������
	//if(fin.is_open())
	for (int i = 0; i < n; i++)
	{
		fin >> a[i]; // ������ �� ����� ����
	}

	fin.close();

}

void MasOper(int *a, int n)
{
	int j = 0;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			j++;
	}


	if (j < 2)
		cout << "������ 2-�� ������������� �����!" << endl;
	else
	{
		cout <<"�������� 2 ������������� �����" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			sum += a[i];
	}
	cout << "����� ������������� ���������=" << sum << endl;

	for (int i = 0; i < n; i++)
	{
		a[i] += sum;
		cout << a[i] << endl;
	}


	int t1 = a[0], t2 = a[1];

	for (int i = 0; i < n - 2; i++)
	{
		a[i] = a[i + 2];
	}

	a[n - 2] = t1;
	a[n - 1] = t2;
}
void MasOutput(int* a, int n)
{
	cout << "\n�����: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

void MasOutputToFile(int* a, int n)
{
	ofstream fout;
	fout.open("C:\\Users\\User\\Desktop\\������������\\3 ����\input1.txt"); // ��������� ������ � ������
	
	for (int i = 0; i < n; i++)
	{
		fout << a[i] << endl; // ������ ������ � ����
	}

	fout.close(); // ��������� ����;
}

int  main()
{
	setlocale(LC_ALL, "Russian");
	int a[100];
	int n; // -���-�� ��������� � �������;
	int k;
	srand(time(NULL));
	cout << "������� �������� n=";
	cin >> n;
	if (n < 0)
	{
		cout << "������!���������� �����" << endl;
		cin >> n;
	}
	

	cout << "1.���� ���������\n2.���� � ����������\n3.���� � �����\n" << endl;
	cin >> k;

	switch (k)
	{
	case 1: f1(a, n);
		break;
	case 2: f2(a, n);
		break;
	case 3: f1(a, n);
		break;
	}
	MasOper(a, n);
	MasOutput(a, n);
	MasOutputToFile(a, n);
	return 0;
}
