#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long int v[100000];
long long int N, M;

void binarySearch(int key);

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0); 
        
    cin >> N;
    

    long long int e;
    
    for(int i=0;i<N;i++) {
       cin >> v[i];
    }

    sort(v, v+N);

    cin >> M;

    for(int i=0;i<M;i++) {
        cin >> e;
        binarySearch(e);
    }
    return 0;
}

void binarySearch(int key) {
    int left = 0, right = N-1;
    int mid;
    int f=0;
    while(left <= right) {
        mid = (left + right) /2;

        f=0;
        if(v[mid] == key) {
            f=1;
            break;
        }
        else if(v[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    printf("%d\n", f);
}