//Вывести элементы списка в обратном порядке.
//Найти последний четный элемент.
//Удалить первый минимальный элемент.
//Вставить 0 после последнего максимального.
#include<iostream>
using namespace std;

struct list // Объявление списка
{ 
	int inf;
	list * next;
	list * prev;
};

void push(list*& h, list*& t, int x) //Добавить элемент в начало
{ 
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) 
	{
		r->prev = NULL;
		h = r;
	}
	else 
	{
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void output(list* h, list* t) // Вывести список
{
	list* p = h;
	while (p) 
	{
		cout << p->inf << " ";
		p = p->next;
	}
}


void del_list(list * &h, list * &t) // Удалить список
{ 
	while (h) 
	{ 
		list * p = h; 
		h = h-> next; 
		h-> prev = NULL; 
		delete p; 
	}
}

void task1() //Вывести элементы списка в обратном порядке
{
	list* h = NULL;
	list* copyt = NULL;
	list* t = NULL;
	int n, l;

	cout << "Введите n : " << endl;
	cin >> n;

	cout << "Введите числа : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	list* h1 = NULL;
	list* t1 = NULL;
	copyt = t;
	while (copyt) // Пока список не пуст перезаписываем в дополнительный список числа, начиная с конца начального списка
	{
		int i = copyt->inf;
		push(h1, t1, i);
		copyt = copyt->prev;
	}

	delete copyt;
	output(h1, t1);
	del_list(h, t);
	del_list(h1, t1);
}

void task2() //Найти последний четный элемент
{
	list* h = NULL;
	list* t = NULL;
	list* copyt = NULL;
	int n, l;

	cout << "Введите n : " << endl;
	cin >> n;

	cout << "Введите числа : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	copyt = t; //Доп указатель на конец списка
	while (copyt) // Идём с конца списка, при первом четном элементе возвращаем его и останавливем цикл
	{
		int i = copyt->inf;
		if (i % 2 == 0) 
		{
			cout << i << endl;
			break;
		}
		copyt = copyt->prev;
	}

	delete copyt;
	del_list(h, t);
	output(h, t);
}

void task3() //Удалить первый минимальный элемент
{
	list* h = NULL;
	list* copyh = NULL;
	list* t = NULL;
	int n, l, minn = 1000000000;

	cout << "Введите n : " << endl;
	cin >> n;

	cout << "Введите числа : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	copyh = h; //Доп указатель на начало
	list* k = NULL;
	while (copyh) // Ищем в списке минимальный элемент и указатель на него
	{
		int i = copyh->inf;
		if (i < minn) 
		{
			minn = i;
			k = copyh; // Указатель на минимальный элемент
		}
		copyh = copyh->next;
	}

	if (k == h && k == t)
		h = t = NULL;
	else if (k == h) //Если минимальный элемент первый - голову переносим на следующий, первый обнуляем
	{
		h = h->next;
		h->prev = NULL;
	}
	else if (k == t) //Если минимальный элемент последний - хвост переносим на предыдущий, последний обнуляем
	{
		t = t->prev;
		t->next = NULL;
	}
	else 
	{
		k->next->prev = k->prev; // "Предшественнику" следующего элемента присваеваем "предшественника" текущего
		k->prev->next = k->next; // "Потомку" пердыдущего элемента присваеваем "потомка" текущего
	}

	delete k;
	delete copyh;
	output(h, t);
	del_list(h, t);
}

void task4() //Вставить 0 после последнего максимального
{
	list* h = NULL;
	list* copyt = NULL;
	list* t = NULL;
	int n, l, maxx = 0;

	cout << "Введите n : " << endl;
	cin >> n;

	cout << "Введите числа : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	copyt = t;//Доп указатель на конец
	list* k = NULL;
	while (copyt) // Идём с конца, ищем первый с конца максимальный элемент через строгое неравенство
	{
		int i = copyt->inf;
		if (i > maxx) 
		{
			maxx = i;
			k = copyt; // указатель на максимальный элемент
		}
		copyt = copyt->prev;
	}

	list* p = new list; // Вставляем 0 после максимального элемента
	p-> inf = 0;
	if (k == t) 
	{ 
		p-> next = NULL;
		p-> prev = k;
		k-> next = p;
		t = p;
	}
	else 
	{ 
		k-> next-> prev = p; 
		p-> next = k-> next; 
		p-> prev = k; 
		k->next = p;
	}

	output(h, t);
	del_list(h, t);
}

int main() {
	int k;
	setlocale(LC_ALL, "Russian");

	cout << "Выберите задание:" << endl;
	cout << "1) Вывести элементы списка в обратном порядке" << endl;
	cout << "2) Найти последний четный элемент" << endl;
	cout << "3) Удалить первый минимальный элемент" << endl;
	cout << "4) Вставить 0 после последнего максимального" << endl;
	cin >> k;

	switch (k) 
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	}
	return 0;
}
