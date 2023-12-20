#include <stdio.h>
#include <stdlib.h>

// 정점의 상태를 표현하는 열거형
typedef enum label{
    FRESH,
    VISITED,
    TREE,
    CROSS
} LABEL;

// 정점 구조체
typedef struct s_vertex{
    int data;
    LABEL label;
    struct s_vertex *next;
} t_vertex;

// 간선 구조체
typedef struct s_edge{
    LABEL label;
    struct s_vertex *v1;
    struct s_vertex *v2;
    struct s_edge *next;
} t_edge;

// BFS 수행 시 사용하는 리스트 구조체
typedef struct s_list{
    int level;
    struct s_vertex *v;
    struct s_list *next;
} t_list;

// 정점 초기화, 추가, 탐색 함수
t_vertex *init_vertex(int data);
void addLast_vertex(t_vertex **head, int data);
t_vertex *find_vertex(t_vertex *node, int data);

// 간선 초기화, 추가, 탐색 함수
t_edge *init_edge(t_vertex *v1, t_vertex *v2);
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2);

// 인접 행렬 초기화 및 출력 함수
void init_adjacency_matrix(t_edge ***matrix, int n);
void print_matrix(t_edge ***matrix, int n);

// BFS 수행 시 사용하는 리스트 초기화, 추가, 삭제 함수
t_list *init_list(t_vertex *v, int level);
void addLast_list(t_list **head, t_vertex *v, int level);
t_vertex *popLeft_list(t_list **head);

// BFS 알고리즘 함수
void BFS(t_vertex *v, t_edge ***matrix, int n);
t_vertex *opposite_vertex(t_edge *edge, int data);

// 그래프 생성 함수
void makeGraph(t_vertex **vertices, t_edge **edges, t_edge ***matrix, int n, int m);


int main() {
    int n, m, s;
    t_vertex *vertices = NULL; 
    t_edge *edges = NULL;
    t_edge ***matrix;
    
    // 사용자로부터 그래프 정보 입력 받기
    scanf("%d%d%d", &n, &m, &s);
    
    // 인접 행렬 할당 및 초기화
    matrix = (t_edge ***)malloc(sizeof(t_edge **) * (n + 1));
    for (int i = 1; i < n + 1; i++)
        matrix[i] = (t_edge **)malloc(sizeof(t_edge *) * (n + 1));

    // 그래프 생성 및 BFS 수행
    makeGraph(&vertices, &edges, matrix, n, m);
    BFS(find_vertex(vertices, s), matrix, n);
    
    // 할당 해제
    for (int i = 1; i < n + 1; i++)
        free(matrix[i]);
    free(matrix);
    return (0);
}

t_vertex *init_vertex(int data){
    // 새로운 정점을 생성하고 초기화
    t_vertex *new = NULL;

    new = (t_vertex *)malloc(sizeof(t_vertex));
    new->data = data;
    new->label = FRESH;
    new->next = NULL;
    return (new);
}

void addLast_vertex(t_vertex **head, int data)
{
    // 정점 리스트의 맨 뒤에 새로운 정점 추가
    t_vertex *new = NULL;
    t_vertex *last = NULL;

    new = init_vertex(data);
    if (*head == NULL){
        *head = new;
        return ;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
}

t_vertex *find_vertex(t_vertex *node, int data){
    // 주어진 데이터와 일치하는 정점을 찾아 반환
    while (node)
	{
	    if (data == node->data)
	        return (node);
	    node = node->next;
	}
	return (NULL);
}

t_edge *init_edge(t_vertex *v1, t_vertex *v2){
    // 새로운 간선을 생성하고 초기화
    t_edge *new = NULL;

    new = (t_edge *)malloc(sizeof(t_edge));
    new->label = FRESH;
    new->v1 = v1;
    new->v2 = v2;
    new->next = NULL;
    return (new);
}

t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2)
{
    // 간선 리스트의 맨 뒤에 새로운 간선 추가
    t_edge *new = NULL;
    t_edge *last = NULL;

    new = init_edge(v1, v2);
    if (*head == NULL){
        *head = new;
        return (new);
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
    return (new);
}

t_list *init_list(t_vertex *v, int level){
    // 새로운 리스트 노드를 생성하고 초기화
    t_list *new = NULL;

    new = (t_list *)malloc(sizeof(t_list));
    new->v = v;
    new->level = level;
    new->next = NULL;
    return (new);
}

void addLast_list(t_list **head, t_vertex *v, int level){
    // 리스트의 맨 뒤에 새로운 노드 추가
    t_list *new = NULL;
    t_list *last = NULL;

    new = init_list(v, level);
    if (*head == NULL){
        *head = new;
        return ;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
}

t_vertex *popLeft_list(t_list **head){
    // 리스트의 맨 앞에서 노드를 꺼내 반환
    t_list *delete = NULL;
    t_vertex *v = NULL;
    delete = *head;
    v = delete->v;
    (*head) = delete->next;
    return v;
}

void init_adjacency_matrix(t_edge ***matrix, int n){
    // 인접 행렬 초기화
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            matrix[i][j] = NULL;
        }
    }
}

t_vertex *opposite_vertex(t_edge *edge, int data){
    // 주어진 간선에서 주어진 데이터와 반대쪽에 위치한 정점을 반환
    if (edge->v1->data == data)
        return edge->v2;
    return edge->v1;
}

void makeGraph(t_vertex **vertices, t_edge **edges, t_edge ***matrix, int n, int m) {
    int vnum1, vnum2;
    t_vertex *v1 = NULL, *v2 = NULL;
    t_edge *new = NULL;
    
    // 인접 행렬 초기화
    init_adjacency_matrix(matrix, n);
	for (int i = 1; i <= n; i++) {
		addLast_vertex(vertices, i);
	}
    for (int i = 0; i < m; i++) {
        // 사용자로부터 간선 정보 입력 받기
        scanf("%d%d", &vnum1, &vnum2);
	    v1 = find_vertex(*vertices, vnum1);
	    v2 = find_vertex(*vertices, vnum2);
		new = addLast_edge(edges, v1, v2);
		matrix[vnum1][vnum2] = new;
		matrix[vnum2][vnum1] = new;
	}
}

void BFS(t_vertex *v, t_edge ***matrix, int n){
    t_vertex *w = NULL;
    t_list *list = NULL;
    int level = 0;

    // 시작 정점을 큐에 추가하고 방문 표시
    addLast_list(&list, v, 0);
    v->label = VISITED;

    // BFS 알고리즘 수행
    while (list){
        v = popLeft_list(&list);
        printf("%d\n", v->data);

        for (int i = 1; i <= n; i++){
            if (!(matrix[v->data][i]))
                continue ;
            if (matrix[v->data][i]->label == FRESH){
                w = opposite_vertex(matrix[v->data][i], v->data);
                if (w->label == FRESH){
                    // 발견한 정점을 큐에 추가하고 트리 간선으로 표시
                    matrix[v->data][i]->label = TREE;
                    w->label = VISITED;
                    addLast_list(&list, w, level + 1);
                }
                else   
                    matrix[v->data][i]->label = CROSS; // 교차 간선으로 표시
            }
        }
        level++;
    }
}

void print_matrix(t_edge ***matrix, int n){
    // 인접 행렬 출력 (디버깅 용도)
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (matrix[i][j] == NULL)
                printf(" -1");
            else if (matrix[i][j]->v1->data == i)
                printf(" %d", matrix[i][j]->v2->data);
            else
                printf(" %d", matrix[i][j]->v1->data);
        }
        printf("\n");
    }
}

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int n; // 정점의 개수
int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 인접 행렬
int visited[MAX_VERTICES]; // 방문한 정점 표시

// 큐 구현
int queue[MAX_VERTICES], front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1)
        printf("\nQueue is Full!!");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    if (front == -1)
        printf("\nQueue is Empty!!");
    else {
        int vertex = queue[front++];
        if (front > rear)
            front = rear = -1;
        return vertex;
    }
    return -1;
}

// BFS 구현
void BFS(int startVertex) {
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 1; i <= n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

// 그래프 초기화 및 간선 추가
void addEdge(int v1, int v2) {
    adjMatrix[v1][v2] = 1;
    adjMatrix[v2][v1] = 1; // 무방향 간선
}

int main() {
    int m, startVertex; // 간선의 개수, 시작 정점
    scanf("%d %d %d", &n, &m, &startVertex);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
    }

    BFS(startVertex); // 시작 정점에서 BFS 수행
    return 0;
}
*/