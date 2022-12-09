/*
숫자 n을 입력받고 십진수인 n을 2진수로 바꿔 출력하는 MyBinary함수를 통해 2진수를 출력하세요.
(MyBinary함수는 정수를 전달받아 2진수를 출력하는 함수입니다.)
(단, 출력되는 2진수는 10의 자리를 넘지 않습니다. 함수 미작성시 0점 처리) [15점]

[입력 예시 1]
17

[출력 예시 1]
10001

[입력 예시 2]
31

[출력 예시 2]
11111

[입력 예시 3]
10
1010
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int MyBinary(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    
    printf("%d\n", MyBinary(n));
   return 0;
}

int MyBinary(int n) {
    int bi[10];
    int ans =0;
    int cnt =0;
    while(n>0) {
        bi[cnt++] = n % 2; // 0 1 0 1
        n/=2;
    }
    for(int i=0;i<cnt;i++) {
        ans = ans*10 + bi[cnt - 1 -i];
    }
    return ans;
}