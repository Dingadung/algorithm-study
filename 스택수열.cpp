#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int cnt=1;

    stack<int> s;
    vector<char> v;

    for(int i=0;i<n;i++) {
        int e;
        cin >> e;
        while (cnt <= e) {
            s.push(cnt);
            v.push_back('+');
            cnt++;
        }
        
        if(e == s.top()) {
            s.pop();
            v.push_back('-');
        }
        else {
            cout << "NO\n";
            return 0;
        }

    }

    for(int i=0;i<v.size();i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
