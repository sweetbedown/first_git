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

void sort(int* mas, int n) {
    int begin = -1, end = n - 1;
    while (begin < end) {
        int count = 0;
        begin++;
        for (int j = begin; j < end; j++) {
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
                count++;
            }
        }
        if (count == 0) break;
        count = 0;
        end--;
        for (int j = end; j > begin-1; j--) {
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
                count++;
            }
        }
    }
}

int** func(int**& mas) {
    int** s = new int* [n];
    for (int i = 0; i < n; i++) s[i] = new int[n];
    for (int i = 0; i < n/2; i++) {
        int x = i + 1;
        int end = x;
        int y = 0;
        while (y <= end) {
            s[i][y] = mas[x][y];
            x--; y++;
        }
    }
    for (int i = n / 2; i < n; i++) {
        int x = n - 1;
        int end = x;
        int y = i - 1;
        int k = i - 1;
        while (y <= end) {
            s[i][y-k] = mas[x][y];
            x--; y++;
        }
    }
    return s;
}

int** func2(int**& mas, int**& a) {
    mas[1][0] = a[0][2];
    mas[0][1] = a[0][3];
    mas[2][0] = a[1][1];
    mas[1][1] = a[1][2];
    mas[0][2] = a[1][3];
    mas[3][1] = a[2][1];
    mas[2][2] = a[2][2];
    mas[1][3] = a[2][3];
    mas[3][2] = a[3][2];
    mas[2][3] = a[3][3];
    return mas;
}

void OutFile(int**& mas){ //Вывод в файл
    for (int i = 0; i < n; i++, out << endl)
        for (int j = 0; j < n; j++)
            out << mas[i][j] << " ";
}

int main(){
    int** mas = inFile();
    OutFile(mas);
    int** a = func(mas);
    for (int i = 0; i < n; i++) {
        sort(a[i], n);
    }
    mas = func2(mas, a);
    out << endl;
    OutFile(mas);
    return 0;
}