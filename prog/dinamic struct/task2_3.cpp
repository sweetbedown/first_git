#include<iostream>
using namespace std;
struct list {
	int inf;
	list* next;
	list* prev;
};
void push(list*& h, list*& t, int x) {
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void output(list* h, list* t) {
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}

void insert_after(list*& h, list*& t, list* r, int y) {
	list* p = new list;
	p->inf = y;
	if (r == t) {
		p->next = NULL;
		p->prev = r;
		r->next = p;
		t = p;
	}
	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
}

void del_list(list*& h, list*& t) {
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}

void del_node(list * &h, list * &t, list * r) { 
	if (r == h && r == t) 
		h = t = NULL;
	else if (r == h) { 
		h = h-> next; 
		h-> prev = NULL;
	}
	else if (r == t) { 
		t = t-> prev; 
		t-> next = NULL;
	}
	else {
		r-> next-> prev = r-> prev; 
		r-> prev-> next = r-> next; 
	}
	delete r; 
}

//for (int i = 1; i < n - 1; i++) {
//	int j = i;
//	while ((j > 0) && (a[j] < a[j - 1])) {
//		swap(a[j], a[j - 1]);
//		j--;
//	}
//}
//void func(list*& copyh, list*& copyt, list* copyt1, list*& t) {
//	copyt = t;
//	copyh = copyh->next;
//	while (copyh != copyt) { 
//		copyt1 = copyh;
//		int a = copyt1->inf;
//		int b = copyt1->prev->inf;
//		while ((copyt1)&&(b > a)) {
//			copyt1->inf = b;
//			copyt1->prev->inf = a;
//			copyt1 = copyt1->prev;
//		}
//		copyh = copyh->next;
//	}
//}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, l, x;
	list* h = NULL;
	list* t = NULL;
	list* copyh = NULL;
	list* copyt = NULL;
	list* copyt1 = NULL;
	cout << "Количество элементов n : ";
	cin >> n;
	cout << "ЗАполните список : ";
	for (int i = 0; i < n; i++) {
		cin >> l;
		push(h, t, l);
	}
	copyh = h->next;
	copyt = t;
	while (copyh != t) {
		copyt1 = copyh;
		int b = copyt1->prev->inf;
		int a = copyt1->inf;
		while ((copyt1 != h)&&(a<b)) {
			b = copyt1->prev->inf;
			a = copyt1->inf;
			copyt1->inf = b;
			copyt1->prev->inf = a;
			copyt1 = copyt1->prev;

		}
		copyh = copyh->next;
	}
	/*func(copyh, copyt, copyt1, t);*/
	output(h, t);
	del_list(h, t);
	delete copyh;
	delete copyt;
	delete copyt1;
	return 0;
}
//5 2 9 1 3 7 9 2 9 -- 1 2 2 3 5 7 9 9 9