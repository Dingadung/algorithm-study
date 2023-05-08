#include <iostream>

using namespace std;


int main(){
    
    for(int i=0;i<3;i++) {
        for(int j=1;j<=9;j++) {
            for(int k=3*i+1;k<=3*(i+1);k++) {
                cout << k << "X" << j << "=" << j*k << " ";
                if(k %3 ==0) cout << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}

/**
 * @brief 양의 정수 99999를 입력받으면 종료하게 하고 그렇지 않으면 프로그램이 종료되지 않고 계속
입력받고 출력받게 만들어주세요
 * 
 */