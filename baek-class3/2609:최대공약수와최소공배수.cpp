#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int max, min;
    if(a>b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }
    while(max % min >0) {
        int tmp = max;
        max = min;
        min = tmp%min;
    }
    cout << min << endl << min*(a/min)*(b/min);
    return 0;
}