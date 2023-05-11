#include <iostream>

using namespace std;

int main() {
	string input;
	cin >> input;
	int len = input.length();
	int alpha = ('Z' - 'A' + 1);
	for (int i = 0; i < len; i++) {
		input[i] = ((input[i] - 3 - 'A') + alpha) % alpha + 'A';
	}
	cout << input;
	return 0;
}