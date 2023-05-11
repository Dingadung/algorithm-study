#include <iostream>
#include <string>

using namespace std;


int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        int R;
        string S;
        cin >> R >> S;
        int lenS = S.length();
        string ans;
        for(int i=0;i<lenS;i++) {
            char e = S[i];
            for(int j=0;j<R;j++) {
                ans += e;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
