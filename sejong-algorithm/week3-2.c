#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int Heap[100];
int n=0;

void downHeap(int i);
void printHeap();
void rBuildHeap(int i);
void buildHeap();

int main() {
    int N, key;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &key);
        Heap[i] = key;
        n++;
    }

    // rBuildHeap(1);
    buildHeap();
    printHeap();
    return 0;
}


void downHeap(int i)
{

    int left = 2*i;
    int right = 2*i + 1;

    int bigger, temp;

    if (n < (left))
        return;

    bigger = left;

    if (n >= right) {
        if (Heap[right] > Heap[bigger])
            bigger = right;
    }

    if (Heap[i] >= Heap[bigger])
        return;

    temp = Heap[i];

    Heap[i] = Heap[bigger];
    Heap[bigger] = temp;

    downHeap(bigger);
}

void printHeap() {
    for (int i = 1; i < n + 1; i++)
        printf(" %d", Heap[i]);
    printf("\n");
}

void rBuildHeap(int i)
{
    int left = 2*i;
    int right = 2*i + 1;
    if (i > n)
        return;
    
    if (left <= n)
	{
		rBuildHeap(left);
	}

	if (right <= n)
	{
		rBuildHeap(right);
	}

    rBuildHeap(left);
    rBuildHeap(right);

    downHeap(i);
}

void buildHeap()
{
    for (int i = n / 2; i >= 1; i--) 
        downHeap(i);
}