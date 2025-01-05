#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define NOSUCHKEY -1

typedef struct Node{
    int idx;
    int key;
    int height;
    struct Node *parent;
    struct Node *lChild;
    struct Node *rChild;
}Node;

typedef int bool; 

//AVL tree
void searchAndFixAfterInsertion(Node **root, Node *w, int h);
void searchAndFixAfterRemoval(Node **root, Node *w);
bool updateHeight(Node *node, int h);
bool isBalanced(Node *node);
Node *find_high_child(Node *node);
Node *restructure(Node *x, Node *y, Node *z, int height);
void check_abc(Node *x, Node *y, Node *z, Node *abc[3]);


Node *init_node(void);
Node *treeSearch(Node *node, int k);
void insertItem(Node **root, int k, int height);
int removeElement(Node **node, int k);
int findElement(Node *node, int k);
void preorder(Node *node);

void expandExternal(Node *node, int k);
Node *reduceExternal(Node **node, Node *z);
Node *inOrderSucc(Node *node);
Node *find_sibling(Node *z);

bool isExternal(Node *node);
bool isInternal(Node *node);
void preorder_h(Node *node);

int main(void)
{
    int key, h, N;
    Node *tree = NULL;
    scanf("%d", &N);
    tree = init_node();
    for(int i=0;i<N;i++) {
            scanf("%d %d", &key, &h);
            insertItem(&tree, key, h);
            tree->idx=i+1;
            printf("idx: %d\n", tree->idx);
    }
    preorder(tree);
    return 0;
}

//AVL tree
void searchAndFixAfterInsertion(Node **root, Node *w, int h){
    Node *x = NULL, *y = NULL, *z = w->parent;
    Node *b = NULL, *bp = NULL;
    
    updateHeight(z, h);
    while (isBalanced(z)){ //1.
        z = z->parent;
        updateHeight(z, h);
    }
    if (z == NULL) //갱신 필요 X
        return;
    
    bp = z->parent; // restructure 안에서 z의 부모가 바뀌기 때문에 미리 저장

    y = find_high_child(z); //2.
    x = find_high_child(y); //3.
    b = restructure(x, y, z, h); //4.
    
    b->parent = bp;
    if(bp == NULL)
        *root = b;
    else if(bp->lChild == z)
        bp->lChild = b;
    else
        bp->rChild = b;  
}

bool updateHeight(Node *node, int h){
    Node *c = NULL;
    
    if (!node) //NULL
        return FALSE;
    c = find_high_child(node);
    if (node->height == c->height + 1)
        return FALSE;
    node->height = h;
    return TRUE;
}

bool isBalanced(Node *node){
    int diff;

    if (!node) //NULL
        return FALSE;
    diff = (node->lChild)->height - (node->rChild)->height;
    if (-1 <= diff && diff <= 1)
        return TRUE;
    return FALSE;
}

Node *find_high_child(Node *node){
    if ((node->lChild)->height > (node->rChild)->height)
        return node->lChild;
    else if ((node->lChild)->height == (node->rChild)->height)
    {
        if (node->parent && (node->parent)->lChild == node)
            return node->lChild;
    }
    return node->rChild;
}

Node *restructure(Node *x, Node *y, Node *z, int h){
    Node *abc[3];
    Node *a, *b, *c;

    check_abc(x, y, z, abc);
    a = abc[0]; b = abc[1]; c = abc[2];
   
    updateHeight(a, h);
    updateHeight(c, h);

    a->parent = b;
    c->parent = b;
    b->lChild = a; 
    b->rChild = c;
    updateHeight(b, h);
    return b;
}

void check_abc(Node *x, Node *y, Node *z, Node *abc[3]){
    if (x->key > y->key && y->key > z->key){ //single
        y->lChild->parent = z;
        z->rChild = y->lChild;
        
        abc[0] = z; 
        abc[1] = y; 
        abc[2] = x;
    }
    else if (x->key < y->key && y->key < z->key){ //single
        y->rChild->parent = z;
        z->lChild = y->rChild;
        abc[0] = x; 
        abc[1] = y; 
        abc[2] = z;
    }
    else if (z->key < x->key && x->key < y->key){ //double
        x->lChild->parent = z;
        x->rChild->parent = y;
        z->rChild = x->lChild;
        y->lChild = x->rChild;
        abc[0] = z; 
        abc[1] = x; 
        abc[2] = y;
    }
    else if (y->key < x->key && x->key < z->key){ //double
        x->lChild->parent = y;
        x->rChild->parent = z;
        y->rChild = x->lChild;
        z->lChild = x->rChild;
        abc[0] = y; 
        abc[1] = x; 
        abc[2] = z;
    }
}

// void searchAndFixAfterRemoval(Node **root, Node *w){
//     Node *x = NULL, *y = NULL, *z = w->parent;
//     Node *b = NULL, *bp = NULL;
    
//     while (1){
//         updateHeight(z);
//         while (isBalanced(z)){ //1.
//             z = z->parent;
//             updateHeight(z);
//         }
//         if (z == NULL) //갱신 필요 X
//             return;

//         bp = z->parent; // restructure 안에서 z의 부모가 바뀌기 때문에 미리 저장

//         y = find_high_child(z); //2.
//         x = find_high_child(y); //3.
//         b = restructure(x, y, z); //4.

//         b->parent = bp;
//         if(bp == NULL)
//             *root = b;
//         else if(bp->lChild == z)
//             bp->lChild = b;
//         else
//             bp->rChild = b; 
//         z = bp;
//     }
// }

Node *init_node(void){
    Node *node = NULL;

    node = (Node *)malloc(sizeof(Node));
    node->key = 0;
    node->height = 0;
    node->parent = NULL;
    node->lChild = NULL;
    node->rChild = NULL;
    return node;
}
//binary search Node
Node *treeSearch(Node *node, int k){
    if (isExternal(node))
        return node;
    if (k == node->key)
        return node;
    else if (k < node->key)
        return treeSearch(node->lChild, k);
    else
        return treeSearch(node->rChild, k);
}

void insertItem(Node **root, int k, int h){
    Node *w = NULL;
    
    w = treeSearch(*root, k);
    if (isInternal(w))
        return ;
    expandExternal(w, k);
    searchAndFixAfterInsertion(root, w, h);
}

void expandExternal(Node *node, int k){
    node->key = k;
    node->height = 1;
    node->lChild = init_node();
    node->rChild = init_node();
    node->lChild->parent = node;
    node->rChild->parent = node;
    //node->lChild->height = 0; -> init_node()에서 진행
    //node->rChild->height = 0;
}

// int removeElement(Node **node, int k){
//     int e;
//     Node *w = NULL, *y = NULL, *z = NULL, *zs = NULL;
    
//     w = treeSearch(*node, k);
//     if (isExternal(w))
//         return k + NOSUCHKEY;
//     e = w->key;
//     z = w->lChild; 
//     if (!(isExternal(z))) //lChild가 있을 경우
//         z = w->rChild; 
//     if (isExternal(z)) //rChild가 없을 경우
//         zs = reduceExternal(node, z);
//     else{
//         y = inOrderSucc(w);
//         z = y->lChild;
//         w->key = y->key;
//         zs = reduceExternal(node, z);
//     }
//     searchAndFixAfterRemoval(node, zs);
//     return e;
// }

Node *reduceExternal(Node **node, Node *z){
    Node *w = NULL, *zs = NULL;

    w = z->parent;
    zs = find_sibling(z);
    if (w->parent == NULL){
        (*node) = zs;
        if (zs)
            zs->parent = NULL;
    }
    else {
		zs->parent = w->parent;
		if ((w->parent)->lChild == w) 
            (w->parent)->lChild = zs;
		else 
            (w->parent)->rChild = zs;
	}
    free(z);    
    free(w);
    return zs;
}

Node *inOrderSucc(Node *node){
    node = node->rChild;

    while (node->lChild && !isExternal(node->lChild))
        node = node->lChild;
    return node;
}

int findElement(Node *node, int k){
    Node *find = NULL;
    
    find = treeSearch(node, k);
    if (isExternal(find))
        return k + NOSUCHKEY;
    return k;
}

Node *find_sibling(Node *z) {
	if (z->parent == NULL) 
        return NULL;
	if ((z->parent)->lChild == z) 
        return (z->parent)->rChild; 
    return (z->parent)->lChild;
}

void preorder(Node *node) {
	if (isExternal(node))
        return ;
	printf("%d: %d\n", node->idx, node->key);
	preorder(node->lChild);
	preorder(node->rChild);
}

void preorder_h(Node *node) {
	if (isExternal(node))
        return ;
	printf(" %d", node->height);
	preorder_h(node->lChild);
	preorder_h(node->rChild);
}

bool isExternal(Node *node){
    if (node->lChild == NULL && node->rChild == NULL)
        return TRUE;
    return FALSE;
}

bool isInternal(Node *node){
    if (node->lChild || node->rChild)
        return TRUE;
    return FALSE;
}

/*
i 5
i 11
i 13
i 3 
i 6
i 1
i 8
i 7
i 2*/