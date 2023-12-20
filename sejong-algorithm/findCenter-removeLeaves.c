#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int vertex;
    struct ListNode *next;
} ListNode;

typedef struct {
    int numVertices;
    ListNode **adjLists;
    int *visited;
} Graph;

// DFS를 사용하여 잎 노드를 찾아 제거하는 함수
void removeLeaves(Graph *graph, int vertex, int parent) {
    graph->visited[vertex] = 1;

    ListNode *current = graph->adjLists[vertex];
    int isLeaf = 1;

    while (current != NULL) {
        if (!graph->visited[current->vertex]) {
            isLeaf = 0;
            removeLeaves(graph, current->vertex, vertex);
        }
        current = current->next;
    }

    if (isLeaf && parent != -1) {
        // 잎 노드를 부모 노드의 인접 리스트에서 제거
        ListNode *prev = NULL;
        current = graph->adjLists[parent];
        while (current != NULL && current->vertex != vertex) {
            prev = current;
            current = current->next;
        }
        if (current != NULL) {
            if (prev == NULL) graph->adjLists[parent] = current->next;
            else prev->next = current->next;
            free(current);
        }
    }
}

// 자유 트리의 중심을 찾는 함수
void findCenter(Graph *graph) {
    // 모든 정점에 대해 DFS 수행
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            removeLeaves(graph, i, -1);
        }
    }

    // 중심 정점 출력
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjLists[i] != NULL) {
            printf("Center of the tree is: %d\n", i);
        }
    }
}

int main() {
    // 그래프 생성 및 초기화
    // 이 부분은 그래프의 정점과 간선을 추가하는 코드로 채워야 합니다.
    // 예: Graph *graph = createGraph(노드 수);
    //     addEdge(graph, v1, v2); (간선 추가)

    findCenter(graph);

    // 메모리 해제 및 기타 정리 작업
    // ...

    return 0;
}
