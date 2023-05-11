#include <iostream>

using namespace std;

int main() {
	int N; // 시험 본 과목의 개수
	cin >> N;
	double sum = 0;
	int max = 0;
	double score[1000];
	for (int i = 0; i < N; i++) {
		cin >> score[i];
		if (score[i] > max)max = score[i];
	}
	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}
	cout << sum / N;
	return 0;
}