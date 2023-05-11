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


int main() {
    cin >> T;
    while (T--) {
        cin >> k; // ���� Ƚ��
        char op; // ������ ��Ÿ���� ���� D �Ǵ� I
        int n;
        multiset<int> Q;
        while(k--) {
            cin >> op >> n;
            if (op == 'I') {
                // Q�� n ����
                Q.insert(n);
            }
            else if (op == 'D') {
                if (Q.empty())continue;
                if (n == 1) {
                    // Q���� �ִ밪 ����
                    auto E = Q.end();
                    E--;
                    Q.erase(E);
                }
                else if (n == -1) {
                    // Q���� �ּڰ� ����
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
