//Дан неориентированный граф. Удалить ребро, соединяющее вершины А и B
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
	in >> N; // Количество вершин в графе

	vector<vector<int>> graph;
	graph.resize(N);

	int r;
	vector<int> vertex;
	vertex.resize(N);
	cout << "Введите вершины A и B : "; cin >> a >> b;

	for (int i = 0; i < N; i++)
	{
		in >> x; // Количество смежных вершин
		if ((i != a) && (i != b)) 
		{
			for (int j = 0; j < x; j++)
			{
				in >> r; // Сами смежные вершины 
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
				in >> r; // Сами смежные вершины 
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