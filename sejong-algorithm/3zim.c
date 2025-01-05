#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int main() {
    int limit, cnt;
    int *zim = (int *)malloc(sizeof(101));
    scanf("%d %d", &limit, &cnt);
    for(int i = 0;i<cnt;i++) {
        int weight, value;
        scanf("%d %d", &weight, &value);
        zim[weight] = value;
    }
    return 0;
}