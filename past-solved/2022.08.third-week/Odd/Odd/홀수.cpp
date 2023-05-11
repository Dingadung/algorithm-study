#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	int min = 100;
	for (int i = 0; i < 7; i++) {
		int e;
		cin >> e;
		if (e % 2 != 0) {
			sum += e;
			if (e < min) min = e;
		}
	}
	if (sum == 0) {
		cout << -1;
		return 0;
	}
	cout << sum << endl << min;
	return 0;
}