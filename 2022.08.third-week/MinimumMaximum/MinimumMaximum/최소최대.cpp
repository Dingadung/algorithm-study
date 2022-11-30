#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int min = 1000000, max = -1000000;
	for (int i = 0; i < N; i++) {
		int e;
		cin >> e;
		if (e > max)max = e;
		if (e < min)min = e;
	}
	cout << min << " " << max;
	return 0;
}