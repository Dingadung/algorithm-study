/*
문제
자연수 
\(N\)과 정수 
\(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 
\(N\)과 
\(K\)가 주어진다. (1 ≤ 
\(N\) ≤ 10, 0 ≤ 
\(K\) ≤ 
\(N\))

출력
 
\(\binom{N}{K}\)를 출력한다.

5 2
-> 10
*/

#include <iostream>

using namespace std;

int factorial(int N);

int main(){
    int K, N;
    cin >> N >> K;
    int NK = factorial(N) / (factorial(K)*factorial(N-K));
    cout << NK;
    return 0;
}

int factorial(int N) {
    int f=1;
    for (int i=N;i>0;i--) {
        f *= i;
    } 
    return f;
}