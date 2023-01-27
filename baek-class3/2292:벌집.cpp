#include <iostream>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int cnt=1;

    int x = 2;
    for(int i=1;x<=N;i++) {
        x = x + 6*(i);
        cnt = i + 1;
    }

    cout << cnt;
    return 0;
}