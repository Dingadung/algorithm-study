#include <stdio.h>
#include <stdlib.h>

typedef struct s_listNode {
    int vertex;
    struct s_listNode *next;
} ListNode;

typedef struct {
    ListNode *head;
} AdjList;

typedef struct {
    int numVertices;
    AdjList *array;
} Graph;

// 큐 관련 구조체 및 함수
typedef struct {
    int items[100];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->items[++q->front];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// 그래프 관련 함수
Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->array = (AdjList *)malloc(vertices * sizeof(AdjList));

    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    // src에서 dest로의 간선 추가
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->vertex = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // 무방향 그래프의 경우, dest에서 src로의 간선도 추가
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->vertex = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void BFS(Graph *graph, int startVertex) {
    Queue q;
    q.front = q.rear = -1;

    int visited[100] = {0};

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("Visited %d\n", currentVertex);

        ListNode *temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->vertex;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    BFS(graph, 2); // 시작 정점 2에서 BFS 수행

    return 0;
}
