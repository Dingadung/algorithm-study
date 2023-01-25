#include <iostream>
#include <algorithm>

using namespace std;

int divs(int x);

int main(){
    int N;
    scanf("%d", &N);

    int ans = 0;
    for(int i=0;i<N;i++) {
        if(divs(i) + i ==N) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}

int divs(int x) {
    int S=0;
    while(x>0) {
        S+=x%10;
        x/=10;
    }
    return S;
}