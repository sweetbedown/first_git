//Удалить все четные элементы
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct tree // Объявление узла
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree * node(int x) {// Создание узла
	tree * n = new tree;
	n-> inf = x;
	n->parent = NULL;
	n->right = NULL;
	n-> left = NULL;
	return n;
}

void preorder(tree* tr) { // Прямой обход (c-l-r)
	if (tr) {
		cout << tr->inf; // Родитель
		preorder(tr->left); // Левый ребенок
		preorder(tr->right); // Правый ребёнок
	}
}

void postorder(tree* tr) { // Обратный обход (l-r-c)
	if (tr) {
		postorder(tr->left); // Левый ребенок
		postorder(tr->right); // Правый ребёнок
		cout << tr->inf; // Родитель
	}
}

void inorder(tree* tr) { // Симметричный обход (l-c-r)
	if (tr) {
		inorder(tr->left); // Левый ребенок
		cout << tr->inf << " "; // Родитель
		inorder(tr->right); // Правый ребёнок
	}
}

void insert(tree*& tr, int x) { // Вставка
	tree* n = node(x);
	if (!tr) // Если дерево пустое - корень
		tr = n;
	else {
		tree* y = tr;
		while (y) { // Ищем куда вставлять
			if (n->inf > y->inf) // Правая ветка
				if (y->right)
					y = y->right;
				else {
					n->parent = y; //Узел становится правым ребёнком
					y->right = n;
					break;
				}
			else if (n->inf < y->inf) // Левая ветка
				if (y->left)
					y = y->left;
				else {
					n->parent = y; // Узел становится левым ребёнком
					y->left = n;
					break;
				}
		}
	}
}

tree * find(tree * tr, int x) { // Поиск
	if (!tr || x == tr->inf) // Нашли или дошли до конца ветки
		return tr;
	if (x < tr->inf)
		return find(tr->left, x); // Ищем по левой ветке
	else
		return find(tr->right, x); // Ищем по правой ветке
}

tree * Min(tree * tr) { // Поиск min
	if (!tr->left) return tr; // Нет левого ребенка
	else return Min(tr->left); // Идем по левой ветке до конца
}

tree* Next(tree* tr, int x) { // Поиск следующего
	tree * n = find(tr, x);
	if (n->right) // Если есть правый ребенок
		return Min(n->right); // Мin по правой ветке
	tree * y = n->parent; // Родитель
	while (y && n == y->right) { // Пока не дошли до корня или узел - правый ребенок
		n = y; // Идем вверх по дереву
		y = y->parent;
	}
	return y; // Возвращаем родителя
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
					p->right = v->right; //ребенок удаляемого узла становится правым ребенком своего "деда"
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
		v->inf = succ->inf; ///присваиваем значение
		if (succ->parent->left == succ) {//если succ левый ребенок
			succ->parent->left = succ->right; ///его правый ребенок становится левым ребенком своего "деда"
			if (succ->right) //если этот ребенок существует
				succ->right->parent = succ->parent; //его родителем становится "дед"
		}
		else {//аналогично если succ - правsq ребенок
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
	cout << "Количество элементов n : "; 
	cin >> n;
 
	cout << "Заполните дерево : ";
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		insert(tr, x);
	}
 
	cout << "Прямой обход : "; 
	inorder(tr); 
	cout << endl;
 
	cout << "Полученный результат : ";
	tree* v = tr;
	Chet_del(tr, v);
	inorder(tr);
	cout << endl;
 
	return 0;
}
// 9 3 10 1 6 14 13 4 7