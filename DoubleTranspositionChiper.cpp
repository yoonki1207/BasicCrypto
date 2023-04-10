#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define TEST
#define MAX_CHARSET 255

using namespace std;

char map[MAX_CHARSET];
int rows = 7;
int cols = 10;
vector<int> rPer;
vector<int> cPer;

void print(char* s);

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

char* changePermutaionRow(const vector<int> per, const char* map) { // size of per is same for number of rows
	char* ret = new char[MAX_CHARSET];
	for (int i = 0; i < rows; i++) {
		int y = per[i];
		for (int j = 0; j < cols; j++) {
			ret[i * cols + j % cols] = map[y * cols + j % cols];
		}
	}
	return ret;
}

char* changePermutaionCol(const vector<int> per, const char* map) {
	char* ret = new char[MAX_CHARSET];
	for (int i = 0; i < cols; i++) {
		int x = per[i];
		for (int j = 0; j < rows; j++) {
			ret[j * cols + i % cols] = map[j * cols + x % cols];
		}
	}
	return ret;
}

void print(char* s) {
	cout << "   ";
	for (int j = 0; j < cols; j++)
		cout << j << ' ';
	cout << '\n';
	for (int i = 0; i < rows; i++) {
		cout << i << ": ";
		for (int j = 0; j < cols; j++) {
			cout << s[i * cols + j % cols] << ' ';
		}
		cout << " : " << rPer[i] << endl;
	}
	cout << "   ";
	for (int j = 0; j < cols; j++)
		cout << cPer[j] << ' ';
	cout << '\n';
}

void nextPer(vector<int>& per, const int max_len, int index = 0) {

}

int main() {

#ifdef TEST2
	rows = 3; cols = 2;
	for (int i = 0; i < 6; i++) map[i] = 'A' + i;
	vector<int> rPer;
	vector<int> cPer;
	for (int i = 0; i < s.size(); i++) map[i] = s[i];
	for (int i = 0; i < rows; i++) cPer.push_back(i);
	for (int i = 0; i < cols; i++) rPer.push_back(i);

	while (next_permutation(cPer.begin(), cPer.end())) {
		while (next_permutation(rPer.begin(), rPer.end())) {
			char* tmp = changePermutaionCol(cPer, map);
			char* ret = changePermutaionRow(rPer, tmp);
			print(ret);
			cout << endl;
		}
	}

#else
	int trial = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) map[i] = s[i];
	for (int i = 0; i < rows; i++) rPer.push_back(i);
	for (int i = 0; i < cols; i++) cPer.push_back(i);

	print(map);
	char* tmp = nullptr;
	char* ret = nullptr;
	while (true) {
		if (tmp) delete[] tmp;
		if (ret) delete[] ret;
		int cmd, a, b;
		cout << "ROWS: 1, COLS: 2 > ";
		cin >> cmd >> a >> b;

		if (cmd == 1) {
			int tmp = rPer[a];
			rPer[a] = rPer[b];
			rPer[b] = tmp;
		}
		else {
			int tmp = cPer[a];
			cPer[a] = cPer[b];
			cPer[b] = tmp;
		}

		tmp = changePermutaionRow(rPer, map);
		ret = changePermutaionCol(cPer, tmp);
		print(ret);
	}
#endif

	return 0;
}
