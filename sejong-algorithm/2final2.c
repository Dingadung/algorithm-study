#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

# define NONE -1

typedef struct NODE {
	int data;
	int distance;
}NODE;

typedef struct EDGE {
	int weight;
	NODE *node;
	NODE *pointedNode;
}EDGE;

typedef struct Queue {
	NODE *data;
	struct Queue *prev;
	struct Queue *next;
}Q;

void getQ(Q **t) {
	(*t) = (Q *)malloc(sizeof(Q));
}

void getNode(NODE **ver, int data) {
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	tmp->data = data;
	tmp->distance = -1;
	(*ver) = tmp;
}

void getEdge(EDGE* mat[][100], NODE *n1, NODE *n2, int w) {
	EDGE *tmp = (EDGE *)malloc(sizeof(EDGE));
	tmp->weight = w;
	tmp->node = n1;
	tmp->pointedNode = n2;
	mat[n1->data - 1][n2->data - 1] = tmp;
}

NODE *findNode(NODE **ver, int data, int n) {
	for (int i = 0; i < n; i++) {
		if (ver[i]->data == data) return ver[i];
	}
	return NULL;
}

void buildGraph(NODE **ver, EDGE* mat[][100], int *n, int *m) {
	int i, j;
	int n1, n2, w;
	NODE *v1, *v2;
	scanf("%d %d", n, m);
    
    //EDGE init
	for (i = 0; i < (*n); i++) {
		for (j = 0; j < (*n); j++) {
			mat[i][j] = NULL;
		}
	}
    //NODE init(0번째에 1번 저장)
	for (i = 0; i < (*n); i++) {
		getNode(ver + i, i + 1);
	}

    //ver1, ver2, weight input
	for (i = 0; i < (*m); i++) {
		scanf("%d %d %d", &n1, &n2, &w);
		v1 = findNode(ver, n1, *n);
		v2 = findNode(ver, n2, *n);
		getEdge(mat, v1, v2, w);
		getEdge(mat, v2, v1, w);
	}
}

void enqueue(Q **front, Q **rear, NODE *v) {
	Q *tmp = NULL;
	getQ(&tmp);
	tmp->data = v;
	tmp->next = NULL;
	if ((*front) == NULL) {
		(*front) = tmp;
		tmp->prev = NULL;
	}
	else {
		(*rear)->next = tmp;
		tmp->prev = (*rear);
	}
	(*rear) = tmp;
}

NODE *removeMin(Q **front, Q **rear) {
	Q *min = (*front), *tmp = (*front)->next;
	NODE *m = NULL;
	while (tmp != NULL) {
		if (tmp->data->distance <= min->data->distance) {
			min = tmp;
		}
		tmp = tmp->next;
	}
	if (min->next != NULL) min->next->prev = min->prev;
	else (*rear) = (*rear)->prev;
	if (min->prev != NULL) min->prev->next = min->next;
	else (*front) = (*front)->next;
	m = min->data;
	free(min);
	return m;
}

Q *inhere(Q *front, NODE *tmp) {
	while (front != NULL) {
		if (front->data == tmp) return front;
		front = front->next;
	}
	return NULL;
}

int PrimJarnikMST(NODE **ver, EDGE* mat[][100], int n) {
	int j, total = 0;
	NODE *u = NULL, *opposite = NULL;
	Q *front = NULL, *rear = NULL, *tmp2 = NULL;

    //first -> 1(0번에 저장되어 있음)
	ver[0]->distance = 0;
	enqueue(&front, &rear, ver[0]);
	while (front != NULL) {
		u = removeMin(&front, &rear);
		printf(" %d", u->data);
        total += u->distance;
		j = (u->data) - 1;
		for (int i = 0; i < n; i++) {
			if (mat[j][i] == NULL) 
                continue;
			opposite = mat[j][i]->pointedNode;
			if (opposite->distance == NONE) {
				opposite->distance = mat[j][i]->weight;
				enqueue(&front, &rear, opposite);
			}
			else if (inhere(front, opposite)) {
				if (mat[j][i]->weight < opposite->distance) {
					opposite->distance = mat[j][i]->weight;
				}
			}
			mat[j][i] = NULL;
			mat[i][j] = NULL;
		}
	}
    return total;
}

int main() {
	int n, m, i, j, total_weight = 0;
	NODE *ver[100];
	EDGE* mat[100][100];

	buildGraph(ver, mat, &n, &m);
	total_weight = PrimJarnikMST(ver, mat, n);
	printf("\n%d", total_weight);
}