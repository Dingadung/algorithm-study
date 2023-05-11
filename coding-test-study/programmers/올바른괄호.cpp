/*
괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 예를 들어

"()()" 또는 "(())()" 는 올바른 괄호입니다.
")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.
'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.

*/

#include<string>
#include <iostream>
#include<stack>

using namespace std;
stack<char> st;

bool solution(string s)
{
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') {
            st.push(s[i]);
        }
        if(s[i]==')') {
            if(st.empty()) return false;
            int val = st.top();
            st.pop();
        }
        
    }
    if(st.empty())return true;
    else return false;
}
