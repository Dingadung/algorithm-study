#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int T; // 입력데이터의 수
int k; // 최대 1000000, Q에 적용할 연산의 개수

struct comp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

multiset<int> ms;
priority_queue<int, vector<int>, comp> Q;
int main() {
    cin >> T;
    while (T--) {
        cin >> k; // 연산 횟수
        char op; // 연산을 나타내는 문자 D 또는 I
        int n;
        for (int i = 0; i < k; i++) {
            cin >> op >> n;
            if (op == 'I') {
                // Q에 n 삽입
                //Q.emplace(n);
                ms.insert(n);
            }
            else if (op == 'D') {
                if (ms.empty())continue;
                if (n == 1) {
                    // Q에서 최대값 삭제
                    auto E = ms.end();
                    E--;
                    ms.erase(E);
                }
                else if (n == -1) {
                    // Q에서 최솟값 삭제
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY\n";
        }
        else {
            auto E = ms.end();
            E--;
            cout << *E << " " << *(ms.begin()) << "\n";
        }
    }
    
    return 0;
}
