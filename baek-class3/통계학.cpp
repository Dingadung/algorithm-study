#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;

int main(){
    int N;
    scanf("%d", &N);

    int S=0;

    int cnt[8001] = {0};

    for(int i=0;i<N;i++) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
        S += tmp;
        cnt[tmp + 4000]++;
    }

    sort(v.begin(), v.end());

    S = round((float)S/N);

    int middle = v[N/2];

    int range = v.back() - v.front();

    int most = cnt[0], mvalue = - 4000;
    bool notFirst = true;

    for(int i=1;i<8001;i++) {
        if(cnt[i] == 0) continue;
        else if(most < cnt[i]) {
            most = cnt[i];
            mvalue = i - 4000;
            notFirst = true;
        }
        else if(most ==  cnt[i] && notFirst) {
            mvalue = i - 4000;
            notFirst = false;
        }
    }

    printf("%d\n", S);
    printf("%d\n", middle);
    printf("%d\n", mvalue);
    printf("%d\n", range);


    return 0;
}