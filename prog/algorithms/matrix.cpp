#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;

vector<vector<int>> In(vector<vector<int>> a) // ���� �������
{
	cout << "������� ������� : " << endl;
	int x;

	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= n; ++j) 
		{
			cin >> x;
			a[i][j] = x;
		}
	}

	cout << endl;
	return a;
}

void Out(vector<vector<int>> a) // ����� �������
{
	cout << "���� : " << endl;

	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= n; ++j) 
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void grape_mult(vector<vector<int>> a, vector<vector<int>> b) // ������������� ���������� ���������
{
	vector<vector<int>> res; // �������������� �������
	res.resize(n+1);
	for (int i = 1; i <= n; i++) 
	{
		res[i].resize(n+1);
	}

	if (n == 1) // ���� ����������� = 1 - ������������� ������������ �������� 
	{
		cout << "���� : " << endl;
		cout << a[1][1] * b[1][1] << endl;
	}
	else 
	{ 
		int k = n / 2 ;

		vector<int> F1;
		F1.resize(n + 1); // ������ ��������� ��� ���������
		for (int i = 1; i <= n; i++) 
		{
			F1[i] = a[i][1] * a[i][2];
			for (int j = 2; j <= k; j++) 
			{
				F1[i] += a[i][2 * j - 1] * a[i][2 * j];
			}
		}

		vector<int> F2;
		F2.resize(n + 1); // ������ ��������� ��� ���������
		for (int i = 1; i <= n; i++) 
		{
			F2[i] = b[1][i] * b[2][i];
			for (int j = 2; j <= k; j++)
			{
				F1[i] += b[2 * j - 1][i] * b[2 * j][i];
			}
		}

		for (int i = 1; i <= n; i++) // ���������� ����������
		{
			for (int j = 1; j <= n; j++) 
			{
				res[i][j] = - F1[i] - F2[j];
				for (int z = 1; z <= k ; z++) 
				{
					res[i][j] += (a[i][2 * z - 1] + b[2 * z][j]) * (a[i][2 * z] + b[2 * z - 1][j]);
				}
			}
		}

		if (n % 2 != 0) // ���� n ����� �� �������� � ��������� ������� res �����������
		{
			for (int i = 1; i <= n; i++) 
			{
				for (int j = 1; j <= n; j++) 
				{
					res[i][j] += a[i][n] * b[n][j];
				}
			}
		}
		Out(res);
	}
}

int main() 
{
	setlocale(LC_ALL, "RUS");

	cout << "������� ����������� ������ n*n : " << endl;
	cin >> n;

	vector<vector<int>> a;
	vector<vector<int>> b;
	a.resize(n+1);
	b.resize(n+1);

	for (int i = 1; i <= n;i++) 
	{
		a[i].resize(n+1);
		b[i].resize(n+1);
	}

	a = In(a);
	b = In(b);

	grape_mult(a, b);

	return 0;
}
