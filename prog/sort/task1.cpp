#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream in("main.txt");
ofstream out("main1.txt");

struct date {// Дата
	int dd, mm, yy;
};

struct people {// Данные о человеке
	string Surname; // Фамилия
	string Post; // Должность 
	date DateOfBirth; // Дата рождения
	int Experience; // Стаж работы
	int Salary; // Зарплата
};

date stand(string str) {// Преобразование из строки в дату

	date x; string temp;
	
	temp = str.substr(0, 2);
	x.dd = atoi(temp.c_str());

	temp = str.substr(3, 2);
	x.mm = atoi(temp.c_str());

	temp = str.substr(6, 4);
	x.yy = atoi(temp.c_str());

	return x;
};

vector<people> inFile() { // Ввод из файла
	vector<people> x;
	people temp;

	while (in.peek() != EOF) {

		in >> temp.Surname; // Фамилия

		in >> temp.Post; // Должность

		string tmp; // Дата рождения
		in >> tmp;
		temp.DateOfBirth = stand(tmp);
		
		in >> temp.Experience;// Стаж работы

		in >> temp.Salary; //зарплата
		
		x.push_back(temp);
	}
	
	return x;
}

void print(people x) {//вывод в файл
	out << x.Surname << " " << x.Post << " " << x.DateOfBirth.dd << " " << x.DateOfBirth.mm << " " << x.DateOfBirth.yy << " " << x.Experience << " " << x.Salary << endl;
}

vector<people> sortt(vector<people> k) {
	for (int i = 1; i < k.size(); i++) {
		int j = i;
		while ((j > 0) && (k[j].Experience < k[j - 1].Experience)) {
			swap(k[j], k[j - 1]);
			j--;
		}
	}
	return k;
}

vector<people> sort(vector<people> &x) {
	int P = 4, N = x.size();
	vector<people> p1, p2, p3, p4;
	int maxx = 0;
	int minn = 9999;
	for (int i = 0; i < N; i++) {
		if (x[i].Experience > maxx) maxx = x[i].Experience;
		if (x[i].Experience < minn) minn = x[i].Experience;
	}
	int m = (maxx - minn) / P;
	for (int i = 0; i < N; i++) {
		int k = (x[i].Experience - minn) / m;
		switch (k) {
		case 0:
			p1.push_back(x[i]);
			break;
		case 1:
			p2.push_back(x[i]);
			break;
		case 2:
			p3.push_back(x[i]);
			break;
		case 3:
			p4.push_back(x[i]);
			break;
		}
	}
	for (int i = 0; i < P; i++) {
		switch (i) {
		case 0:
			p1 = sortt(p1);
		case 1:
			p2 = sortt(p2);
		case 2:
			p3 = sortt(p3);
		case 3:
			p4 = sortt(p4);
		}
	}
	vector<people> end;
	end.insert(end.end(), p1.begin(), p1.end());
	end.insert(end.end(), p2.begin(), p2.end());
	end.insert(end.end(), p3.begin(), p3.end());
	end.insert(end.end(), p4.begin(), p4.end());
	return x;
}

int main() {
	vector <people> x;
	x = inFile();
	x = sort(x);
	for (int i = 0; i < x.size(); i++) print(x[i]);
	return 0;
}