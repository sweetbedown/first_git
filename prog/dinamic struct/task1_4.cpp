//����� ���� �����, ������� X, �������� ����� �������
#include <iostream>

using namespace std;

struct queue{
    int inf;
    queue *next;
};

void push (queue *&h,queue *&t, int x){
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

int pop (queue *&h,queue *&t){
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h){ 
        t = NULL;
    }
    delete r;
    return i;
}

void result(queue*& h, queue*& t){
    int max = 0;
    queue* h_res = NULL, *t_res = NULL;
    queue* h1 = NULL, * t1 = NULL;
    queue* h2 = NULL, * t2 = NULL;
    queue* h3 = NULL, * t3 = NULL;
    while (h){
        int x = pop(h, t);
        push(h3, t3, x);
        if (x >= max) {
            max = x;
        }
    }
    int c = 0;
    while (h3){
        int x = pop(h3, t3);
        if (x == max) c++;
        if (c == 0) {
            push(h1, t1, x);
        }
        else {
            push(h2, t2, x);
        }
    }
    while (h2) {
        int x = pop(h2, t2);
        push(h_res, t_res, x);
    }
    while (h1) {
        int x = pop(h1, t1);
        push(h_res, t_res, x);
    }
    h=h_res; //������ �������� ������� �� �����
    t=t_res;
}

int main(){
    setlocale(LC_ALL, "Russian");
    queue *h = NULL, *t = NULL; //�������������� �������
    int n;
    int x;
    cout << "���������� ��������� n = "; cin >> n;
    cout << "��������� ������� : ";
    for (int i=0; i<n; i++){ // ��������� ����� � �������
        cin >> x;
        push(h, t, x); 
    }
    result(h, t);
    cout << "����� : " << endl;
    while (h || t){   // ������� �������
        cout << pop(h, t) << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
// 8
// 1 2 9 3 5 7 5 3
// 1 2 9 3 5 9 5 3