//Дан ориентированный граф. Найти все сильно связные компоненты графа.
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

ifstream in("input.txt");

vector<int> order;
vector<int> path;

void dfs1(vector<vector<int>>& Gr, int x, bool* used) 
{
	used[x] = 1;
	for (int i = 0; i < Gr[x].size(); ++i)
		if (!used[Gr[x][i]])
			dfs1(Gr, Gr[x][i], used);
	order.push_back(x);
}

void dfs2(vector<vector<int>>& Gr, int x, bool* used) 
{
	used[x] = 1;
	path.push_back(x);
	for (int i = 0; i < Gr[x].size(); ++i)
		if (!used[Gr[x][i]])
			dfs2(Gr, Gr[x][i], used);
}

int main() 
{
	setlocale(LC_ALL, "Russian");

	int x, n, r;
	in >> n;

	vector<vector<int>> gr;
	gr.resize(n);
	vector<vector<int>> grT;
	grT.resize(n);

	for (int i = 0; i < n; i++) 
	{
		in >> x;
		if (x != 0) 
		{
			for (int j = 0; j < x; j++) 
			{
				in >> r;
				gr[i].push_back(r);
				grT[r].push_back(i);
			}
		}
	}

	for (int i = 0; i < n; ++i) sort(grT[i].begin(), grT[i].end());

	bool* used = new bool[n];
	for (int i = 0; i < n; ++i) used[i] = 0;

	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(gr, i, used);

	for (int i = 0; i < n; ++i) used[i] = 0;

	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(grT, v, used);
			sort(path.begin(), path.end());
			for (vector<int>::iterator it = path.begin(); it != path.end(); cout << *it << " ", ++it);
			cout << "\n";
			path.clear();
		}
	}

	return 0;
}
//8
//1
//1
//3
//2 4 5
//1
//3
//2
//2 7
//2
//0 5
//1
//6
//1
//5
//2
//3 6
