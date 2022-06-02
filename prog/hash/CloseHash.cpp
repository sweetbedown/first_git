//Двойное + умножение по стажу
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

ifstream in("input.txt");

double A = 0.61803;

struct chel {
	string name;
	string work;
	string data;
	int experience = 0;
	int salary = 0;
};

vector<chel> inFile() {
	vector<chel> x;
	chel man;
	while (in.peek() != EOF) {
		in >> man.name;
		in >> man.work;
		in >> man.data;
		in >> man.experience;
		in >> man.salary;
		x.push_back(man);
	}
	return x;
}



int main() {
	setlocale(LC_ALL, "Russian");

	vector<chel> people;
	people = inFile();
	int M = 21, MM = 20;
	vector <chel> Hash;
	Hash.resize(M);

	for (int i = 0; i < M; i++) {
		Hash[i].experience = -1;
	}

	for (int i = 0; i < people.size(); i++) {
		int j = 0;
		double x = A * people[i].experience;
		double n;
		int h1 = M * modf(x, &n);
		int h2 = 1 + MM * modf(x, &n);
		while (true) {
			int k = (h1 + j*h2) * modf(x, &n);
			while (k >= M) {
				k = k * modf(x, &n);
			}
			if (Hash[k].experience == -1) {
				Hash[k] = people[i];
				break;
			}
			else {
				j++;
			}
		}

	}
	cout << "HASH TABLE : " << endl;
	for (int i = 0; i < M; ++i) {
		cout << i << " : ";
		if (Hash[i].experience != -1)
			cout << Hash[i].name << " " << Hash[i].work << " " << Hash[i].data << " " << Hash[i].experience << " " << Hash[i].salary << endl;
		else
			cout << "NULL" << endl;;
	}
	cout << endl;

	cout << "Add person :" << endl;
	chel man;
	cout << "Заполните данные :" << endl;
	cout << "Имя :"; cin >> man.name;
	cout << "Должность :"; cin >> man.work;
	cout << "Дата рождения :"; cin >> man.data;
	cout << "Стаж :"; cin >> man.experience;
	cout << "Зарплата :"; cin >> man.salary;
	if (man.experience != -1) {
		int j = 0;
		double x = A * man.experience;
		double n;
		int h1 = M * modf(x, &n);
		int h2 = 1 + MM * modf(x, &n);
		while (true) {
			int k = (h1 + j * h2) * modf(x, &n);
			while (k >= M) {
				k = k * modf(x, &n);
			}
			if (Hash[k].experience == -1) {
				Hash[k] = man;
				break;
			}
			else {
				j++;
			}
		}
	}
	cout << endl;
	cout << "HASH TABLE(after adding person): " << endl;
	for (int i = 0; i < M; ++i) {
		cout << i << " : ";
		if (Hash[i].experience != -1)
			cout << Hash[i].name << " " << Hash[i].work << " " << Hash[i].data << " " << Hash[i].experience << " " << Hash[i].salary << endl;
		else
			cout << "NULL" << endl;;
	}
	cout << endl;

	int o;
	cout << "Enter the person's experience to search : ";
	cin >> o;
	int j = 0;
	double x = A * o;
	double n;
	int h1 = M * modf(x, &n);
	int h2 = 1 + MM * modf(x, &n);
	while (true) {
		int p = (h1 + j * h2) * modf(x, &n);
		while (p >= M) {
			p = p * modf(x, &n);
		}
		if (Hash[p].experience == o) {
			cout << Hash[p].name << " " << Hash[p].work << " " << Hash[p].data << " " << Hash[p].experience << " " << Hash[p].salary << endl;
			break;
		}
		else {
			j++;
		}
	}

	return 0;
}