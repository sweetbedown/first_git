#include<iostream>

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

int pop(stack*& h) {
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack*& h) {
    stack* h1 = NULL;
    while (h) {
        push(h1, pop(h));
    }
    h = h1;
}

int func(int x) {
    int sum = 0;
    while (x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

stack* result(stack*& h) {
    stack * res = NULL; //инициализация
    stack * h1 = NULL;
    int max = 0;
    while (h) {
        int x = pop(h); //удаляем первый элемент
        if (func(x) > max) {
            max = func(x);
        }
        push(h1, x);
    }
    while (h1) {
        int x = pop(h1);
        if (func(x) != max) {
            push(res, x);
        }
    }
    return res;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Количество элементов n = "; cin >> n;
    stack* h = NULL; 
    int x;
    cout << "Заполните стек: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, x);
    }
    reverse(h);
    stack* res = result(h); 
    cout << "Ответ : " << endl;
    while (res) {
        cout << pop(res) << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}