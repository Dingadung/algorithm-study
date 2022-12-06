#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string e;
    cin >>e;
    int S=0;
    for(int i=0;i<N;i++) {
        S += e[i] - '0';
    }
    cout << S;
    return 0;
}