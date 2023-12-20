// 무방향 그래프
// 인접행렬 구현

#include <stdio.h>
#include <stdlib.h>

typedef struct s_vertex{
    int data;
    struct s_vertex *next;
}t_vertex;

typedef struct s_edge{
    int weight;
    struct s_vertex *v1;
    struct s_vertex *v2;
    struct s_edge *next;
}t_edge;

// vertice 초기화, 추가, 탐색 (header X)
t_vertex *init_vertex(int data);
void addLast_vertex(t_vertex **head, int data);
t_vertex *find_vertex(t_vertex *node, int data);

// edge 초기화, 추가, 탐색 (header X)
t_edge *init_edge(t_vertex *v1, t_vertex *v2, int w);
t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2, int w);

void init_adjacency_matrix(t_edge *matrix[7][7]);

// 그래프 생성, cmd_a, cmd_d
void makeGraph(int info[8][3], t_vertex **vertices, t_edge **edges, t_edge *matrix[7][7]);
void print_adjacency_matrix(t_vertex *head, int data, t_edge *matrix[7][7]);
void update_edge(t_vertex *vertices, t_edge **edges, int vnum1, int vnum2, int w, t_edge *matrix[7][7]);
void delete_edge(t_edge **head, t_vertex *v1, t_vertex *v2);


int main() {
    char cmd;
	int data, v1, v2, w;
    t_vertex *vertices = NULL; 
    t_edge *edges = NULL;
    t_edge *matrix[7][7];
	int info[8][3] = {{1,1,2},{1,1,3},{1,1,4},{2,1,6},{1,2,3},{4,3,5},{4,5,5},{3,5,6}};
    
    makeGraph(info, &vertices, &edges, matrix);
	while (1) {
		scanf("%c", &cmd); getchar();
		if (cmd == 'a') {
			scanf("%d", &data); getchar();
			print_adjacency_matrix(vertices, data, matrix);
		}
		else if (cmd == 'm'){
		    scanf("%d %d %d", &v1, &v2, &w); getchar();
		    update_edge(vertices, &edges, v1, v2, w, matrix);
		}
		else if (cmd == 'q') 
		    break;
	}
	return (0);
}

t_vertex *init_vertex(int data){
    t_vertex *new = NULL;

    new = (t_vertex *)malloc(sizeof(t_vertex));
    new->data = data;
    new->next = NULL;
    return (new);
}

void addLast_vertex(t_vertex **head, int data)
{
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
    while (node)
	{
	    if (data == node->data)
	        return (node);
	    node = node->next;
	}
	return (NULL);
}


t_edge *init_edge(t_vertex *v1, t_vertex *v2, int w){
    t_edge *new = NULL;

    new = (t_edge *)malloc(sizeof(t_edge));
    new->weight = w;
    new->v1 = v1;
    new->v2 = v2;
    new->next = NULL;
    return (new);
}

t_edge *addLast_edge(t_edge **head, t_vertex *v1, t_vertex *v2, int w)
{
    t_edge *new = NULL;
    t_edge *last = NULL;

    new = init_edge(v1, v2, w);
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



void init_adjacency_matrix(t_edge *matrix[7][7]){
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            matrix[i][j] = NULL;
        }
    }
}


void makeGraph(int info[8][3], t_vertex **vertices, t_edge **edges, t_edge *matrix[7][7]) {
    t_vertex *v1 = NULL, *v2 = NULL;
    t_edge *new = NULL;
    
    init_adjacency_matrix(matrix);

	for (int i = 1; i <= 6; i++) {
		addLast_vertex(vertices, i);
	}
	
	for (int i = 0; i < 8; i++) {
	    v1 = find_vertex(*vertices, info[i][1]);
	    v2 = find_vertex(*vertices, info[i][2]);
		new = addLast_edge(edges, v1, v2, info[i][0]);
        matrix[info[i][1]][info[i][2]] = new;
		matrix[info[i][2]][info[i][1]] = new;
	}
}

void print_adjacency_matrix(t_vertex *head, int data, t_edge *matrix[7][7]){
    t_vertex *v = find_vertex(head, data);
    t_edge *edge = NULL;
    
    if (v == NULL){
        printf("-1\n");
        return ;
    }
    for (int i = 1; i <= 6; i++){
        edge = matrix[data][i];
        if (!edge)
            continue ;
        if (edge->v1->data == data)
            printf(" %d %d", edge->v2->data, edge->weight);
        else if (edge->v2->data == data)
            printf(" %d %d", edge->v1->data, edge->weight);
    }
    printf("\n");
}

void update_edge(t_vertex *vertices, t_edge **edges, int vnum1, int vnum2, int w, t_edge *matrix[7][7]){
    t_vertex *v1 = NULL, *v2 = NULL;
    t_edge *edge = NULL, *new = NULL;
    
    v1 = find_vertex(vertices, vnum1);
	v2 = find_vertex(vertices, vnum2);
	if (v1 == NULL || v2 == NULL){
	    printf("-1\n");
	    return ;
	}
    edge = matrix[vnum1][vnum2];
    if (edge){
        if (w == 0){
            matrix[vnum1][vnum2] = NULL;
            matrix[vnum2][vnum1] = NULL;
	        delete_edge(edges, v1, v2);
        }
        else
            edge->weight = w;
        return ;
    }
    if (w != 0){
        new = addLast_edge(edges, v1, v2, w);
	    matrix[vnum1][vnum2] = new;
		matrix[vnum2][vnum1] = new;
    }
}

void delete_edge(t_edge **head, t_vertex *v1, t_vertex *v2){
    t_edge *prev = NULL;
    t_edge *delete = NULL;
    
    delete = *head;
    while (delete){
        if (delete->v1 == v1 && delete->v2 == v2)
            break ;
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