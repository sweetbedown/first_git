//������� ��� ������ ��������
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct tree // ���������� ����
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree * node(int x) {// �������� ����
	tree * n = new tree;
	n-> inf = x;
	n->parent = NULL;
	n->right = NULL;
	n-> left = NULL;
	return n;
}

void preorder(tree* tr) { // ������ ����� (c-l-r)
	if (tr) {
		cout << tr->inf; // ��������
		preorder(tr->left); // ����� �������
		preorder(tr->right); // ������ ������
	}
}

void postorder(tree* tr) { // �������� ����� (l-r-c)
	if (tr) {
		postorder(tr->left); // ����� �������
		postorder(tr->right); // ������ ������
		cout << tr->inf; // ��������
	}
}

void inorder(tree* tr) { // ������������ ����� (l-c-r)
	if (tr) {
		inorder(tr->left); // ����� �������
		cout << tr->inf << " "; // ��������
		inorder(tr->right); // ������ ������
	}
}

void insert(tree*& tr, int x) { // �������
	tree* n = node(x);
	if (!tr) // ���� ������ ������ - ������
		tr = n;
	else {
		tree* y = tr;
		while (y) { // ���� ���� ���������
			if (n->inf > y->inf) // ������ �����
				if (y->right)
					y = y->right;
				else {
					n->parent = y; //���� ���������� ������ �������
					y->right = n;
					break;
				}
			else if (n->inf < y->inf) // ����� �����
				if (y->left)
					y = y->left;
				else {
					n->parent = y; // ���� ���������� ����� �������
					y->left = n;
					break;
				}
		}
	}
}

tree * find(tree * tr, int x) { // �����
	if (!tr || x == tr->inf) // ����� ��� ����� �� ����� �����
		return tr;
	if (x < tr->inf)
		return find(tr->left, x); // ���� �� ����� �����
	else
		return find(tr->right, x); // ���� �� ������ �����
}

tree * Min(tree * tr) { // ����� min
	if (!tr->left) return tr; // ��� ������ �������
	else return Min(tr->left); // ���� �� ����� ����� �� �����
}

tree* Next(tree* tr, int x) { // ����� ����������
	tree * n = find(tr, x);
	if (n->right) // ���� ���� ������ �������
		return Min(n->right); // �in �� ������ �����
	tree * y = n->parent; // ��������
	while (y && n == y->right) { // ���� �� ����� �� ����� ��� ���� - ������ �������
		n = y; // ���� ����� �� ������
		y = y->parent;
	}
	return y; // ���������� ��������
}

void Delete(tree*& tr, tree* v) {//�������� ����
	tree* p = v->parent;
	if (!p) tr = NULL; //������ �������� ���� ����
	else if (!v->left && !v->right) {//���� ��� �����
		if (p->left == v) //��������� � �������� ������ �� NULL
			p->left = NULL;
		if (p->right == v)
			p->right = NULL;
		delete v;
	}
	else if (!v->left || !v->right) {//���� ������ ���� �������
		if (!p) { //���� ������� ������, � �������� 1 �������
			if (!v->left) { //���� ���� ������ �������
				tr = v->right; //�� ���������� ������
				v->parent = NULL;
			}
			else { //���������� ��� ������
				tr = v->left;
				v->parent = NULL;
			}
		}
		else {
			if (!v->left) {//���� ���� ������ �������
				if (p->left == v) //���� ��������� ���� ���. ����� ��������
					p->left = v->right; //������� ���������� ���� ���������� ����� �������� ������ "����"
				else
					p->right = v->right; //������� ���������� ���� ���������� ������ �������� ������ "����"
				v->right->parent = p; //��������� ������� ���������� ��� "���"
			}
			else {//���������� ��� ������ �������
				if (p->left == v)
					p->left = v->left;
				else
					p->right = v->left;
				v->left->parent = p;
			}
			delete v;
		}
	}
	else {//���� ��� �������
		tree* succ = Next(tr, v->inf);//��������� �� ��������� �����
		v->inf = succ->inf; ///����������� ��������
		if (succ->parent->left == succ) {//���� succ ����� �������
			succ->parent->left = succ->right; ///��� ������ ������� ���������� ����� �������� ������ "����"
			if (succ->right) //���� ���� ������� ����������
				succ->right->parent = succ->parent; //��� ��������� ���������� "���"
		}
		else {//���������� ���� succ - ����sq �������
			succ->parent->right = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;
		}
		delete succ;
	}
}
void Chet_del(tree* tr,tree* v) {
	if (v->left != NULL) Chet_del(tr, v->left);
	if (v->right != NULL) Chet_del(tr, v->right);
	if (v->inf % 2 == 0) Delete(tr, v);
}
int main() {
	setlocale(LC_ALL, "Russian");
	tree* tr = NULL;
	int n; 
	cout << "���������� ��������� n : "; 
	cin >> n;
 
	cout << "��������� ������ : ";
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		insert(tr, x);
	}
 
	cout << "������ ����� : "; 
	inorder(tr); 
	cout << endl;
 
	cout << "���������� ��������� : ";
	tree* v = tr;
	Chet_del(tr, v);
	inorder(tr);
	cout << endl;
 
	return 0;
}
// 9 3 10 1 6 14 13 4 7