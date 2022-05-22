// 1 Солбцы по возрастанию с помощью быстрой сортировки
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n = 4;

int** inFile()//Ввод из файла
{ 
    int** mas = new int* [n];
    for (int i = 0; i < n; i++)
        mas[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> mas[i][j];
    return mas;
}

void sort_nech(int* mas, int n) {
    int i = 1, step;
    while (pow(3, i) - 1 < n) {
        i++;
    }
    step = pow(3, i) - 1;
    while (step > 0) {
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while ((j >= 0) && (mas[j] > mas[j + step])) {//Сравниваем элементы
                swap(mas[j], mas[j + step]);//Меняем местами
                j -= step;
            }
        }
        i--;
        step = pow(3, i) - 1;// Меняем шаг
        if (i == 0) step++;
    }
}
void sort_ch(int* mas, int n) {
    int i = 1, step;
    while (pow(3, i) - 1 < n) {
        i++;
    }
    step = pow(3, i) - 1;
    while (step > 0) {
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while ((j >= 0) && (mas[j] < mas[j + step])) {//Сравниваем элементы
                swap(mas[j], mas[j + step]);//Меняем местами
                j -= step;
            }
        }
        i--;
        step = pow(3, i) - 1;// Меняем шаг
        if (i == 0) step++;
    }
}

void OutFile(int**& mas){ //Вывод в файл
    for (int i = 0; i < n; i++, out << endl)
        for (int j = 0; j < n; j++)
            out << mas[i][j] << " ";
}

int main(){
    int** mas = inFile();
    OutFile(mas);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) sort_ch(mas[i], n);
        else sort_nech(mas[i], n);
    }
    out << endl;
    OutFile(mas);
    return 0;
}