//��� ����������������� ����. ������� �����, ����������� ������� � � B
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");

int main() 
{
	setlocale(LC_ALL, "Russian");

	int x, N, a, b;
	in >> N; // ���������� ������ � �����

	vector<vector<int>> graph;
	graph.resize(N);

	int r;
	vector<int> vertex;
	vertex.resize(N);
	cout << "������� ������� A � B : "; cin >> a >> b;

	for (int i = 0; i < N; i++)
	{
		in >> x; // ���������� ������� ������
		if ((i != a) && (i != b)) 
		{
			for (int j = 0; j < x; j++)
			{
				in >> r; // ���� ������� ������� 
				graph[i].push_back(r);
			}
		}
		else
		{
			int c;
			if (i == a) c = b;
			else c = a;
			for (int j = 0; j < x; j++)
			{
				in >> r; // ���� ������� ������� 
				if (r != c)
				{
					graph[i].push_back(r);
				}
			}
		}
		
	}

	for (int i = 0; i < N; i++) 
	{
		cout << i << " : ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
//7
//4
//1 2 4 5
//2
//0 3
//2
//0 5
//1
//1
//2
//0 6
//3
//0 2 6
//2
//4 5