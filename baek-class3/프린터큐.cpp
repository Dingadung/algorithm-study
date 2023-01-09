#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main(){
    int T;
    cin >> T;

    int N, M;



    while(T-- >0) {
        cin >> N >> M; // 문서의 개수, 궁금한 문서가 놓여있는 위치
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int cnt =0;
        
        for(int i=0;i<N;i++) {
            int e;
            cin >> e;
            q.push({i, e});
            pq.push(e);
        }

        while(!q.empty()) {
            
            int idx = q.front().first;
            int val = q.front().second;

            q.pop();

            if(val == pq.top()) {
                pq.pop();
                cnt ++ ;
                if(idx == M) {
                    cout << cnt << endl;
                    break;
                }
            }
            else {
                q.push({idx, val});
            }
        }
    }

    return 0;
}