#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>

using namespace std;

string wb[] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string bw[] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string ch[50];

int cntWb(int x, int y){
    int cnt=0;
    for(int i = 0; i<8; i ++) {
        for(int j=0;j<8;j++) {
            if(ch[i+x][j+y] != wb[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int cntBw(int x, int y){
    int cnt=0;
    for(int i = 0; i<8; i ++) {
        for(int j=0;j<8;j++) {
            if(ch[i+x][j+y] != bw[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        cin >> ch[i];
    }

    int MIN = 12345;

    for(int i=0;i+8<=N;i++) {
        for(int j=0;j+8<=M;j++) {
            int tmp;
            tmp = min(cntBw(i, j), cntWb(i, j));
            if(tmp < MIN) {
                MIN = tmp;
            }
        }
    }
    cout << MIN;
    return 0;
}