#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int treebonach(int x);

int main() {
    int n;
    scanf("%d", &n);
    // printf("%d\n", treebonach(n));
    printf("%d", n);
    return 0;
}


int treebonach(int x) {
    if(x==0 || x == 1) return 0;
    if(x==1) return 1;
    return treebonach(treebonach(x-1) + treebonach(x-2) + treebonach(x-3));
}