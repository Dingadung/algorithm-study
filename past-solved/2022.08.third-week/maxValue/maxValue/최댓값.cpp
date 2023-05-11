#include <iostream>

using namespace std;

int main() {
	int e;
	int max = 0, seq=0;
	for (int i = 1; i <= 9; i++) {
		cin >> e;
		if (max < e) {
			max = e;
			seq = i;
		}
	}
	cout << max << endl << seq;
	return 0;
}