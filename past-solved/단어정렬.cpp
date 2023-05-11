#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>

using namespace std;

int cmp(string x,  string y);

string str[20000];

int main() {
    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> str[i];
    }

    sort(str, str+N, cmp);

    for(int i=0;i<N;i++) {
        if(str[i] == str[i-1]) {
            continue;
        }
        cout << str[i] << endl;
    }

    return 0;
}

int cmp(string x,  string y){
    // 1. 길이가 같다면 사전순으로!
    if(x.length() == y.length()) {
        return x < y;
    }
    else {// 2. 길이가 다르다면, 짧은 순으로!
        return x.length() < y.length();
    }
    
}