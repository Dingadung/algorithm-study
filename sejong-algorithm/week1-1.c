#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)


typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    char elem;
}Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int n; // 헤더와 트레일러 제외한 노드 개수
}List;

void initList(List* list);
void add(List* list, int r, char e);
char delete(List* list, int r);
char get(List* list, int r);
void print(List* list);


int main() {
    int N = 0; // 연산의 개수
    int rank = 0; // 순위

    char c_word;
    char elm;
    char tmp;

    List lList;
    initList(&lList); // 왜 주소로 넣어줘야하지??

    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        scanf("%c", &c_word);
        getchar();
        switch (c_word)
        {
        case 'A':
            scanf("%d %c", &rank, &elm);
            getchar();
            add(&lList, rank, elm);
            break;
        case 'D':
            scanf("%d", &rank);
            getchar();
            delete(&lList, rank);
            break;
        case 'G':
            scanf("%d", &rank);
            getchar();
            tmp = get(&lList, rank);
            if (tmp != 1)
                printf("%c\n", tmp);
            break;
        case 'P':
            print(&lList);
            break;
        default:
            break;
        }
    }



    return 0;
}

void initList(List* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->tail = (Node*)malloc(sizeof(Node));
    list->head->next = list->tail; // 왜 list의 tail의 prev를 안가르키지?
    list->tail->prev = list->head;
    list->n = 0;
}
void add(List* list, int r, char e) {
    if ((r < 1) || (r > list->n + 1))
    {
        printf("invalid position\n");
        return;
    }
    Node *ptr = list->head;
    for(int i=0;i<r;i++) {
        ptr = ptr->next;
    }

    Node* new_Node = (Node*)malloc(sizeof(Node));
    new_Node->elem = e;
    new_Node->next = ptr;
    new_Node->prev = ptr->prev;
    (ptr->prev)->next = new_Node;
    ptr->prev = new_Node;
    list->n += 1;

}
char delete(List* list, int r) {
    if ((r < 1) || (r > list->n))
    {
        printf("invalid position\n");
        return 1;
    }

    Node *ptr = list->head;

    for(int i=0;i<r;i++) {
        ptr = ptr->next;
    }

    char elem = ptr->elem;
    (ptr->prev)->next = ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    list->n -= 1;
    return elem;
}


char get(List* list, int r) {
    if ((r < 1) || (r > list->n))
    {
        printf("invalid position\n");
        return 1;
    }

    Node *ptr = list->head;

    for(int i=0;i<r;i++) {
        ptr = ptr->next;
    }

    return ptr->elem;
}

void print(List* list) {
    Node* ptr = list->head->next;
    while (ptr != list->tail)
    {
        printf("%c", ptr->elem);
        ptr = ptr->next;
    }
    printf("\n");
}