#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream in("input1.txt");
ofstream out("output1.txt");

struct date {
	int dd, mm, yy;
};

struct people {
	string name;
	string post;
	date d_b;
	int qual;
	int salary;
};

vector<people> inFile() {
	vector<people> x;
	people man;
	string s;
	while (in.peek() != EOF) {
		in >> man.name;
		in >> man.post;
		in >> s;
		man.d_b = stad(s);
		in >> s;
		man.qual = atoi(s.c_str());
		in >> man.salary;
		x.push_back(man);
	}
	return x;
}

date stad(string str) {//из строки в дату
	date x;
	string temp = str.substr(0, 2);//день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//мес€ц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//год
	x.yy = atoi(temp.c_str());
	return x;
}

void print(people x) {//вывод в файл
	out << x.name << " " << x.post << " " << x.d_b.dd << " " << x.d_b.mm << " " << x.d_b.yy << " " << x.qual << " " << x.salary << endl;
}

void bubble(vector<people>& vec) {
	for (int i = 0; i < 9; i++) {

		for (int j = 9; j > i; j--) {

			if (vec[j - 1].post > vec[j].post) {

				swap(vec[j - 1], vec[j]);

			}
			else {
				if ((vec[j - 1].post == vec[j].post)&&(vec[j - 1].qual > vec[j].qual)) {

					swap(vec[j - 1], vec[j]);

				}
				else {
					if ((vec[j - 1].qual == vec[j].qual) && (vec[j - 1].salary > vec[j].salary)) {

						swap(vec[j - 1], vec[j]);

					}
				}
			}

		}

	}
}

int main() {
	vector <people> x;
	x = inFile();
	bubble(x);
	for (int i = 0; i < x.size(); i++) print(x[i]);
	return 0;
}