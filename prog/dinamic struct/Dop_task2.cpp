//Граф представлен в виде списка смежности.Реализовать обход в ширину, используя очередь, и нерекурсивный обход в глубину.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("input.txt");

struct queue // очередь
{ 
	int inf;
	queue * next;
};

void pushQ(queue*& h, queue*& t, int x) // Добавление элемента в начало очереди
{ 
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) 
	{
		h = t = r;
	}
	else 
	{
		t->next = r;
		t = r;
	}
}

int popQ(queue*& h, queue*& t)  // Удаление элемента из очереди с возвращением его значения
{
	queue* r = h;
	int i = h->inf;
	h = h->next;
	if (!h)
		t = NULL;
	delete r;
	return i;
}

struct stack // Стек
{
	int inf;
	stack* next;
};

void pushS(stack *&h, int x) // Добавление элемента в стек
{ 
	stack * r = new stack; 
	r -> inf = x; 
	r -> next = h; 
	h = r; 
}

int popS(stack * &h) { // Удаление элемента из стека с возвращением его значения
	int i = h -> inf; 
	stack * r = h; 
	h = h -> next; 
	delete r; 
	return i; 
}

void reverseS(stack * &h)  // Перевернуть стек
{ 
	stack * h1 = NULL; 
	while (h) 
		pushS(h1, popS(h)); 
	h = h1; 
}


void helperW(queue* h,queue*t,int k, vector<vector<int>> Gr, vector<int> visit) //помощник для обхода в ширина
{
	pushQ(h, t, k);
	visit[k] = 1;
	cout << k << " ";
	while (h) 
	{
		int y = popQ(h, t);
		for (int i = 0; i < Gr[y].size(); i++) 
		{
			int j = Gr[y][i];
			if (visit[j] == 0) 
			{
				cout << j << " ";
				visit[j] = 1;
				pushQ(h, t, j);
			}
		}

	}
}



vector<int> helperD(int k, vector<vector<int>> Gr, vector<int> visit, stack* A) // помощник для обхода в глубину
{
	pushS(A, k);
	cout << k << " ";
	bool f1 = false;
	int y;
	visit[k] = 1;
	while (A) 
	{
		int k = A->inf;
		for (int i = 0; i < Gr[k].size();i++) 
		{
			if (visit[Gr[k][i]] == 0) 
			{
				y = Gr[k][i];
				f1 = true;
				break;
			}
			else 
			{
				f1 = false;
			}
		}
		if (f1 == true) 
		{
			visit[y] = 1;
			pushS(A, y);
			cout << y << " ";
		}
		else 
		{
			popS(A);
		}
	
	}
	return visit;
}

void width(int N, vector<vector<int>> Gr) //обход в ширину с использованием очреди
{
	queue* h = NULL;
	queue* t = NULL;
	int k;

	cout << "Начать обход с : " << endl;
	cin >> k;

	vector<int> visit;
	visit.resize(N);
	for (int i = 0; i < N; i++) 
	{
			visit.push_back(0);
	}

	helperW(h, t, k, Gr, visit);
	cout << endl;
}

void deep(int N, vector<vector<int>> Gr) { // Обход в глубину
	int k;
	stack* A = NULL;
	cout << "Начать обход с : " << endl;
	cin >> k;
	vector<int> visit;
	visit.resize(N);
	for (int i = 0; i < N; i++) {
		visit.push_back(0);
	}
	visit = helperD(k, Gr, visit, A);
	for (int i = 0; i < N; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;
			visit = helperD(i, Gr, visit, A);
		}
	}
}


int main() 
{
	setlocale(LC_ALL, "Russian");

	int E, N;
	in >> N;

	vector<vector<int>> Reb;
	vector<int> Conect;
	Reb.resize(N);
	int r;

	for (int i = 0; i < N; i++) //Заполняем элементами
	{
		in >> E;
		Conect.push_back(E);// количество ребер
		for (int j = 0; j < E; j++)
		{
			in >> r;
			Reb[i].push_back(r);//смежные вершины
		}
	}

	for (int i = 0; i < N; i++)  //вывод графа
	{
		for (auto j = 0; j < Conect[i]; j++) 
		{
			cout << Reb[i][j] << " ";
		}
		cout << endl; 
	}
	Shirina(N, Reb);
	Glubina(N, Reb);
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
//2
//2 6
//6
//4 5
