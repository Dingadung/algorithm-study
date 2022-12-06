#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    string ox;
    for(int i=0;i<N;i++) {
        cin >> ox;
        int cnt = 0, sum=0;
        for(int j=0;j<ox.length();j++) {
            if(ox[j]=='O') {
                cnt++;
                sum += cnt;
            }
            if(ox[j]!='O') {
                cnt=0;
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}
