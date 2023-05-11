#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001] = {0};

int M, N;

int main() {
    scanf("%d %d", &M, &N);

    for(int i=2;i<=N;i++) {
        arr[i] = i;
    }



    for(int i=2; i*i <= N ;i++) {
        if(arr[i] == 0) continue;
        
        for(int j=i*i;j<=N;j+=i) {
            arr[j] = 0;
        }
    }

    arr[2] = 0;

    for(int i=M;i<=N;i++) {
        if(arr[i] != 0)
            printf("%d\n", arr[i]);
    }

    // for (int i=0;i<=N;i++) {
    //     printf("%d ", arr[i]);
    //     if(i!=0 && i%5==0) printf("\n");
    // }
    return 0;
}
