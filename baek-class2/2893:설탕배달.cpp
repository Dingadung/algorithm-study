/*
문제
상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 
상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 
봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

상근이는 귀찮기 때문에, 
최대한 적은 봉지를 들고 가려고 한다. 
예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.

상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)

출력
상근이가 배달하는 봉지의 최소 개수를 출력한다. 만약, 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.

18 --> 4
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    
    int cnt =0 ;
    
    if(N%5 == 0) {
        cout << N / 5;
        return 0;
    }

    for(int i=0;i<=N/5;i++) {
        for(int j=0;j<=N/3;j++) {
            if(i*5 + j*3 == N) {
                v.push_back(i + j);
            }
        }   
    }
    sort(v.begin(), v.end());

    if(v.empty()) {
        cout << -1;
    }
    else
        cout << v[0];
    // else if(N%5%3==0) {
    //     cout << N/5 + N%5/3;
    // }
    // else if(N%3%5==0) {
    //     cout << N/3 + N%3/5;
    // }
    // else if(N%3 == 0) {
    //     cout << N/3;
    // }
    // else {
    //     cout << -1;
    // }
    
    // 5로 바로 나누어지는 경우
    // 5로 바로 안나누어 질 때 --->
    // 5 : 3
    // 5가 더 큰 경우, 3이 더 큰 경우
    // 3으로 나누어 지는 경우
    

    return 0;
}