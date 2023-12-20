/*
Floyd-Warshall 알고리즘은 그래프의 모든 정점 쌍에 대한 최단 경로를 찾는 알고리즘입니다. 
이 알고리즘은 그래프의 이행적 폐쇄(Transitive Closure)를 계산할 때에도 사용될 수 있습니다. 
이행적 폐쇄는 그래프의 어떤 정점에서 다른 정점으로 도달 가능한지 여부를 나타냅니다.

이 코드는 정점의 개수가 4개인 그래프에 대해 Floyd-Warshall 알고리즘을 사용하여 이행적 폐쇄를 계산합니다. 
graph[][]는 그래프의 인접 행렬을 나타내며, reach[][]는 이행적 폐쇄를 저장하는 행렬입니다. 알고리즘이 실행된 후 reach[i][j]가 1이면 정점 i에서 j로 가는 경로가 존재한다는 것을 의미합니다.

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 99999

// Floyd-Warshall 알고리즘을 사용한 이행적 폐쇄 계산
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int reach[MAX_VERTICES][MAX_VERTICES], i, j, k;

    // reach 행렬 초기화
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            reach[i][j] = graph[i][j];

    // k를 거쳐가는 모든 정점 쌍에 대해 최단 경로 계산
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // i에서 j로 가는 경로가 존재하거나, i에서 k를 거쳐 j로 가는 경로가 존재하면
                if (reach[i][k] && reach[k][j])
                    reach[i][j] = 1;
            }
        }
    }

    // 결과 출력
    printf("Transitive closure of the given graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    int n = 4; // 정점의 개수

    floydWarshall(graph, n);

    return 0;
}
