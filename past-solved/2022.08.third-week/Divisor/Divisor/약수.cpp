#include <iostream>

using namespace std;

int main() {
	int c;
	cin >> c; // ����� ����
	int tmp = c;
	int e; // ���
	int N=1, min = 1000000, max = 0;
	while (c--) {
		cin >> e;
		if (e > max)max = e;
		if (e < min)min = e;
	}
	N = max * min;
	cout << N;
	return 0;
}