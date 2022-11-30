#include <iostream>
#include <string>

using namespace std;

string lower(string str);

int main(){
    string str;
    char ori[60];
    cin >> str;
    str = lower(str);

    char e;
    int cnt = 0;
    int len = str.length();

    int f=0;
    for(int i=0;i<len;i++) {
        e = str[i];
        for(int j=0;j<cnt;j++) {
            if(e == ori[j]) {
                f = 1;
            }
        }
        if(f == 0) {
            ori[cnt++] = e;
        }
        f=0;
    }

    int max=0, c=0;
    char ans;

    for(int i=0;i<cnt;i++) {
        e = ori[i];
      for(int j=0;j<len;j++) {
            if(e == str[j]) {
                c++;
            }
        }  
        if(c == max){
            ans = '?';
        }
        if(c > max) {
            max = c;
            ans = ori[i];
        }
        c=0;
    }

    if(ans >= 'a' && ans <= 'z') {
        ans = ans - 'a' + 'A';
    }

    cout << ans;
    return 0;
}

string lower(string str) {
    for(int i=0;i<str.length();i++) {
        if(str[i] >='A' && str[i] <='Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}
