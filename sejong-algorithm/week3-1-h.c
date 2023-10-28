#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)


int H[100], n = 0;

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();



void main() {

   int key;
   char input;

   while (1) {

      scanf("%c", &input);

      if (input == 'q')
         break;

      if (input != 'q')
      {
         switch (input)
         {
         case 'i': //insertItem 호출
            scanf("%d", &key);
            insertItem(key); // n 위치에 key 삽입, upHeap(n) 호출 수행 후 n 갱신
            printf("0\n");
            getchar();
            break;

         case 'd': // removeMax 호출
            printf("%d\n", removeMax()); // downHeap 호출 수행 후 n 갱신
            getchar();
            break;

         case 'p': // printHeap 호출
            printHeap(); // 힙에 저장된 키들을 레벨순서로 인쇄
            getchar();
            break;
         }
      }
   }
}

void upHeap(int i) // 힙 내 위치 i에 저장된 키를 크기에 맞는 위치로 상향 이동
{
   int temp;
   if (i == 1)
      return;
   if (H[i] <= H[i / 2])
      return;
   temp = H[i];
   H[i] = H[i / 2];
   H[i / 2] = temp;
   upHeap(i / 2);
}

void downHeap(int i)
{
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

void insertItem(int key) {
   H[++n] = key;
   upHeap(n);
}

int removeMax() {

   int key;
   key = H[1];
   H[1] = H[n--];

   downHeap(1);

   return key;
}

void printHeap() {
   for (int i = 1; i < n + 1; i++)
      printf(" %d", H[i]);
   printf("\n");
}