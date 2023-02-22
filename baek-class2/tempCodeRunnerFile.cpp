#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <stack>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        string s;
        getline(cin, s);
        if(s == ".") break;

        bool check=true;
        stack<char> bal;
        
        for(int i =0; i<s.length();i++) {
            char e = s[i];
            if(e == '(' || e == '[') {
                bal.push(e);
            }
            else if(s[i] == ')') {
                if(!bal.empty() && bal.top() == '(') {
                    // balance ok
                    bal.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
            else if(s[i] == ']') {
                if(!bal.empty() && bal.top() != '[') {
                    // balance ok
                    bal.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check && bal.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    

    return 0;
}