#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#pragma warning(disable:4996)
#define PI 3.1415926
typedef unsigned char Data;

typedef struct {
   double real;
   double imag;
} Complex;

Complex complex_multiply(Complex a, Complex b) {
   Complex result;
   result.real = (double)a.real * (double)b.real - (double)a.imag * (double)b.imag;
   result.imag = (double)a.real * (double)b.imag + (double)a.imag * (double)b.real;
   return result;
}


// Exponential function for complex numbers
Complex complex_exp(double angle) {
   Complex result;
   result.real = cos(angle);
   result.imag = sin(angle);
   return result;
}

void DFT_2D(Data** input, Data** output, int N) {
   for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) {
         Complex sum = { 0.0, 0.0 };

         for (int m = 0; m < N; m++) {
            for (int n = 0; n < N; n++) {
               double angle = -2 * PI * (u * m + v * n) / N;
               Complex exp_part = complex_exp(angle);
               Complex input_val = { input[m][n], 0.0 };

               Complex term = complex_multiply(input_val, exp_part);
               sum.real += term.real;
               sum.imag += term.imag;
            }
         }
         sum.real /= (N * N);
         sum.imag /= (N * N);

         
         // Compute the magnitude and clip to 255
         Data magnitude = (Data)fmin(sqrt(sum.real * sum.real + sum.imag * sum.imag), 255);
         output[u][v] = magnitude;
      }
   }
}

int main()
{
   FILE* fp;
   Data** input, ** output;
   int i, j;
   double val;

   //Memory alloc
   input = (Data**)malloc(sizeof(Data*) * 512);
   for (i = 0; i < 512; i++)
      input[i] = (Data*)malloc(sizeof(Data) * 512);

   output = (Data**)malloc(sizeof(Data*) * 256);
   for (i = 0; i < 256; i++)
      output[i] = (Data*)malloc(sizeof(Data) * 256);

   //File read
   fp = fopen("lena.img", "rb");
   for (i = 0; i < 512; i++)
   {
      fread(input[i], sizeof(Data), 512, fp);
   }
   fclose(fp);

   //Zoom-out (downsampling) : 512x512 Lena image to 256x256 Lena image
   for (i = 0; i < 512; i += 2)
   {
      for (j = 0; j < 512; j += 2)
      {
         val = (input[i][j] + input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1]) / 4;
         output[i / 2][j / 2] = (Data)val;
      }
   }

   //File write
   fp = fopen("downsampling.img", "wb");

   for (i = 0; i < 256; i++)
   {
      fwrite(output[i], sizeof(Data), 256, fp);
   }
   fclose(fp);

   ///DFT_2D

   fp = fopen("downsampling.img", "rb");
   if (fp == NULL) {
      printf("이미지 파일을 열 수 없습니다! \n");
      return 1;
   }
   for (i = 0; i < 256; i++) { 
      fread(output[i], sizeof(Data), 256, fp);
   }
   fclose(fp);

   Data** dftResult = (Data**)malloc(sizeof(Data*) * 256);
   for (i = 0; i < 256; i++) {
      dftResult[i] = (Data*)malloc(sizeof(Data) * 256);
   }

   for (i = 0; i < 256; i++) { 
      DFT_2D(output, input, 256); 
   }


   fp = fopen("DFT_2D.img", "wb");
   for (i = 0; i < 256; i++) {
      fwrite(dftResult[i], sizeof(Data), 256, fp);
   }
   fclose(fp);










   //Memory free
   for (i = 0; i < 512; i++)
      free(input[i]);
   free(input);

   for (i = 0; i < 256; i++)
      free(output[i]);
   free(output);

   for (i = 0; i < 256; i++) {
      free(dftResult[i]);
   }
   free(dftResult);
}