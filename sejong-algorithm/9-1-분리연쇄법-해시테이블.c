#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

#define TRUE 1
#define FALSE 0
#define NOSUCHKEY -1

// 해시 테이블의 각 노드를 나타내는 구조체
typedef struct Node {
    int key; // 키 값을 저장하는 변수
    struct Node *next; // 다음 노드를 가리키는 포인터
} NODE;

// 해시 테이블의 버킷 배열을 초기화하는 함수
NODE **initBucketArray(int M);

// 새로운 노드를 생성하여 반환하는 함수
NODE *getNode(int x);

// 해시 테이블에 아이템을 삽입하는 함수
void insertItem(NODE * ht[], int x, int M);

// 해시 테이블에 아이템을 제거하는 함수
int removeElement(NODE *ht[], int x, int M);

// 해시 테이블에서 아이템을 검색하고 위치를 반환하는 함수
int findElement(NODE *ht[], int x, int M);

// 해시 테이블의 내용을 출력하는 함수
void printElement(NODE *ht[], int M);

int main() {
    char cmd;
    int M, x;
    NODE **ht = NULL; // 해시테이블을 나타내는 이중 포인터

    scanf("%d", &M); // 버킷 배열의 크기를 입력 받음
    ht = initBucketArray(M); // 초기화된 해시 테이블을 생성

    while(1) {
        getchar();
        scanf("%c", &cmd); // 사용자로부터 명령 문자를 입력 받음

        if(cmd == 'i') {
            scanf("%d", &x);
            insertItem(ht, x, M); // 아이템 삽입
        } else if(cmd == 'd') {
            scanf("%d", &x);
            printf("%d\n", removeElement(ht, x, M)); // 아이템 제거 및 결과 출력
        } else if(cmd == 's') {
            scanf("%d", &x);
            printf("%d\n", findElement(ht, x, M)); // 아이템 제거 및 결과 출력
        } else if(cmd == 'p') {
            printElement(ht, M); // 해시테이블의 내용 출력
        } else if(cmd == 'e') {
            break;
        }
    }
    return 0;
}

// 해시 테이블의 버킷 배열을 초기화하는 함수
NODE **initBucketArray(int M) {
    NODE **ht = NULL; /// 이중 포인터로 버킷 배열 생성

    ht = (NODE**)malloc(sizeof(NODE*)*M); // 메모리 할당
    for(int i=0;i<M;i++) {
        ht[i] = NULL; // 각 버킷을 초기화
    }
    return ht;
}

// 새로운 노드를 생성하여 반환하는 함수
NODE *getNode(int x) {
    NODE*new = NULL;

    new = (NODE*)malloc(sizeof(NODE)); // 새로운 노드 메모리 할당
    new -> key = x; // 키 값을 설정
    new-> next = NULL; // 다음 노드를 초기화
    return new;
}

// 해시 테이블에 아이템을 삽입하는 함수
void insertItem(NODE * ht[], int x, int M) {
    NODE *new = NULL;
    int hx = x%M; // 해시 함수를 사용하여 버킷 위치 계산 // h(x) = k % M

    new = getNode(x); // 새로운 노드 생성
    new -> next = ht[hx]; // 연결리스트의 첫번째 노드로 삽입
    ht[hx] = new;
}

// 해시 테이블에 아이템을 제거하고 제거한 노드의 수를 반환하는 함수
int removeElement(NODE *ht[], int x, int M) {
    int cnt = 0;
    int hx = x % M;
    NODE * node = ht[hx], *prev = NULL;

    while(node) {
        cnt += 1;
        if(node -> key == x) {
            if(cnt == 1) {
                ht[hx] = node -> next;
            } else {
                prev -> next = node -> next;
            }
            free(node);
            return cnt;
        }
        prev = node;
        node = node -> next;
    }
    return 0;
}

// 해시 테이블에서 아이템을 검색하고 위치를 반환하는 함수
int findElement(NODE *ht[], int x, int M) {
    int cnt = 0;
    NODE * node = ht[x % M];

    while(node) {
        cnt +=1;
        if(node -> key == x) {
            return cnt; // 아이템을 찾으면 위치 반환
        }
        node = node -> next;
    }
    return 0; // 아이템을 찾지 못한 경우 0 반환
}

// 해시 테이블의 내용을 출력하는 함수
void printElement(NODE *ht[], int M) {
    NODE *node = NULL;

    for(int i=0;i<M;i++) {
        node = ht[i];
        while(node) {
            printf(" %d", node -> key); // 각 버킷의 노드 값 출력
            node = node ->next;
        }
    }
    printf("\n");
}