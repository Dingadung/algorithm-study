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


int main() {
    cin >> T;
    while (T--) {
        cin >> k; // 연산 횟수
        char op; // 연산을 나타내는 문자 D 또는 I
        int n;
        multiset<int> Q;
        while(k--) {
            cin >> op >> n;
            if (op == 'I') {
                // Q에 n 삽입
                Q.insert(n);
            }
            else if (op == 'D') {
                if (Q.empty())continue;
                if (n == 1) {
                    // Q에서 최대값 삭제
                    auto E = Q.end();
                    E--;
                    Q.erase(E);
                }
                else if (n == -1) {
                    // Q에서 최솟값 삭제
                    Q.erase(Q.begin());
                }
            }
        }
        if (Q.empty()) {
            cout << "EMPTY\n";
        }
        else {
            auto E = Q.end();
            E--;
            cout << *E << " " << *(Q.begin()) << "\n";
        }
    }
    
    return 0;
}
