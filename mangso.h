#pragma once
#include <iostream>

using namespace std;

class mangso
{
private:
	int n, a[100];
public:
	friend istream &operator >>(istream &input, mangso &dt);
	friend ostream &operator <<(ostream &ouput, mangso &dt);
};

istream &operator >>(istream &input, mangso &dt)
{
	do
	{
		cout << "Nhap so phan tu:";
		input >> dt.n;
		if (dt.n <= 0 || dt.n >= 100) cout << "\t\tGia Tri Khong Hop Le!\n";
	} while (dt.n <= 0 || dt.n >= 100);

	for (int i = 0; i < dt.n; i++)
	{
		cout << "Nhap A[" << i + 1 << "] = ";
		input >> dt.a[i];
	}

	return input;
}

ostream &operator <<(ostream &ouput, mangso &dt)
{
	ouput << "-Cac phan tu chan ngoai 4 va 10 la:";
	long tich = 1;
	for (int i = 0; i < dt.n; i++)
	{
		if (dt.a[i] % 2 == 0 && dt.a[i] != 4 && dt.a[i] != 10)
		{
			ouput << "  " << dt.a[i];
			tich *= dt.a[i];
		}
		
	}

	ouput << ", tich la:" << tich;


	int b[100][2], m=0, flag = 0;
	for (int i = 0; i < dt.n; i++)
	{
		flag = 0;
		for (int j = 0; j < m; j++)
		{
			if (dt.a[i] == b[j][0])
			{
				flag = 1;
				b[j][1]++;
				continue;
			}
				
		}
		if (flag == 0)
		{
			b[m][0] = dt.a[i];
			b[m][1] = 1;
			m++;
		}
	}
	int c[100], x = 0;
	for (int i = 0; i < m; i++)
	{
		if (b[i][1] == 1)
		{
			c[x] = b[i][0];
			x++;
		}
	}
	for (int i = 0; i <x-1; i++)
	{
		for (int j = i+1; j < x; j++)
		{
			if (c[i] < c[j])
				swap(c[i], c[j]);
		}
	}
	cout << "\n-Sap xep giam dan: ";
	for (int i = 0; i < x; i++)
	{
		ouput << "  " << c[i];
	}
	return ouput;
}