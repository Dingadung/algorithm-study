/*
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. 
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 
그리고 항상 K ≦ N 이다. 
그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>

using namespace std;

unsigned int len[10000];
unsigned int K, N;
unsigned int ans;


int main() {
    cin >> K >> N; // 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N
    
    unsigned int maxi = 0;

    for(int i=0;i<K;i++) {
        cin >> len[i];
        maxi = max(maxi, len[i]);
    }

    unsigned int left = 1, right = maxi, mid;

    while(left <= right) {
        unsigned int cnt = 0;
        mid = (left + right) /2;

        for(int i=0;i<K;i++) {
            cnt += len[i] / mid;
        }

        if(cnt >= N) {
            left = mid + 1;

            ans = max(ans, mid);
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}