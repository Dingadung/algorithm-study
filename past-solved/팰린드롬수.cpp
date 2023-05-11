#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    string S;
    cin >> S;
    while(S!="0") {
        int f=0;
        int len = S.length();
        for(int i=0;i<len;i++) {
            if(S[i] != S[len -1 -i]){
                f=1;
                break;
            }
        }
        if(f==0){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
        cin >> S;
    }

    return 0;
}