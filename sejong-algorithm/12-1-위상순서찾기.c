/*
- 강연결 - 각 하나의 정점으로부터 모든 접점 도달
O(n+m)
- 이행적 폐쇄: FloydWarshall -> v != u 인 방향경로가 있으면, 직선 경로 존재
- 동적프로그래밍
- 방향 비싸이클 그래프(DAG): 방향 싸이클이 존재하지 않는 방향 그래프
방향그래프가 DAG이면, 위상 순서를 가지며 그 역도 참이다.
    - 방향 그래프 내 정점들의 진입차수 이용
    - DFS 특화 -> 방향 싸이클 조사 불가
*/

#include <stdio.h>
#include <stdlib.h>

# define NONDAG 'N'
# define DAG 'Y'

typedef struct s_vertex{
    int num;
    int indegree;
    char name;
    struct s_NtoE *ntoe;
    struct s_vertex *next;
}t_vertex;

typedef struct s_NtoE{
    struct s_edge *edge;
    struct s_NtoE *next;
}t_NtoE;

typedef struct s_edge{
    struct s_vertex *v1;
    struct s_vertex *v2;
    struct s_edge *next;
}t_edge;

typedef struct s_node{
    struct s_vertex *v;
    struct s_node *next;
}t_node;

// vertex 초기화, 추가, 탐색 (header X)
t_vertex *init_vertex(char name, int num);
void addLast_vertex(t_vertex **head, char , int num);
t_vertex *find_vertex(t_vertex *node, char name);
t_vertex *opposite_vertex(t_edge *edge, char name);

// edge 초기화, 추가, 탐색 (header X)
t_edge *init_edge(t_vertex *v1, t_vertex *v2);
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2);
t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2);

// NtoE 초기화, 추가 (header O)
t_NtoE *init_NtoE(t_edge *edge);
void add_NtoE(t_NtoE *head, t_edge *edge, char name);

// queue
t_node *init_node(t_vertex *v);
void enqueue(t_node **queue, t_vertex *v);
t_vertex *dequeue(t_node **queue);

void buildGraph(t_vertex **vertices, t_edge **edges);
void topologicalSort(t_vertex *head, char *topOrder);

int n, m;

int main() {
    t_vertex *vertices = NULL;
    t_edge *edges = NULL;
    char *topOrder = NULL;

    buildGraph(&vertices, &edges);
    topOrder = (char *)malloc(sizeof(char) * (n + 1));
    topologicalSort(vertices, topOrder);
    if (topOrder[0] == NONDAG)
        printf("0\n");
    else{
        for (int i = 1; i <=n; i++)
            printf(" %c", topOrder[i]);
        printf("\n");
    }
	return (0);
}

void topologicalSort(t_vertex *head, char *topOrder)
{
    int order = 1;
    t_node *queue = NULL;
    t_vertex *ver, *w;
    t_NtoE *ntoe;

    ver = head;
    while (ver){
        if (ver->indegree == 0)
            enqueue(&queue, ver);
        ver = ver->next;
    }

    while (queue){
        ver = dequeue(&queue);
        topOrder[order] = ver->name;
        order++;
        ntoe = ver->ntoe->next;
        while(ntoe){
            w = opposite_vertex(ntoe->edge, ver->name);
            w->indegree--;
            if (w->indegree == 0)
                enqueue(&queue, w);
            ntoe = ntoe->next;
        }
    }
    if (order <= n)
        topOrder[0] = NONDAG;
    else
        topOrder[0] = DAG;
}

void buildGraph(t_vertex **vertices, t_edge **edges){
    char vName, wName;
    t_vertex *v = NULL, *w = NULL;
    t_edge *new = NULL;

    // n: 정점 수
    scanf("%d", &n); getchar();
	for (int i = 1; i <= n; i++) {
        // 정점들의 이름
        scanf("%c", &vName); getchar();
		addLast_vertex(vertices, vName, i);
	}
	
    // 방향 간선 수
    scanf("%d", &m); getchar();
	for (int i = 0; i < m; i++) {
        scanf("%c %c", &vName, &wName); getchar();
	    v = find_vertex(*vertices, vName);
	    w = find_vertex(*vertices, wName);
		new = addLast_edge(edges, v, w);
		add_NtoE(v->ntoe, new, v->name);
        w->indegree++;
    }
}



t_vertex *init_vertex(char name, int num){
    t_vertex *new = NULL;

    new = (t_vertex *)malloc(sizeof(t_vertex));
    new->num = num;
    new->name = name;
    new->indegree = 0;
    new->ntoe = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->ntoe->edge = NULL;
    new->ntoe->next = NULL;
    new->next = NULL;
    return (new);
}

void addLast_vertex(t_vertex **head, char name, int num)
{
    t_vertex *new = NULL;
    t_vertex *last = NULL;

    new = init_vertex(name, num);
    if (*head == NULL){
        *head = new;
        return ;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new;
}

t_vertex *find_vertex(t_vertex *node, char name){
    while (node)
	{
	    if (name == node->name)
	        return (node);
	    node = node->next;
	}
	return (NULL);
}

t_vertex *opposite_vertex(t_edge *edge, char name){
    if (edge->v1->name == name)
        return edge->v2;
    return edge->v1;
}


t_edge *init_edge(t_vertex *v1, t_vertex *v2){
    t_edge *new = NULL;

    new = (t_edge *)malloc(sizeof(t_edge));
    new->v1 = v1;
    new->v2 = v2;
    new->next = NULL;
    return (new);
}

t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2)
{
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

t_edge *find_edge(t_edge *node, t_vertex *v1, t_vertex *v2){
    while (node)
	{
	    if (node->v1 == v1 && node->v2 == v2)
	        return (node);
	    if (node->v2 == v1 && node->v1 == v2)
	        return (node);
	    node = node->next;
	}
	return (NULL);
}


t_NtoE *init_NtoE(t_edge *edge){
    t_NtoE *new = NULL;

    new = (t_NtoE *)malloc(sizeof(t_NtoE));
    new->edge = edge;
    new->next = NULL;
    return (new);
}

void add_NtoE(t_NtoE *head, t_edge *edge, char name)
{
    t_NtoE *new = NULL;
    t_NtoE *prev = NULL;
    t_edge *p_edge = NULL;

    new = init_NtoE(edge);
    prev = head;
    new->next = prev->next;
    prev->next = new;
}

t_node *init_node(t_vertex *v){
    t_node *new = NULL;

    new = (t_node *)malloc(sizeof(t_node));
    new->v = v;
    new->next = NULL;
    return (new);
}

void enqueue(t_node **queue, t_vertex *v){
    t_node *new = NULL;
    t_node *last = NULL;

    new = init_node(v);
    if (*queue == NULL){
        *queue = new;
        return ;
    }
    last = *queue;
    while (last->next)
        last = last->next;
    last->next = new;
}

t_vertex *dequeue(t_node **queue){
    t_node *delete = NULL;
    t_vertex *v = NULL;
    delete = *queue;
    v = delete->v;
    (*queue) = delete->next;
    return v;
}