/*
입력
첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다.

출력
여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.

제한
2 ≤ N ≤ 50
10 ≤ x, y ≤ 200

5
55 185
58 183
88 186
60 175
46 155
->
2 2 1 2 5
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;

int main(){
    int N;
    cin >> N;
    int rank[50]={0};
    for(int i=0;i<N;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for(int i=0;i<N;i++) {
        int x = v[i].first;
        int y = v[i].second;
        for(int j=0;j<v.size();j++) {
            if(v[j].first > x && v[j].second > y) {
                rank[i]++;
            }
        }
    }

    for(int i=0;i<N;i++) {
        cout << rank[i] + 1 << " ";
    }
    return 0;
}