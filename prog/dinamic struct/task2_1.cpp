//Создать двусвязный список, содержащий целые числа. Удалить все четные числа.
#include <iostream>

using namespace std;

struct list { //двусвязный список
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) { //добавляет элемент в конец дв. списка
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

void insert_after(list*& h, list*& t, list* r, int y) {
    list * p = new list; 
    p-> inf = y;
    if (r == t) { 
    	p-> next = NULL; 
    	p-> prev = r; 
    	r-> next = p;
    	t = p; 
    }
    else { 
    	r-> next-> prev = p; 
    	p-> next = r-> next; 
    	p-> prev = r; 
    	r-> next = p;
    }
}

void print(list* h, list* t) { //выводит двусв. список
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
}

void func(list*& copyh, list*& h, list*& t) {
    int maxx = 0;
    int minn = 999;
    while (copyh) {
		int i = copyh->inf;
		if (i >= maxx) {
			maxx = i;
		}
		if (i <= minn) {
			minn = i;
		}
		copyh = copyh->next;
	}
    copyh = h;
    while (copyh) {
		int i = copyh->inf;
		if (i == maxx) {
			insert_after(h, t, copyh, minn);
			copyh = copyh->next;
		}
		copyh = copyh->next;
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

int main(){
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Количество элементов n = ";
    cin >> n;
    list* h = NULL;
    list* copyh = NULL;
    list* t = NULL;
    int x;
    cout << "Заполните список : ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, t, x);
    }
    copyh = h;
    func(copyh, h, t);
    print(h, t);
    del_list(h, t);
    return 0;
}