#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

// 해시 테이블에 원소를 삽입하는 함수
int insertItem(int *root, int k, int M) {
    int hash;
    for(int i =0;i<M;i++) {
        hash = (k%M+i) % M; // 개방 주소법을 사용하여 해시 값 계산
        // (h(k) + f(i)) % M, f(i) = i

        if(root[hash] == 0) { // 해당 위치가 비어 있으면
            root[hash] = k; // 원소를 삽입
            return hash; // 삽입된 위치를 반환
        }
        printf("C"); // 충돌 발생 시, 'C'를 출력
    }
    return 0;
}

// 해시 테이블에서 원소를 검색하는 함수
int search(int *root, int k, int M) {
    int hash;
    for(int i = 0;i<M;i++) {
        hash = (k % M + i) % M; // 개방 주소법을 사용하여 해시값 계산

        if(root[hash] == k) {
            // 해당 위치에 원소를 찾으면
            return hash; // 해당 위치를 반환
        }
    }
    return -1; // 원소를 찾지 못한 경우 -1을 반환
}

int main() {
    int *root = NULL;
    int M, N, k, i, n;
    char e;
    scanf("%d %d", &M, &N); // 해시 테이블 크기(M)와 작업 횟수(N)을 입력 받음
    root = (int *)malloc(sizeof(int)*M); // 해시테이블을 동적으로 할당
    for(i = 0;i<M;i++) {
        root[i] = 0; // 해시 테이블 초기화: 모든 위치를 0으로 초기화
    }
    while(1) {
        getchar();
        scanf("%c", &e); // 사용자로부터 명령 문자를 입력 받음
        if(e == 'i') {
            scanf("%d", &k); // 삽입할 원소를 입력 받음
            printf("%d\n", insertItem(root, k, M)); //삽입 함수 호출 및 결과 출력
        } else if(e == 's') {
            scanf("%d", &k); // 검색할 원소를 입력 받음
            n = search(root, k, M); // 검색 함수 호출
            printf("%d", n);
            if(n != -1) {
                printf(" %d", root[n]); // 원소를 찾았을 때 해당 위치의 값 출력
            }
            printf("\n");
        } else if(e == 'e') {
            break; // 프로그램 종료
        }
    }
    free(root); // 동적으로 할당한 메모리 해제
    return 0;
}