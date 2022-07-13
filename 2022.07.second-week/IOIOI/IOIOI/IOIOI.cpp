#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
const int N_MAX = 1000001;
const int M_MAX = 1000001;

long long N, M;
string S;
string IO;

int cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; // O�� I�� ����
    cin >> M; // ���ڿ� S�� ����
    cin >> S;
    
    for (int i = 0; i < M; i++) {
        int t = 0;
        if (S[i] == 'O')continue;
        while (S[i + 1] == 'O' && S[i + 2] == 'I') {
            t++;
            if (t == N) {
                cnt++;
                t--; // �ߺ� ����
            }
            i += 2;
        }
    }
    cout << cnt;
    return 0;
}
