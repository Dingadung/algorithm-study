#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int treebonach(int x);
    int a =0;

int main() {
    int n;
    scanf("%d", &n);
    // printf("%d\n", n);
    printf("%d %d", treebonach(n), a);
    return 0;
}


int treebonach(int x) {
    a++;

    if(x==0 || x ==1) return 0;
    if(x==2) return 1;

    return treebonach(x-1) + treebonach(x-2) + treebonach(x-3);
}