
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q, q2;

int main(){
    int N;
    scanf("%d", &N);

    for(int i=N;i>0;i--) {
        q.push(i);
    }

    while(N > 1) {
        int e;
        q.pop();
        e = q.front();
        q2.push(e);
        q.pop();
    }

    return 0;
}
