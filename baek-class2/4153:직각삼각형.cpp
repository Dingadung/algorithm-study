/*
문제
과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다. 주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.
입력
입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다. 각 테스트케이스는 모두 30,000보다 작은 양의 정수로 주어지며, 각 입력은 변의 길이를 의미한다.
출력
각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.
6 8 10
25 52 60
5 12 13
0 0 0
->
right
wrong
right
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    while(a != 0 && b!=0 && c!=0){
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        if(v[2]*v[2] == v[0]*v[0] + v[1]*v[1]) cout << "right\n";
        else cout << "wrong\n";

        // cout << "v[2]*v[2] = " <<v[2]*v[2] << "v[0]*v[0] + v[1]*v[1]  = "<< v[0]*v[0] + v[1]*v[1] << "\n";
        cin >> a >> b >> c;
    }
    

    return 0;
}