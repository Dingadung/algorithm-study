#include <iostream>
#include <string>

using namespace std;


int main(){
    int M, H;
    cin >> H >> M;
    if(M - 45 < 0) {
        if(H == 0)
            H = 24;
        H--;
        M = M + 15;
    }
    else {
        M -= 45;
    }
    cout << H << " " << M;
    return 0;
}
