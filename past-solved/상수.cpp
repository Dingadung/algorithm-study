#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int c, d;
    c = change(a);
    d = change(b);
    int ans = c>d? c:d;
    cout << ans;
    return 0;
}

int change(int m) {
    int n = 0;
    while(m>0) {
        n = n*10 + m%10;
        m/=10;
    }
    return n;
}
