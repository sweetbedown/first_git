//после всех чисел, кратных X, вставить новый элемент
#include <iostream>

using namespace std;

struct queue{
    int inf;
    queue *next;
};

void push (queue *&h,queue *&t, char x){
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t){ 
        h = t = r; 
    }else{
        t->next = r;
        t = r;
    }
}

char pop (queue *&h,queue *&t){
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h){ 
        t = NULL;
    }
    delete r;
    return i;
}

bool func(char x) {
    if (((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z')) || ((x >= '0') && (x <= '9'))) return true;
    else return false;
}

void result(queue*& h, queue*& t){
    queue* h_res = NULL, *t_res = NULL;
    while (h){
        char x = pop(h, t);
        if (func(x)) {
            push(h_res, t_res, x);
        }
    }
    h=h_res; //замена исходной очереди на новую
    t=t_res;
}

int main(){
    setlocale(LC_ALL, "Russian");
    queue *h = NULL, *t = NULL; //инициализируем очередь
    int n;
    char x;
    cout << " оличество элементов n = "; cin >> n;
    cout << "«аполните очередь : ";
    for (int i=0; i<n; i++){ // добавл€ем числа в очередь
        cin >> x;
        push(h, t, x); 
    }
    result(h, t);
    cout << "ќтвет : " << endl;
    while (h || t){   // выводим очередь
        cout << pop(h, t) << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
// 8
// a w 2 ! ; s . d