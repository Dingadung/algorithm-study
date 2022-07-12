#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int T; // �Էµ������� ��
int k; // �ִ� 1000000, Q�� ������ ������ ����

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
        cin >> k; // ���� Ƚ��
        char op; // ������ ��Ÿ���� ���� D �Ǵ� I
        int n;
        for (int i = 0; i < k; i++) {
            cin >> op >> n;
            if (op == 'I') {
                // Q�� n ����
                //Q.emplace(n);
                ms.insert(n);
            }
            else if (op == 'D') {
                if (ms.empty())continue;
                if (n == 1) {
                    // Q���� �ִ밪 ����
                    auto E = ms.end();
                    E--;
                    ms.erase(E);
                }
                else if (n == -1) {
                    // Q���� �ּڰ� ����
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
