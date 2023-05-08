#include <iostream>

using namespace std;


int main(){
    int n = 0;

    while(true) {
        cin >> n;
        if(n == 99999) break;
        for(int i=0;i<n;i++) {
            for(int j=n;j>i+1;j--) {
                cout << " ";
            }
            for(int j=0;j<=i;j++) {
                cout << "*";
            }
            cout << "\n";   
        } 
    }
    
  

    return 0;
}

/**
 * @brief 양의 정수 99999를 입력받으면 종료하게 하고 그렇지 않으면 프로그램이 종료되지 않고 계속
입력받고 출력받게 만들어주세요
 * 
 */