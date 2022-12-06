#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    int e;
    for(int i=0;i<N;i++) {
        scanf("%d", &e);
        if(e < X) {
            printf("%d ", e);
        }
    }
    return 0;
}