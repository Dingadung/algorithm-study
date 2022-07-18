#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>
using namespace std;

void printSpace();
void printStar();

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = N-1 ; j > i; j--) {
			printSpace();
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printStar();
		}
		cout << endl;
	}
	return 0;
}

void printSpace(int len, int cur) {
	cout << " ";
}
void printStar() {
	cout << "*";
}