#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int *Heap;
int n=0;

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();
int main() {
    char e;
    int key;
    scanf("%c", &e);
    Heap = (int*)malloc(n*sizeof(int));

    for(int i=0; i<n; i++) {
        scanf("%d", &key);
    }
    return 0;
}

void upHeap(int i) // 힙 내 위치 i에 저장된 키를 크기에 맞는 위치로 상향 이동
{
    int temp;
    if (i == 1)
        return;
    if (Heap[i] < Heap[i / 2])
        return;
    temp = Heap[i];
    Heap[i] = Heap[i / 2];
    Heap[i / 2] = temp;
    upHeap(i / 2);
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

void insertItem(int key) {
    n++;
    Heap[n] = key;
    upHeap(n);
}

int removeMax() {
    int key;
    key = Heap[1];
    Heap[1] = Heap[n--];
    downHeap(1);
    return key;
}

void printHeap() {
    for (int i = 1; i < n + 1; i++)
        printf(" %d", Heap[i]);
    printf("\n");
}