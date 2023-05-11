#include <iostream>
#include <string>

using namespace std;

bool check(char e);

int main(){
    string str;
    getline(cin, str);
    int cnt=0;
    for(int i=0;i<str.length()-1;i++){
        if(str[i] == ' ' && check(str[i+1])) { // 오른쪽이 알파벳 왼쪽이 빈칸
            cnt++;
        }
    }
    if(check(str[0])) cnt++;
    cout << cnt <<endl;
    return 0;
}

bool check(char e) {
    return e>='a' && e<='z' || e>='A' && e<='Z';
}