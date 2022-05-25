//����� ���� �����, ������� X, �������� ����� �������
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
    h=h_res; //������ �������� ������� �� �����
    t=t_res;
}

int main(){
    setlocale(LC_ALL, "Russian");
    queue *h = NULL, *t = NULL; //�������������� �������
    int n;
    char x;
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
// a w 2 ! ; s . d