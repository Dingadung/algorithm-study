#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)


int main() {
    int n;
    scanf("%d", &n);

    // int *arr = (int*)malloc(n*sizeof(int));
    int arr[9999] = {0,};
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // int *set = (int*)malloc(n*sizeof(int));
    int set[9999] = {0,};
    for(int i=0; i<n; i++) {
        set[i] = 0;
    }

    int idx = 0;
    for(int i =0;i<n;i++) {
        int f=0;
        for(int j =0; j<n; j++) {
            if(arr[i] == set[j]) {
                f=1;
            }
        }
        if(f==0) {
            set[idx++] = arr[i];
        }
    }

    // for(int i=0;i<n;i++) {
    //     printf("%d ", set[i]);
    // }
    // printf("%d ", idx);

    // int *cnt = (int*)malloc(idx*sizeof(int));
    int cnt[9999] = {0, };
    for(int i=0; i<n; i++) {
        cnt[i] = 0;
    }
    for(int i=0; i<idx; i++) {
        for(int j=0;j<n;j++) {
            if(set[i] == arr[j]) {
                cnt[i] ++;
            }
        }
    }

    

    for(int i=0;i<idx;i++) {
        for(int j=0;j<idx-1;j++) {
            if(cnt[j]>cnt[j+1]) {
                int tmp = cnt[j];
                cnt[j]=cnt[j+1];
                cnt[j+1]=tmp;
                
                tmp = set[j];
                set[j]=set[j+1];
                set[j+1]=tmp;
            }else if(cnt[j]==cnt[j+1]) {
                if(set[j]>set[j+1]) {
                    int tmp = cnt[j];
                    cnt[j]=cnt[j+1];
                    cnt[j+1]=tmp;
                    
                    tmp = set[j];
                    set[j]=set[j+1];
                    set[j+1]=tmp;
                }
            }
        }
    }


    // for(int i=0; i<idx; i++) {
    //     printf("%d: %d, ", set[i], cnt[i]);
    // }

    ////////////////////////////////////////////////////////////////

    // int *cntSet = (int*)malloc(idx*sizeof(int));
    int cntSet[9999] = {0,};
    for(int i=0; i<idx; i++) {
        cntSet[i] = 0;
    }

    int setIdx = 0;
    for(int i =0;i<idx;i++) {
        int f=0;
        for(int j =0; j<n; j++) {
            if(cnt[i] == cntSet[j]) {
                f=1;
            }
        }
        if(f==0) {
            cntSet[setIdx++] = cnt[i];
        }
    }

    

    for(int i=0;i<setIdx;i++) {
        for(int j=0;j<setIdx-1;j++) {
            if(cntSet[j]<cntSet[j+1]) {
                int tmp = cntSet[j];
                cntSet[j]=cntSet[j+1];
                cntSet[j+1]=tmp;
            }
        }
    }

    // for(int i=0;i<setIdx;i++) {
    //     printf("%d\n", cntSet[i]);
    // }

    // printf("setIDX : %d\n", setIdx);

    for(int i=0;i<idx;i++) {
        if(setIdx>1 && cntSet[1] == cnt[i]) {
            printf("%d %d\n", set[i], cnt[i]);
        } else if(setIdx==1){
            printf("%d %d\n", set[i], cnt[i]);
        }
    }
    return 0;
}
