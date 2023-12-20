#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

/*
- n 개의 정점과 m 개의 간선으로 구성
- 정점은 1 ~ n 사이의 정수로 번호가 매겨져 있고, 정점의 번호는 모두 다름
- 모든 간선은 무방향 간선이고, 한 정점에서 임의의 다른 정점으로 가는 경로는 반드시 존재
- 인점 리스트 구조를 사용하여 표현해야함


인접 정점의 조사 순서
- 정점 u의 인접 정점(or 부착 간선)들을 번호가 작은 정점부터 조사한다.
(즉, 아래 DFS 의사 코드의 for 문(☚)에서 인접 정점들을 번호가 작은 정점부터 큰 순서대로 조사하라. 조사 순서에 따라 방문 결과가 달라질 수 있음에 유의할 것)

입력
- 첫 줄에 정점의 개수 n, 간선의 개수 m, 순회 시작 정점 번호 s가 주어진다.
- 이후 m개의 줄에 한 줄에 하나씩 간선의 정보(간선의 양 끝 정점 번호)가 주어진다. 간선은 임의의 순서로 입력되고, 중복 입력되는 간선은 없다.
(무방향 간선이므로 간선 (u, v)와 (v, u)는 동일한 간선으로 취급)
◦ 출력
- 출발정점 s에서 출발하는 DFS의 방문 순서대로 정점 번호를 출력한다.
*/ 

// 정점과 간선의 레이블을 정의하는 열거형
typedef enum label {
    FRESH,    // 방문하지 않은 상태
    VISITED,  // 방문한 상태
    TREE,     // 트리 간선
    BACK      // 역방향 간선
} LABEL;

// 간선을 나타내는 구조체
typedef struct s_edge {
    LABEL label;
    struct s_vertex *v1;
    struct s_vertex *v2;
    struct s_edge *next;
} t_edge;

// 노드와 간선을 연결하는 구조체
typedef struct s_NtoE {
    struct s_edge *edge;
    struct s_NtoE *next;
} t_NtoE;

// 그래프 정점을 나타내는 구조체
typedef struct s_vertex {
    int data;
    LABEL label;
    struct s_NtoE *ntoe;
    struct s_vertex *next;
} t_vertex;

// 함수 원형 선언
t_vertex *init_vertex(int data);
void addLast_vertex(t_vertex **head, int data);
t_vertex *find_vertex(t_vertex *node, int data);
t_edge *init_edge(t_vertex *v1, t_vertex *v2);
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2);
t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2);
t_NtoE *init_NtoE(t_edge *edge);
void add_NtoE(t_NtoE *head, t_edge *edge, int data, int check);
t_vertex *opposite_vertex(t_edge *edge, int data);
void makeGraph(t_vertex **vertices, t_edge **edges, int n, int m);
void rDFS(t_vertex *v);

int main() {
    int n, m, s;
    t_vertex *vertices = NULL;
    t_edge *edges = NULL;

    // 정점의 개수, 간선의 개수, 시작 정점을 입력
    scanf("%d%d%d", &n, &m, &s);
    // 그래프 생성
    makeGraph(&vertices, &edges, n, m);
    // 시작 정점부터 깊이 우선 탐색 수행
    rDFS(find_vertex(vertices, s));
    return 0;
}

// 새로운 정점을 초기화하는 함수
t_vertex *init_vertex(int data) {
    t_vertex *new = (t_vertex *)malloc(sizeof(t_vertex));
    new->data = data;
    new->label = FRESH;
    new->ntoe = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->ntoe->edge = NULL;
    new->ntoe->next = NULL;
    new->next = NULL;
    return new;
}

// 정점을 리스트의 끝에 추가하는 함수
void addLast_vertex(t_vertex **head, int data) {
    t_vertex *new = init_vertex(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    t_vertex *last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
}

// 주어진 데이터를 가진 정점을 찾는 함수
t_vertex *find_vertex(t_vertex *node, int data) {
    while (node) {
        if (data == node->data)
            return node;
        node = node->next;
    }
    return NULL;
}

// 간선을 초기화하는 함수
t_edge *init_edge(t_vertex *v1, t_vertex *v2) {
    t_edge *new = (t_edge *)malloc(sizeof(t_edge));
    new->label = FRESH;
    new->v1 = v1;
    new->v2 = v2;
    new->next = NULL;
    return new;
}

// 간선을 리스트의 끝에 추가하는 함수
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2) {
    t_edge *new = init_edge(v1, v2);
    if (*head == NULL) {
        *head = new;
        return new;
    }
    t_edge *last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
    return new;
}

// 주어진 정점과 연결된 간선을 찾는 함수
t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2) {
    while (node) {
        if (node->v1 == v1 && node->v2 == v2)
            return node;
        if (node->v2 == v1 && node->v1 == v2)
            return node;
        node = node->next;
    }
    return NULL;
}

// 노드에서 간선으로의 연결을 초기화하는 함수
t_NtoE *init_NtoE(t_edge *edge) {
    t_NtoE *new = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->edge = edge;
    new->next = NULL;
    return new;
}

// 노드에서 간선으로의 연결을 추가하는 함수
void add_NtoE(t_NtoE *head, t_edge *edge, int data, int check) {
    t_NtoE *new = init_NtoE(edge);
    t_NtoE *prev = head;
    t_edge *p_edge = NULL;

    while (prev->next) {
        p_edge = prev->next->edge;
        if (p_edge->v1->data == data) {
            if (p_edge->v2->data > check)
                break;
        } else if (p_edge->v2->data == data) {
            if (p_edge->v1->data > check)
                break;
        }
        prev = prev->next;
    }
    new->next = prev->next;
    prev->next = new;
}

// 간선과 정점을 연결하여 반대편 정점을 반환하는 함수
t_vertex *opposite_vertex(t_edge *edge, int data) {
    if (edge->v1->data == data)
        return edge->v2;
    return edge->v1;
}

// 그래프를 생성하는 함수
void makeGraph(t_vertex **vertices, t_edge **edges, int n, int m) {
    int vnum1, vnum2;
    t_vertex *v1 = NULL, *v2 = NULL;
    t_edge *new = NULL;

    // 정점 추가
    for (int i = 1; i <= n; i++) {
        addLast_vertex(vertices, i);
    }

    // 간선 추가
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &vnum1, &vnum2);
        v1 = find_vertex(*vertices, vnum1);
        v2 = find_vertex(*vertices, vnum2);
        new = addLast_edge(edges, v1, v2);
        add_NtoE(v1->ntoe, new, v1->data, v2->data);
        if (vnum1 != vnum2)
            add_NtoE(v2->ntoe, new, v2->data, v1->data);
    }
}

// 깊이 우선 탐색을 수행하는 함수
void rDFS(t_vertex *v) {
    t_vertex *w = NULL;
    t_NtoE *ntoe = NULL;

    printf("%d\n", v->data);
    v->label = VISITED;
    ntoe = v->ntoe->next;
    while (ntoe) {
        if (ntoe->edge->label == FRESH) {
            w = opposite_vertex(ntoe->edge, v->data);
            if (w->label == FRESH) {
                ntoe->edge->label = TREE;
                rDFS(w);
            } else
                ntoe->edge->label = BACK;
        }
        ntoe = ntoe->next;
    }
}