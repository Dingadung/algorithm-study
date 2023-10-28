#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int M = 0, idx =0;
    for(int i = 0; i < n; i++) {
        M = 0;
        for(int j = 0; j < n-i; j++) {
            if(arr[j] > M) {
                M = arr[j];
                idx = j;
            }
        }
        if(arr[n-1-i] != M) {
            swap(&arr[idx], &arr[n-1-i]);
        }
        
    }
    for(int i = 0; i < n; i++) {
        printf(" %d", arr[i]);   
    }
    return 0;
}