//Дано дерево. Определить степень узла Х.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct tree // структура дерева
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree* node(int x) {// создание нового узла
	tree* n = new tree;
	n->inf = x;
	n->parent = NULL;
	n->right = NULL;
	n->left = NULL;
	return n;
}

void preorder(tree* tr) { // прямой обход (К-Л-П)
	if (tr) {
		cout << tr->inf; //корень
		preorder(tr->left); //левое
		preorder(tr->right); //правое
	}
}

void postorder(tree* tr) { // обратный обход (Л-П-К)
	if (tr) {
		postorder(tr->left); //левое
		postorder(tr->right); //правое
		cout << tr->inf; //корень
	}
}

void inorder(tree* tr) { // симметричный обход (Л-К-П)
	if (tr) {
		inorder(tr->left); //левое
		cout << tr->inf << " "; //корень
		inorder(tr->right); //правое
	}
}

void insert(tree*& tr, int x) {
	tree* n = node(x);
	if (!tr)//если дерево пустое - корень
		tr = n;
	else {
		tree* y = tr;
		while (y) {//ищем куда вставлять
			if (n->inf > y->inf)//правая ветка
				if (y->right)
					y = y->right;
				else {
					n->parent = y;//узел становится правым ребенком
					y->right = n;
					break;
				}
			else if (n->inf < y->inf)//левая ветка
				if (y->left)
					y = y->left;
				else {
					n->parent = y;//узел становится левым ребенком
					y->left = n;
					break;
				}
		}
	}
}

tree* find(tree* tr, int x) {//поиск
	if (!tr || x == tr->inf)//нашли или дошли до конца ветки
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);//ищем по левой ветке
	else
		return find(tr->right, x);//ищем по правой ветке
}

tree* Min(tree* tr) {//поиск min
	if (!tr->left) return tr;//нет левого ребенка
	else return Min(tr->left);//идем по левой ветке до конца
}

tree* Next(tree* tr, int x) {//поиск следующего
	tree* n = find(tr, x);
	if (n->right)//если есть правый ребенок
		return Min(n->right);//min по правой ветке
	tree* y = n->parent; //родитель
	while (y && n == y->right) {//пока не дошли до корня или узел - правый ребенок
		n = y;//идем вверх по дереву
		y = y->parent;
	}
	return y;//возвращаем родителя
}

void Delete(tree*& tr, tree* v) {//удаление узла
	tree* p = v->parent;
	if (!p) tr = NULL; //дерево содержит один узел
	else if (!v->left && !v->right) {//если нет детей
		if (p->left == v) //указатель у родителя меняем на NULL
			p->left = NULL;
		if (p->right == v)
			p->right = NULL;
		delete v;
	}
	else if (!v->left || !v->right) {//если только один ребенок
		if (!p) { //если удаляем корень, у которого 1 ребенок
			if (!v->left) { //если есть правый ребенок
				tr = v->right; //он становится корнем
				v->parent = NULL;
			}
			else { //аналогично для левого
				tr = v->left;
				v->parent = NULL;
			}
		}
		else {
			if (!v->left) {//если есть правый ребенок
				if (p->left == v) //если удаляемый узел явл. левым ребенком
					p->left = v->right; //ребенок удаляемого узла становится левым ребенком своего "деда"
				else
					p->right = v->right; ////ребенок удаляемого узла становится правым ребенком своего "деда"
				v->right->parent = p; //родителем ребенка становится его "дед"
			}
			else {//аналогично для левого ребенка
				if (p->left == v)
					p->left = v->left;
				else
					p->right = v->left;
				v->left->parent = p;
			}
			delete v;
		}
	}
	else {//есть оба ребенка
		tree* succ = Next(tr, v->inf);//следующий за удаляемым узлом
		v->inf = succ->inf; //присваиваем значение
		if (succ->parent->left == succ) {//если succ левый ребенок
			succ->parent->left = succ->right; //его правый ребенок становится левым ребенком своего "деда"
			if (succ->right) //если этот ребенок существует
				succ->right->parent = succ->parent; //его родителем становится "дед"
		}
		else {//аналогично если succ - правый ребенок
			succ->parent->right = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;
		}
		delete succ;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	tree* tr = NULL;
	int n;

	cout << "Введите n : ";
	cin >> n;

	cout << "Заполните дерево : ";
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		insert(tr, x);
	}

	cout << "Узел X : ";
	cin >> x;

	cout << "Симметричный обход : ";
	inorder(tr);
	cout << endl;

	cout << "Степень узла равна : ";
	tr = find(tr, x);
	if (tr->right != NULL && tr->left != NULL) {// Если 2 ребенка
		cout << "2" << endl;
	}
	else {
		if (tr->right != NULL || tr->left != NULL) {// Если 1 ребенок
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl; // Если детей нет
		}
	}

	return 0;
}
// 8 3 10 1 6 14 13 4 7