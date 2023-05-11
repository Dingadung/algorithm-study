#include <iostream>
#include <string>

using namespace std;

int main(){
    int input[10];
    for(int i=0;i<10;i++){
        cin >> input[i];
    }

    int div[10];
    for(int i=0;i<10;i++){
        div[i] = input[i] % 42;
    }

    // for(int i=0;i<10;i++){
    //     cout << div[i] << endl;
    // }

    

    int cnt[10] = {0};
    cnt[0] = div[0];
    int c=1;
    for(int i=0;i<10;i++) {
        int f=0;
        for(int j=0;j<c;j++) {
            if(cnt[j] == div[i]) {
                f=1;
                break;
            }
        }
        if(f==0) {
            cnt[c++] = div[i];
        }
    }

    cout << c << endl;
    
    
    return 0;
}
