#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    while(true) {
        string s;
        getline(cin, s);
        if(s == ".") break;

        stack<char> bal;
        bool check=true;
        
        for (int i = 0; i < s.length(); i++) {
            char e = s[i];
            if(e == '(' || e == '[') {
                bal.push(e);
            }
            else if(e == ')') {
                if(!bal.empty() && bal.top() == '(') {
                    // balance ok
                    bal.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
            else if(e == ']') {
                if(!bal.empty() && bal.top() == '[') {
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