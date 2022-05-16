#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

ifstream in("main3.txt");
ofstream out("main1.txt");

vector<vector<int>> inFile() {
	vector<vector<int>> x;
	int g = 5;
	x.resize(g);
	for (int j = 0; j < g; j++) {
		x.resize(g);
	}
	int a;
	while (in.peek() != EOF) {
		for (int i = 0; i < g; i++) {
			for (int j = 0; j < g; j++) {
				in >> a;
				x[i][j] = a;
			}
		}
	}
	return x;
}

vector<vector<int>> sort(vector<vector<int>>&a,int nach, int n) {
	int left, right, centr;
	for (int i = 0; i < n; i++) {
		left = nach;
		right = n-1;
		centr = (n/2)+1;
		while (left <= right) {
			while (a[i][left] < a[i][centr]) {
				left++;
			}
			while (a[i][right] > a[i][centr]) {
				right--;
			}
			if (left <= right) {
				swap(a[i][left], a[i][right]);
				right--; left++;
			}
		}
		vector <int>b;
		for (int d = 0; d < centr; d++) {
			b.push_back(a[i][d]);
		}
		vector <int>q;
		for (int d = n-1; d > centr; d--) {
			q.push_back(a[i][d]);
		}
		if (b.size() > 1) sort(a,nach,right);
		if (q.size() > 1) sort(a,left,n);
	}
	return a;
}

int main() {
	vector<vector<int>> x;
	int N = 5;
	x = inFile();
	x = sort(x, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << x[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}