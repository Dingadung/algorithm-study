#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)


int H[100], n = 0;

void downHeap(int i) {

   int bigger, temp;

   if ((n < (i * 2)) && (n < (i * 2 + 1)))
      return;

   bigger = i * 2;

   if (n >= i * 2 + 1) {
      if (H[i * 2 + 1] > H[bigger])
         bigger = i * 2 + 1;
   }

   if (H[i] >= H[bigger])
      return;

   temp = H[i];

   H[i] = H[bigger];
   H[bigger] = temp;

   downHeap(bigger);
}

void printHeap() {
   for (int i = 1; i < n + 1; i++)
      printf(" %d", H[i]);

   printf("\n");
}

void rBuildHeap(int i) // 재귀 방식으로 상향식 힙 생성
{
   if (i > n)
      return;

   rBuildHeap(2 * i);
   rBuildHeap(2 * i + 1);

   downHeap(i);
}

void buildHeap() // 비재귀 방식으로 상향식 힙 생성
{
   for (int i = n / 2; i >= 1; i--) 
      downHeap(i);
}

void main() {

   int N; // 키 개수
   int input; // 키들 저장할 변수

   scanf("%d", &N);

   for (int i = 1; i <= N; i++) {

      scanf("%d", &input);

      H[i] = input;
      n++;
   }

   rBuildHeap(1);
   // buildHeap();

   printHeap();
}