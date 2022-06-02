//Умножение по стажу
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

ifstream in("input.txt");

double A = 0.61803;

struct people 
{
	string name;
	string work;
	string data;
	int experience = 0;
	string salary;
};

struct list 
{
	people inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, people x) // Добавление в список
{
	list* r = new list;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t) {
		r->prev = nullptr;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list* h, list* t)  //Вывод элемента
{
	list* p = h;
	while (p) 
	{
		cout << p->inf.name << " " << p->inf.work << " " << p->inf.data << " " << p->inf.experience << " " << p->inf.salary << endl;
		p = p->next;
	}
}

void del_node(list*& h, list*& t, list* r)  // Удаление элемента
{
	if (r == h && r == t)
		h = t = nullptr;
	else if (r == h) 
	{
		h = h->next;
		h->prev = nullptr;
	}
	else if (r == t) 
	{
		t = t->prev;
		t->next = nullptr;
	}
	else 
	{
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}

vector<people> inFile() //Считывание из файла
{
	vector<people> x;
	people man;
	while (in.peek() != EOF) 
	{
		in >> man.name;
		in >> man.work;
		in >> man.data;
		in >> man.experience;
		in >> man.salary;
		x.push_back(man);
	}
	return x;
}

list* find(list* h, list* t, int x) //Поиск элемента
{
	list* p = h;
	while (p) //Идём в конец списка, пока не равно Х
	{
		if (p->inf.experience == x) 
			break;
		p = p->next;
	}
	return p;
}

vector<people>  Add_people(vector <pair<list*, list*>>& Hash, int M, vector<people> chel) //Ввод человека + добавление
{
	people man;
	cout << "Заполните данные :" << endl;
	cout << "Имя :"; cin >> man.name; cout << endl;
	cout << "Должность :"; cin >> man.work; cout << endl;
	cout << "Дата рождения :"; cin >> man.data; cout << endl;
	cout << "Стаж :"; cin >> man.experience; cout << endl;
	cout << "Зарплата :"; cin >> man.salary; cout << endl;


	double x = A * man.experience;
	double n;
	int g = M * modf(x, &n);
	push(Hash[g].first, Hash[g].second, man);
	chel.push_back(man);

	cout << "Хэш-таблица(После добавления человека): " << endl;
	for (int i = 0; i < Hash.size(); ++i) {
		cout << i << " : " << endl;
		print(Hash[i].first, Hash[i].second);
		cout << endl;
	}
	return chel;
}

int main() {
	
	setlocale(LC_ALL, "Russian");
	vector<people> people;
	people = inFile();
	int M = 16;
	vector <pair<list*, list*>> Hash; //Объявляем хэш-таблицу
	Hash.resize(M);

	for (int i = 0; i < M; ++i) 
	{
		Hash[i].first = NULL;
		Hash[i].second = NULL;
	}

	
	for (int i = 0; i < people.size(); i++) 
	{
		double x = A * people[i].experience;
		double n;
		int g = M * modf(x, &n);
		push(Hash[g].first, Hash[g].second, people[i]);
	}

	cout << "Хэш-таблица : " << endl;
	for (int i = 0; i < Hash.size(); ++i) 
	{
		cout << i << " : " << endl;
		print(Hash[i].first, Hash[i].second);
		cout << endl;
	}

	people = Add_people(Hash, M, people);
	cout << endl;
	cout << endl;

	int k;
	cout << "Введите стаж, чтобы найти человека : ";
	cin >> k;
	double x = A * k;
	double n;
	int g = M * modf(x, &n);
	list* p = find(Hash[g].first, Hash[g].second, k);
	if (p) 
	{
		cout << p->inf.name << " " << p->inf.work << " " << p->inf.data << " " << p->inf.experience << " " << p->inf.salary << endl;
	}
	else 
	{
		cout << " Ничего не найдено " << endl;
	}

	cout << "Введите стаж, чтобы удалить человека : ";
	cin >> k;
	x = A * k;
	g = M * modf(x, &n);
	p = find(Hash[g].first, Hash[g].second, k);
	if (p) 
	{
		del_node(Hash[g].first, Hash[g].second, p);
	}
	else 
	{
		cout << " Ничего не найдено " << endl;
	}

	cout << "Хэш-таблица(После удаления эл.): " << endl;
	for (int i = 0; i < Hash.size(); ++i) 
	{
		cout << i << " : " << endl;
		print(Hash[i].first, Hash[i].second);
		cout << endl;
	}

	return 0;
}
//PUPKIN Director 19.4.1960 41 200000
//ABALDUEV Auditor 20.5.1988 9 60000
//BABAKHIN TheCashier 30.07.1980 11 40000
//WADBAL Inspector 22.09.1977 13 70000
//GAVESHIN Broker 04.11.1994 5 150000
//GALICIAN Operator 23.01.1974 18 80000
//DANILOV Lawyer 09.03.1990 7 50000
//EVDOKIMOV Dispatcher 22.06.1990 10 45000
//ZHABOYEDOV Recruiter 12.08.1988 11 60000
//ZABALUEV Psychologist 13.05.1990 6 100000
//IVOILOV Supervisor 01.01.1991 3 34000
//TREASURER Merchandiser 04.03.1969 30 46000
//LAZARENKO Sales - consultant 05.04.1963 31 38000
//MAVRODI Businessman 11.08.1955 36 100000000
//EMBANKMENT Analyst 14.06.1956 43 100000
//OBATUROV Art - Director 29.11.1980 22 120000
//PAVIN Event - Manager 13.09.1982 20 150000
//ROGOZA TheLayoutDesigner 15.05.1995 3 60000
//SABUROV Copywriter 17.02.1988 10 120000
//TABACHNIKOV Promoter 18.12.1990 6 50000