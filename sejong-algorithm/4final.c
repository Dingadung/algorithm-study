#include <stdio.h>
#include <stdlib.h>

#define INF 2147483647

typedef struct s_vertex {
    int data;
    int distance;
    int visited;
    struct s_NtoE *ntoe;
    struct s_vertex *next;
} t_vertex;

typedef struct s_NtoE {
    struct s_edge *edge;
    struct s_NtoE *next;
} t_NtoE;

typedef struct s_edge {
    int weight;
    struct s_vertex *v1;
    struct s_vertex *v2;
    struct s_edge *next;
} t_edge;

t_vertex *queue[101];
int vn, vm, vs;
int n;

// vertex 초기화, 추가, 탐색 (header X)
t_vertex *init_vertex(int data);
t_vertex *addLast_vertex(t_vertex **head, int data);
t_vertex *find_vertex(t_vertex *node, int data);

// edge 초기화, 추가, 탐색 (header X)
t_edge *init_edge(t_vertex *v1, t_vertex *v2, int w);
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2, int w);
t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2);

// NtoE 초기화, 추가 (header O)
// NtoE는 추가할 때 node number 오름차순 정렬
t_NtoE *init_NtoE(t_edge *edge);
void add_NtoE(t_NtoE *head, t_edge *edge, int data, int check);

// 그래프 생성, cmd_a, cmd_d
void makeGraph(t_vertex **vertices, t_edge **edges);
void DijkstraShortestPaths(t_vertex **vertices, t_vertex *ver);

t_vertex *opposite_vertex(t_edge *edge, int data);
int check_include_queue(t_vertex *z);

//priority queue
void insertItem(t_vertex *ver);
t_vertex *removeMin(void);
void upHeap(int i);
void downHeap(int i);
void swap(int i, int j);

int main() {
    t_vertex *vertices = NULL;
    t_edge *edges = NULL;

    scanf("%d %d %d", &vn, &vm, &vs);
    makeGraph(&vertices, &edges);
    DijkstraShortestPaths(&vertices, find_vertex(vertices, vs));
    return (0);
}

void makeGraph(t_vertex **vertices, t_edge **edges) {
    int vnum1, vnum2, weight;
    t_vertex *v1 = NULL, *v2 = NULL, *newv = NULL;
    t_edge *new = NULL;

    for (int i = 1; i <= vn; i++) {
        newv = addLast_vertex(vertices, i);
        insertItem(newv);
    }

    for (int i = 0; i < vm; i++) {
        scanf("%d %d %d", &vnum1, &vnum2, &weight);
        v1 = find_vertex(*vertices, vnum1);
        v2 = find_vertex(*vertices, vnum2);
        new = addLast_edge(edges, v1, v2, weight);
        add_NtoE(v1->ntoe, new, v1->data, v2->data);
        if (vnum1 != vnum2)
            add_NtoE(v2->ntoe, new, v2->data, v1->data);
    }
}

void DijkstraShortestPaths(t_vertex **vertices, t_vertex *ver) {
    t_vertex *u, *z, *tmp;
    t_NtoE *ntoe;

    ver->distance = 0;
    ver->visited = 1;
    upHeap(check_include_queue(ver));

    while (n) {
        u = removeMin();
        u->visited = 1;
        ntoe = u->ntoe->next;
        while (ntoe) {
            z = opposite_vertex(ntoe->edge, u->data);
            if (check_include_queue(z)) {
                if (u->distance + ntoe->edge->weight < z->distance) {
                    z->distance = u->distance + ntoe->edge->weight;
                    upHeap(check_include_queue(z));
                }
            }
            ntoe = ntoe->next;
        }
    }

    tmp = *vertices;
    while (tmp) {
        if (tmp->visited && tmp != ver && tmp->distance != INF)
            printf(" %d %d\n", tmp->data, tmp->distance);
        tmp = tmp->next;
    }
}

t_vertex *init_vertex(int data) {
    t_vertex *new = NULL;

    new = (t_vertex *)malloc(sizeof(t_vertex));
    new->data = data;
    new->distance = INF;
    new->visited = 0;
    new->ntoe = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->ntoe->edge = NULL;
    new->ntoe->next = NULL;
    new->next = NULL;
    return (new);
}

t_vertex *addLast_vertex(t_vertex **head, int data) {
    t_vertex *new = NULL;
    t_vertex *last = NULL;

    new = init_vertex(data);
    if (*head == NULL) {
        *head = new;
        return new;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
    return new;
}

t_vertex *find_vertex(t_vertex *node, int data) {
    while (node) {
        if (data == node->data)
            return (node);
        node = node->next;
    }
    return (NULL);
}

t_edge *init_edge(t_vertex *v1, t_vertex *v2, int weight) {
    t_edge *new = NULL;

    new = (t_edge *)malloc(sizeof(t_edge));
    new->weight = weight;
    new->v1 = v1;
    new->v2 = v2;
    new->next = NULL;
    return (new);
}

t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2, int weight) {
    t_edge *new = NULL;
    t_edge *last = NULL;

    new = init_edge(v1, v2, weight);
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

t_vertex *opposite_vertex(t_edge *edge, int data) {
    if (edge->v1->data == data)
        return edge->v2;
    return edge->v1;
}

int check_include_queue(t_vertex *z) {
    for (int i = 1; i <= n; i++) {
        if (queue[i] == z)
            return i;
    }
    return 0;
}

void insertItem(t_vertex *ver) {
    n++;
    queue[n] = ver;
    upHeap(n);
}

t_vertex *removeMin(void) {
    t_vertex *ver;

    ver = queue[1];
    queue[1] = queue[n];
    n--;
    downHeap(1);
    return (ver);
}

void upHeap(int i) {
    int parent;
    int tmp;

    parent = i / 2;
    if (i == 1)
        return;
    if (queue[i]->distance > queue[parent]->distance)
        return;

    swap(i, parent);
    upHeap(parent);
}

void downHeap(int i) {
    int left, right;
    int smaller;

    left = i * 2;
    right = i * 2 + 1;

    if (left > n)
        return;
    smaller = left;
    if (right <= n) {
        if (queue[smaller]->distance > queue[right]->distance)
            smaller = right;
    }

    if (queue[i]->distance <= queue[smaller]->distance)
        return;

    swap(i, smaller);
    downHeap(smaller);
}

void swap(int i, int j) {
    t_vertex *tmp;

    tmp = queue[i];
    queue[i] = queue[j];
    queue[j] = tmp;
}