#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void print(vector<int> vec) 
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) 
		cout << *it << " "; 
	cout << "\n";
}

vector<int> create_vector(int n) 
{
	vector<int> vec;

	for (int i = 0; i < n; i++) 
	{
		int x; cin >> x;
		vec.push_back(x);
	}

	return vec;
}

void class_sort(vector<int>& vec, int k_10, int n) 
{

	vector<vector<int>> DopVec;
	DopVec.resize(10);

	for (int j = 0; j < n; j++)
		DopVec[(vec[j] / k_10) % 10].push_back(vec[j]); //Записываем числа, с одинаковыми старшими разрядами в отдельные массивы

	for (int i = 0; i < 10; i++)
		if (DopVec[i].size() > 1)
			class_sort(DopVec[i], k_10 / 10, DopVec[i].size()); //Рекурсивно вызываю сортировку для подмассивов

	vec.clear();

	for (int j = 0; j < 10; j++) 
	{
		for (vector<int>::iterator it = DopVec[j].begin(); it != DopVec[j].end(); it++) //Записываю отсортированные подмассивы в результирующий
			vec.push_back(*it);
		DopVec[j].clear();
	}
}

void SortRadixMSD(vector<int> &vec, int n) {
	//Поиск максимального элемента
	int mx = 0;
	for (int i = 0; i < n; mx = max(mx, vec[i]), ++i);

	//Вычисление максимального разряда
	int k = 0;
	for (int i = 0; mx > 0; ++k, ++i)
		mx /= 10;

	//10^k
	int k10 = 1;
	for (int i = 0; i < k - 1;  i++)
		k10 *= 10;
	
	class_sort(vec, k10, n);
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	int n; 
	cout << "Количество элементов = "; cin >> n;

	vector<int> vec = create_vector(n);

	SortRadixMSD(vec, n); 
	
	print(vec);
}

//41 8467 6334 6500 9169 5724 1478 9358 6962 4464
//41 1478 4464 5724 6334 6500 6962 8467 9169 9358