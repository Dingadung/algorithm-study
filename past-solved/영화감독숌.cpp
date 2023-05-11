#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>

using namespace std;

bool check(int N);

int main() {
    int N;
    cin >> N;

    int ori = 665;
    int cnt = 0;

    while(cnt < N) {
        if(check(ori)) {
            cnt++;
        }
        if(cnt == N) break;
        ori++;
    }

    cout << ori;

    return 0;
}

bool check(int N) {
    while(N>0) {
        if(N%10 == 6 && N/10%10 == 6 && N/10/10%10 == 6) {
            return true;
        }
        N/=10;
    }
    return false;
}