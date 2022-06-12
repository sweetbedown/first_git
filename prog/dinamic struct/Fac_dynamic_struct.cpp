//������� �������� ������ � �������� �������.
//����� ��������� ������ �������.
//������� ������ ����������� �������.
//�������� 0 ����� ���������� �������������.
#include<iostream>
using namespace std;

struct list // ���������� ������
{ 
	int inf;
	list * next;
	list * prev;
};

void push(list*& h, list*& t, int x) //�������� ������� � ������
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

void output(list* h, list* t) // ������� ������
{
	list* p = h;
	while (p) 
	{
		cout << p->inf << " ";
		p = p->next;
	}
}


void del_list(list * &h, list * &t) // ������� ������
{ 
	while (h) 
	{ 
		list * p = h; 
		h = h-> next; 
		h-> prev = NULL; 
		delete p; 
	}
}

void task1() //������� �������� ������ � �������� �������
{
	list* h = NULL;
	list* copyt = NULL;
	list* t = NULL;
	int n, l;

	cout << "������� n : " << endl;
	cin >> n;

	cout << "������� ����� : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	list* h1 = NULL;
	list* t1 = NULL;
	copyt = t;
	while (copyt) // ���� ������ �� ���� �������������� � �������������� ������ �����, ������� � ����� ���������� ������
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

void task2() //����� ��������� ������ �������
{
	list* h = NULL;
	list* t = NULL;
	list* copyt = NULL;
	int n, l;

	cout << "������� n : " << endl;
	cin >> n;

	cout << "������� ����� : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	copyt = t; //��� ��������� �� ����� ������
	while (copyt) // ��� � ����� ������, ��� ������ ������ �������� ���������� ��� � ������������ ����
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

void task3() //������� ������ ����������� �������
{
	list* h = NULL;
	list* copyh = NULL;
	list* t = NULL;
	int n, l, minn = 1000000000;

	cout << "������� n : " << endl;
	cin >> n;

	cout << "������� ����� : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	copyh = h; //��� ��������� �� ������
	list* k = NULL;
	while (copyh) // ���� � ������ ����������� ������� � ��������� �� ����
	{
		int i = copyh->inf;
		if (i < minn) 
		{
			minn = i;
			k = copyh; // ��������� �� ����������� �������
		}
		copyh = copyh->next;
	}

	if (k == h && k == t)
		h = t = NULL;
	else if (k == h) //���� ����������� ������� ������ - ������ ��������� �� ���������, ������ ��������
	{
		h = h->next;
		h->prev = NULL;
	}
	else if (k == t) //���� ����������� ������� ��������� - ����� ��������� �� ����������, ��������� ��������
	{
		t = t->prev;
		t->next = NULL;
	}
	else 
	{
		k->next->prev = k->prev; // "���������������" ���������� �������� ����������� "���������������" ��������
		k->prev->next = k->next; // "�������" ����������� �������� ����������� "�������" ��������
	}

	delete k;
	delete copyh;
	output(h, t);
	del_list(h, t);
}

void task4() //�������� 0 ����� ���������� �������������
{
	list* h = NULL;
	list* copyt = NULL;
	list* t = NULL;
	int n, l, maxx = 0;

	cout << "������� n : " << endl;
	cin >> n;

	cout << "������� ����� : " << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> l;
		push(h, t, l);
	}

	copyt = t;//��� ��������� �� �����
	list* k = NULL;
	while (copyt) // ��� � �����, ���� ������ � ����� ������������ ������� ����� ������� �����������
	{
		int i = copyt->inf;
		if (i > maxx) 
		{
			maxx = i;
			k = copyt; // ��������� �� ������������ �������
		}
		copyt = copyt->prev;
	}

	list* p = new list; // ��������� 0 ����� ������������� ��������
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

	cout << "�������� �������:" << endl;
	cout << "1) ������� �������� ������ � �������� �������" << endl;
	cout << "2) ����� ��������� ������ �������" << endl;
	cout << "3) ������� ������ ����������� �������" << endl;
	cout << "4) �������� 0 ����� ���������� �������������" << endl;
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
