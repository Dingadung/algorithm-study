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
    int elem;
    for(int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &elem);
        int idx=0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < elem) {
                idx++;
            }
        }
        
        for(int j = i; j >=idx;j--) {
            if(j+1 <n) {
                arr[j+1] = arr[j];
            }
            
        }
        arr[idx] = elem;
        // printf("idx = %d arr[idx] = %d\n", idx, arr[idx]);
    }
    
    for(int i = 0; i < n; i++) {
        printf(" %d", arr[i]); 
    }
    return 0;
}