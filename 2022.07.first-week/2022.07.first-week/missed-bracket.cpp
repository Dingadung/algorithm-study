#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int MAX=51;
string cal;
char opt[MAX];
int num[MAX]={0};

bool isMinus;

int main() {
    cin >> cal; // 식
    //cout << cal << endl;
    
    int num_idx=0, opt_idx=0, ans=0;
    isMinus=false;

    for(int i=0;i<cal.length()+1;i++){
        //printf("cal[%d]: %c \n", i, cal[i]);
        if (cal[i] == '-' || cal[i] == '+' ) {
            opt[opt_idx] = cal[i];
            num_idx++;
            opt_idx++;
        }
        else if (cal[i] == '\0') {
            num_idx++;
        } 
        else{
            num[num_idx] = num[num_idx] * 10 + (cal[i] - '0');
        }
    }

    
    //for (int i = 0; i < num_idx; i++) {
    //    printf("num: %d\n\n", num[i]);
    //}
    //cout << num_idx << endl;

    ans += num[0];


    for(int i=0;i<opt_idx;i++){
        if(opt[i]=='-'){
            isMinus=true;
        }
        if(isMinus){
            ans -= num[i+1];
        }
        else{
            ans += num[i+1];
        }
    }
    cout << ans;
    return 0;
}
