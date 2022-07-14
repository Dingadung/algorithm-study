#include<iostream>
#include<string>
#include<vector>
using namespace std;
string pattern;
string text;
int N, M;
string S;

vector<int> Fail() {
	int m = pattern.length();
	vector<int> pi(m); // 모든 원소가 0으로 초기화된 상태에서 시작한다.
	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

int KMP() {
	int m = pattern.length();
	int n = pattern.length();
	int ans = 0;
	vector<int> pi = Fail();

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				ans++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}


int main() {
	cin >> N;
	cin >> M;
	cin>> S;

	for (int i = 0; i < 2 * N + 1; i++) {
		if (i % 2 == 0) {
			pattern.push_back('I');
		}
		else {
			pattern.push_back('O');
		}
	}

	int cnt = KMP();
	cout << cnt;
	return 0;
}