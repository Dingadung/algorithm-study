#include <iostream>

using namespace std;

int main() {
	int c;
	cin >> c; // 약수의 개수
	int tmp = c;
	int e; // 약수
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