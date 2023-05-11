#include<stdio.h>
#pragma warning(disable:4996)
#include<math.h>
#include <string.h>
int main(void) {
   char re[20] = { 0, }, new[20];
   int n = 0;
   int i = 0;
   scanf("%d", &n);
   getchar();
   for (i = 0;i <n;i++) {
      scanf("%c", &re[i]);
   }
   for (i = 0;i < n;i++) {
      new[i] = re[n - i - 1];
      
   }

      for (i = 0;i < n ;i++) {
         printf("%c", new[i]);
      }
   return 0;
}