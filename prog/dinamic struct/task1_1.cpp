#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct stack {
	char inf;
	stack* next;
};

void push(stack*& h, char x) { 
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

char pop(stack*& h) { 
	char i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h) { 
	stack* h1 = NULL;
	while (h)
		push(h1, pop(h));
	h = h1;
}

stack* F(stack*& steck) {
	string a = "eyuioa";
	stack* GlSteck = NULL;
	stack* SglSteck = NULL;
	while (steck) {
		char x = pop(steck);
		if (a.find(x)) {
			push(GlSteck, x);
		}
		else {
			push(SglSteck, x);
		}
	}
	reverse(GlSteck);
	reverse(SglSteck);
	while (GlSteck || SglSteck) {
		char x;
		if (SglSteck) {
			x = pop(SglSteck);
		}
		else {
			x = pop(GlSteck);
		}
		push(steck, x);
	}
	return steck;
}


int main() {
	int n; char k;
	setlocale(LC_ALL, "Russian");
	cout << "������� n : " << endl;
	cin >> n;
	stack* steck = NULL;
	cout << "��������� ���� : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> k;
		push(steck, k);
	}
	stack* res = F(steck);
	while (res) {
		cout << pop(res) << " ";
	}
	return 0;
}