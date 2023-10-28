#include <stdio.h>
#include <mach/mach_time.h>
#include <time.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int M = 0, idx = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > M) {
                M = arr[j];
                idx = j;
            }
        }
        if (arr[n - 1 - i] != M) {
            swap(&arr[idx], &arr[n - 1 - i]);
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));
    uint64_t start, end;
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);

    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    start = mach_absolute_time();
    selectionSort(arr, n);
    end = mach_absolute_time();

    double milliseconds = (double) (end - start) * (double) timebase.numer / (double) timebase.denom / 1e6;
    printf("선택 정렬 경과 시간: %f ms\n", milliseconds);

    int *arr2 = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr2[i] = rand();
    }

    start = mach_absolute_time();
    insertionSort(arr2, n);
    end = mach_absolute_time();

    milliseconds = (double) (end - start) * (double) timebase.numer / (double) timebase.denom / 1e6;
    printf("삽입 정렬 경과 시간: %f ms\n", milliseconds);

    free(arr);
    free(arr2);
    return 0;
}
