#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int n; // 정점의 개수
int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 인접 행렬
int visited[MAX_VERTICES]; // 방문한 정점 표시

// DFS 구현
void DFS(int v) {
    visited[v] = 1; // 정점 v를 방문했다고 표시
    printf("%d ", v);

    for (int i = 1; i <= n; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) { // 인접하고 아직 방문하지 않은 정점
            DFS(i);
        }
    }
}

// 그래프 초기화 및 간선 추가
void addEdge(int v1, int v2) {
    adjMatrix[v1][v2] = 1;
    adjMatrix[v2][v1] = 1; // 무방향 간선
}

int main() {
    int m, s; // 간선의 개수, 시작 정점
    scanf("%d %d %d", &n, &m, &s);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
    }

    DFS(s); // 시작 정점에서 DFS 수행
    return 0;
}
