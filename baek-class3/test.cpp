
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q, q2;

int main(){
    int N;
    scanf("%d", &N);

    for(int i=1;i<=N;i++) {
        q.push(i);
    }

    while(q.size()>1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();

    return 0;
}
