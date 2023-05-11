#include <iostream>

using namespace std;


int main(){
    int a[5];
    for(int i=0;i<5;i++) {
        cin >> a[i];
    }
    int v;
    cin >> v;
    
    cout << a[v-1];

    return 0;
}

/**
 * 사용자로부터 5개의 정수를 입력 받는다. 이 후, 사용자가 1을 입력하면 첫 번째 입력 받은 정수를 출력하고,
_ 2를 입력하면 두 번 째 입력 받은 정수를 출력하는 프로그램을 작성하시오.
 * 
 */