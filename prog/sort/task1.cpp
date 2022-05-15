////4. По стажу работы с помощью блочной сортировки.
////Работа обязательно с файлами. В файле содержатся данные о сотрудниках предприятия: фамилия, должность, дата
////рождения(день, месяц, год), стаж работы, зарплата(не менее 20 человек)
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//ifstream in("input1.txt");
//ofstream out("output.txt");
//
//struct chel {
//	string name;
//	string work;
//	string data;
//	int experience;
//	string salary;
//};
//
//vector<chel> inFile() {
//	vector<chel> x;
//	chel man;
//	string s;
//	while (in.peek() != EOF) {
//		in >> man.name;
//		in >> man.work;
//		in >> man.data;
//		in >> s;
//		man.experience = atoi(s.c_str());
//		in >> man.salary;
//		x.push_back(man);
//	}
//	return x;
//}
//
//
//vector<chel> INSERT(vector<chel> Finaly, vector<chel> k) {
//	Finaly.insert(Finaly.end(), k.begin(), k.end());
//	return Finaly;
//}
//
//vector<chel> sortirovka(vector<chel> k) {
//	for (int i = 1; i < k.size(); i++) {
//		int j = i;
//		while ((j > 0) && ((k[j].experience < k[j - 1].experience))) {
//			swap(k[j], k[j - 1]);
//			j--;
//		}
//	}
//	return k;
//}
//
//void print(chel man) {
//	out << man.name << " " << man.work << " " << man.data << " " << man.experience << " " << man.salary << endl;
//}
//
//vector<chel> sorti(vector <chel> man) {
//	int N = man.size();
//	int P = 5;
//	int maxx = 0, minn = 100000000000000;
//	for (int i = 0; i < man.size(); i++) {
//		if (man[i].experience < minn) {
//			minn = man[i].experience;
//		}
//		if (man[i].experience > maxx) {
//			maxx = man[i].experience;
//		}
//	}
//	int m = (maxx - minn) / P;
//	vector<chel> k0, k1, k2, k3, k4;
//	for (int i = 0; i < man.size(); i++) {
//		int k = (man[i].experience - minn) / m;
//		switch (k) {
//		case 0:
//			k0.push_back(man[i]);
//			break;
//		case 1:
//			k1.push_back(man[i]);
//			break;
//		case 2:
//			k2.push_back(man[i]);
//			break;
//		case 3:
//			k3.push_back(man[i]);
//			break;
//		case 4:
//			k4.push_back(man[i]);
//			break;
//		case 5:
//			k4.push_back(man[i]);
//			break;
//		}
//	}
//	for (int z = 0; z < P; z++) {
//		if ((z == 0) && (k0.size() != 0)) {
//			k0=sortirovka(k0);
//		}
//		if ((z == 1) && (k1.size() != 0)) {
//			k1=sortirovka(k1);
//		}
//		if ((z == 2) && (k2.size() != 0)) {
//			k2=sortirovka(k2);
//		}
//		if ((z == 3) && (k3.size() != 0)) {
//			k3=sortirovka(k3);
//		}
//		if ((z == 4) && (k4.size() != 0)) {
//			k4=sortirovka(k4);
//		}
//	}
//	vector<chel> Finaly;
//	Finaly = INSERT(Finaly, k0); Finaly = INSERT(Finaly, k1); Finaly = INSERT(Finaly, k2); Finaly = INSERT(Finaly, k3); Finaly = INSERT(Finaly, k4);
//	return Finaly;
//}
//
//
//int main() {
//	vector<chel> people;
//	people = inFile();
//	people = sorti(people);
//	for (int i = 0; i < people.size(); i++)
//		print(people[i]);
//	return 0;
//}
////PUPKIN Director 19.4.1960 41 200000
////ABALDUEV Auditor 20.5.1988 9 60000
////BABAKHIN TheCashier 30.07.1980 11 40000
////WADBAL Inspector 22.09.1977 13 70000
////GAVESHIN Broker 04.11.1994 5 150000
////GALICIAN Operator 23.01.1974 18 80000
////DANILOV Lawyer 09.03.1990 7 50000
////EVDOKIMOV Dispatcher 22.06.1990 10 45000
////ZHABOYEDOV Recruiter 12.08.1988 11 60000
////ZABALUEV Psychologist 13.05.1990 6 100000
////IVOILOV Supervisor 01.01.1991 3 34000
////TREASURER Merchandiser 04.03.1969 30 46000
////LAZARENKO Sales - consultant 05.04.1963 31 38000
////MAVRODI Businessman 11.08.1955 36 100000000
////EMBANKMENT Analyst 14.06.1956 43 100000
////OBATUROV Art - Director 29.11.1980 22 120000
////PAVIN Event - Manager 13.09.1982 20 150000
////ROGOZA TheLayoutDesigner 15.05.1995 3 60000
////SABUROV Copywriter 17.02.1988 10 120000
////TABACHNIKOV Promoter 18.12.1990 6 50000
