#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stdlib.h>

using namespace std;

int check(int x, int y, int w, int h);


int main() {
    int x, y, w, h; // (x, y) .  (w, y)
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int L=0, L2=0, ans;

    if(check(x, y, w, h) == 1 ) {
        ans = sqrt((x-w)*(x-w) + (y-h)*(y-h));
    }
    else if(check(x, y, w, h) == 2) {
        ans = sqrt((x-0)*(x-0) + (y-h)*(y-h));
    }
    else if(check(x, y, w, h) == 3) {
        ans = sqrt((x-0)*(x-0) + (y-0)*(y-0));
    }
    else if(check(x, y, w, h) == 4) {
        ans = sqrt((x-w)*(x-w) + (y-0)*(y-0));
    }
    else {
        L = min(abs(x-w), abs(x-0));
        L2 = min(abs(y - 0), abs(y-h));
        ans = min(L, L2);
    }
    
    cout << ans;

    return 0;
}

int check(int x, int y, int w, int h) {
    if(x < 0) {
        if(y < 0) {
            return 3;
        }
        else if(y > h) {
            return 2;
        }
    }
    else if(x > w) {
        if(y > h) {
            return 1;
        }
        else if(y < 0) {
            return 4;
        }
    }
    return 5;
}