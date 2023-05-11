#include <iostream>
#include <string>

using namespace std;

int main(){
    int a[8];
    int f=0;
    for(int i=0;i<8;i++) {
        cin >> a[i];
    }
    
    for(int i=1;i<=8;i++) {
        if(a[i-1] != i){
            f=1; 
            break;
        }
        f=0;
    }
    if(f==0){
        cout << "ascending";
        return 0;
    }
    f=0;

    for(int i=0;i<8;i++) {
        if(a[i] != 8-i) { 
            f=1;
            break;
        } 
        f=0;
    }
    if(f==0){
        cout << "descending";
        return 0;
    }
    cout << "mixed";
    return 0;
}
