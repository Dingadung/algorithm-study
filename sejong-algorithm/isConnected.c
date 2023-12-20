#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numVertices;
    int **adjMatrix;
} Graph;

void DFS(Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int isConnected(Graph *graph) {
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // 시작 정점에서 DFS 수행
    DFS(graph, 0, visited);

    // 모든 정점을 방문했는지 확인
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            free(visited);
            return 0; // 연결되지 않은 정점 발견
        }
    }

    free(visited);
    return 1; // 모든 정점이 연결됨
}

int main() {
    // 그래프 생성 및 초기화
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5; // 예시로 5개의 정점을 가정
    graph->adjMatrix = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++) {
        graph->adjMatrix[i] = (int *)malloc(5 * sizeof(int));
        for (int j = 0; j < 5; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    // 간선 추가 예시
    graph->adjMatrix[0][1] = 1;
    graph->adjMatrix[1][0] = 1;
    // 다른 간선 추가

    // 연결성 검사
    if (isConnected(graph)) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }

    // 할당 해제
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}
