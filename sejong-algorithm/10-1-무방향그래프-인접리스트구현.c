// 무방향 그래프
// 인접리스트 구현

#include <stdio.h>
#include <stdlib.h>

// 정점을 나타내는 구조체
typedef struct s_vertex {
    int data;
    struct s_NtoE *ntoe; // 인접 간선을 나타내는 연결리스트의 헤드
    struct s_vertex *next; // 다음 정점을 가리키는 포인터
} t_vertex;

// 인접 간선을 나타내는 구조체
typedef struct s_NtoE {
    struct s_edge *edge; // 간선을 가리키는 포인터
    struct s_NtoE *next; // 다음 인접 간선을 가리키는 포인터
} t_NtoE;

// 간선을 나타내는 구조체
typedef struct s_edge {
    int weight;
    struct s_vertex *v1;
    struct s_vertex *v2;
    struct s_edge *next; // 다음 간선을 가리키는 포인터
} t_edge;

// 정점 초기화, 추가, 탐색 (헤더 없음)
t_vertex *init_vertex(int data);
void addLast_vertex(t_vertex **head, int data);
t_vertex *find_vertex(t_vertex *node, int data);

// 간선 초기화, 추가, 탐색 (헤더 없음)
t_edge *init_edge(t_vertex *v1, t_vertex *v2, int w);
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2, int w);
t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2);

// 인접 간선 초기화, 추가 (헤더 있음)
// 인접 간선은 추가할 때 노드 번호 오름차순으로 정렬
t_NtoE *init_NtoE(t_edge *edge);
void add_NtoE(t_NtoE *head, t_edge *edge, int data, int check);

// 그래프 생성, cmd_a, cmd_d
void makeGraph(int info[8][3], t_vertex **vertices, t_edge **edges);
void print_NtoE(t_vertex *head, int data);
void update_edge(t_vertex *vertices, t_edge **edges, int vnum1, int vnum2, int w);
void delete_NtoE(t_edge *edge, t_NtoE *head);
void delete_edge(t_edge **head, t_vertex *v1, t_vertex *v2);

int main() {
    char cmd;
    int data, v1, v2, w;
    t_vertex *vertices = NULL;
    t_edge *edges = NULL;
    int info[8][3] = {{1, 1, 2}, {1, 1, 3}, {1, 1, 4}, {2, 1, 6}, {1, 2, 3}, {4, 3, 5}, {4, 5, 5}, {3, 5, 6}};

    makeGraph(info, &vertices, &edges);
    while (1) {
        scanf("%c", &cmd);
        getchar();
        if (cmd == 'a') {
            scanf("%d", &data);
            getchar();
            print_NtoE(vertices, data);
        } else if (cmd == 'm') {
            scanf("%d %d %d", &v1, &v2, &w);
            getchar();
            update_edge(vertices, &edges, v1, v2, w);
        } else if (cmd == 'q')
            break;
    }
    return (0);
}

t_vertex *init_vertex(int data) {
    t_vertex *new = NULL;

    new = (t_vertex *)malloc(sizeof(t_vertex));
    new->data = data;
    new->ntoe = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->ntoe->edge = NULL;
    new->ntoe->next = NULL;
    new->next = NULL;
    return (new);
}

void addLast_vertex(t_vertex **head, int data) {
    t_vertex *new = NULL;
    t_vertex *last = NULL;

    new = init_vertex(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
}

t_vertex *find_vertex(t_vertex *node, int data) {
    while (node) {
        if (data == node->data)
            return (node);
        node = node->next;
    }
    return (NULL);
}

t_edge *init_edge(t_vertex *v1, t_vertex *v2, int w) {
    t_edge *new = NULL;

    new = (t_edge *)malloc(sizeof(t_edge));
    new->weight = w;
    new->v1 = v1;
    new->v2 = v2;
    new->next = NULL;
    return (new);
}

t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2, int w) {
    t_edge *new = NULL;
    t_edge *last = NULL;

    new = init_edge(v1, v2, w);
    if (*head == NULL) {
        *head = new;
        return (new);
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
    return (new);
}

t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2) {
    while (node) {
        if (node->v1 == v1 && node->v2 == v2)
            return (node);
        if (node->v2 == v1 && node->v1 == v2)
            return (node);
        node = node->next;
    }
    return (NULL);
}

t_NtoE *init_NtoE(t_edge *edge) {
    t_NtoE *new = NULL;

    new = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->edge = edge;
    new->next = NULL;
    return (new);
}

void add_NtoE(t_NtoE *head, t_edge *edge, int data, int check) {
    t_NtoE *new = NULL;
    t_NtoE *prev = NULL;
    t_edge *p_edge = NULL;

    new = init_NtoE(edge);
    prev = head;
    /*
    p_edge->v1->data 또는 p_edge->v2->data가 check보다 큰 경우, 새 간선은 현재 간선 바로 전에 삽입되어야 합니다. 이것은 정점 번호의 오름차순 순서를 유지하기 위한 것입니다.*/
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

void makeGraph(int info[8][3], t_vertex **vertices, t_edge **edges) {
    t_vertex *v1 = NULL, *v2 = NULL;
    t_edge *new = NULL;

    for (int i = 1; i <= 6; i++) {
        addLast_vertex(vertices, i);
    }

    for (int i = 0; i < 8; i++) {
        v1 = find_vertex(*vertices, info[i][1]);
        v2 = find_vertex(*vertices, info[i][2]);
        new = addLast_edge(edges, v1, v2, info[i][0]);
        add_NtoE(v1->ntoe, new, v1->data, v2->data);
        if (info[i][1] != info[i][2])
            add_NtoE(v2->ntoe, new, v2->data, v1->data);
    }
}

void print_NtoE(t_vertex *head, int data) {
    t_NtoE *ntoe = NULL;
    t_vertex *v = find_vertex(head, data);

    if (v == NULL) {
        printf("-1\n");
        return;
    }

    ntoe = v->ntoe->next;
    while (ntoe) {
        if (ntoe->edge->v1->data == data)
            printf(" %d %d", ntoe->edge->v2->data, ntoe->edge->weight);
        else if (ntoe->edge->v2->data == data)
            printf(" %d %d", ntoe->edge->v1->data, ntoe->edge->weight);
        ntoe = ntoe->next;
    }
    printf("\n");
}

void update_edge(t_vertex *vertices, t_edge **edges, int vnum1, int vnum2, int w) {
    t_vertex *v1 = NULL, *v2 = NULL;
    t_edge *edge = NULL, *new = NULL;

    v1 = find_vertex(vertices, vnum1);
    v2 = find_vertex(vertices, vnum2);
    if (v1 == NULL || v2 == NULL) {
        printf("-1\n");
        return;
    }
    edge = find_edge(*edges, v1, v2);
    if (edge) {
        if (w == 0) {
            delete_NtoE(edge, v1->ntoe);
            if (vnum1 != vnum2)
                delete_NtoE(edge, v2->ntoe);
            delete_edge(edges, v1, v2);
        } else
            edge->weight = w;
        return;
    }
    if (w != 0) {
        new = addLast_edge(edges, v1, v2, w);
        add_NtoE(v1->ntoe, new, v1->data, v2->data);
        if (vnum1 != vnum2)
            add_NtoE(v2->ntoe, new, v2->data, v1->data);
    }
}

void delete_NtoE(t_edge *edge, t_NtoE *head) {
    t_NtoE *prev = NULL;
    t_NtoE *delete = NULL;

    prev = head;
    while (prev->next) {
        if (prev->next->edge == edge) {
            delete = prev->next;
            break;
        }
        prev = prev->next;
    }
    if (delete) {
        prev->next = delete->next;
        free(delete);
    }
}

void delete_edge(t_edge **head, t_vertex *v1, t_vertex *v2) {
    t_edge *prev = NULL;
    t_edge *delete = NULL;

    delete = *head;
    while (delete) {
        if (delete->v1 == v1 && delete->v2 == v2)
            break;
        if (delete->v2 == v1 && delete->v1 == v2)
            break;
        prev = delete;
        delete = delete->next;
    }
    if (prev)
        prev->next = delete->next;
    else
        (*head) = delete->next;
    free(delete);
}