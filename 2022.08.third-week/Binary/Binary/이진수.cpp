#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int idx = 0;
		while (n > 0) {
			if (n % 2 != 0)cout << idx << " ";
			idx++;
			n /= 2;
		}
	}
	return 0;
}