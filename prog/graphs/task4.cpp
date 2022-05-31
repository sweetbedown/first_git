//Дан неориентированный граф. Является ли граф связным
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");

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
		in >> x;
		count[i] = x;
		if (x != 0) 
		{
			for (int j = 0; j < x; j++) 
			{
				in >> r;
				graph[i].push_back(r);
			}
		}
	}

	int c = 0;

	for (int i = 0; i < N; i++) 
	{
		if (count[i] == N - 1) c++;
	}

	if (c == N) cout << "Связный";
	else cout << "Не связный";

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