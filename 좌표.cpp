#include<stdio.h>
#define ABS(a) a<0? -a:a
#define MAX(a,b) a>=b? a:b
#define MAX2(a,b,c) a>=b? c:b
// 찐, 맥스, 절댓값, 원래값


int main(){
    int x[6] = {0,},max;
    for(int i=0;i<6;i++){
        scanf("%d",&x[i]);
    }

    max = ABS(x[0]);
    int k = x[0];

    for(int i=1; i<6; i++){
        int abs = ABS(x[i]);
        max = MAX(max, abs);
        k = MAX(ABS(x[i]), max, x[i]);
    }
    printf("%d %d", k, max);


    return 0;
}


