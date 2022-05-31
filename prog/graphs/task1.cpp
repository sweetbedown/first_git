//��� ����������������� ����. ������� ���������� ������, ������� � ������
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");

int main() 
{
	setlocale(LC_ALL, "Russian");

	int x, N;
	in >> N; // ���������� ������ � �����

	vector<vector<int>> graph;
	graph.resize(N);

	int r;
	vector<int> vertex;
	vertex.resize(N);

	for (int i = 0; i < N; i++)
	{
		in >> x; // ���������� ������� ������
		vertex.push_back(i);
		for (int j = 0; j < x; j++)
		{

			in >> r; // ���� ������� ������� 
			graph[i].push_back(r);
		}
	}

	int a;

	cout << "������� ����� ������� : "; cin >> a;

	cout << "�� ������� ������� : ";
	for (int i = 0; i < N; i++) 
	{
		int c = 0;
		for (int j = 0; j < graph[a].size(); j++) 
		{
			if (i == graph[a][j]) c++;
		}
		if (c == 0) cout << i << " ";
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