#include <iostream>

using namespace std;

int main() {
	string S;
	cin >> S;
	for (char alpha = 'a'; alpha <= 'z'; alpha++) {
		int idx = -1;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == alpha) {
				idx = i;
				break;
			}
		}
		cout << idx << " ";
	}
	return 0;
}