

int main()
{
	VanPhong d[100];
	int n;

	do
	{
		cout << "\tNhap so luong nhan vien van phong:";
		cin >> n;
		if (n < 0 || n > 100) cout << "\t\tGia Tri Khong Hop Le!\n";
	} while (n < 0 || n >100);

	for (int i = 0; i < n; i++)
	{
		d[i].nhap();
	}

	VanPhong max = d[0];
	for (int i = 0; i < n; i++)
	{
		if (max.heSoLuong < d[i].heSoLuong)
			max = d[i];
	}

	cout << "\nNhan vien co luong cao nhat: \n";
	max.xuat();

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (d[i].heSoLuong > d[j].heSoLuong)
				swap(d[i].heSoLuong > d[j].heSoLuong);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		d[i].xuat();
	}

	return 0;
}
