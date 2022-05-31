//Дан ориентированный граф. Подсчитать полустепень захода каждой вершины.
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("output.txt");

int main() 
{
	setlocale(LC_ALL, "Russian");

	int x, N, r;
	in >> N;

	vector<vector<int>> graph;
	graph.resize(N);
	vector<int> count;
	count.resize(N);

	for (int i = 0; i < N; i++) 
	{
		count[i] = 0;
	}

	for (int i = 0; i < N; i++) 
	{
		in >> x;
		if (x != 0) 
		{
			for (int j = 0; j < x; j++) 
			{
				in >> r;
				graph[i].push_back(r);
				count[r]++;
			}
		}
	}

	for (int i = 0; i < N; i++) 
	{
		cout << "Полустепень Захода " << i << " вершины : " << count[i] << endl;
	}

	return 0;
}
//5
//1
//3
//2
//2 3
//0
//2
//2 4
//1
//3