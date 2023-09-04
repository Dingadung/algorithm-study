#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct treeNode
{
    struct treeNode* left;
    int data;
    struct treeNode* right;
}treeNode;

treeNode* node;

treeNode* makeRootNode(treeNode* root, int data) {
    treeNode* newNode;
    if (root == NULL) {
    newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
    }
    return NULL;
}

void addLeftchild(treeNode* parent, int data) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    parent->left = newNode;
}

void addRightchild(treeNode* parent, int data) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    parent->right = newNode;
}

treeNode* addNode(treeNode* root, int leftData, int rightData) {
    if (leftData != 0) addLeftchild(root, leftData);
    if (rightData != 0) addRightchild(root, rightData);
    return root;
}

/*전위순회*/
void preorder(treeNode* root, int value) {
    if (root)
    {
        if (value == root->data)
            node = root;
        preorder(root->left, value);
        preorder(root->right, value);
    }
}


void search(treeNode* root, int id) {
    if (root)
    {
        if (root->data == id)
        {
            preorder(root, id);
        }
        else
        {
            search(root->left, id);
            search(root->right, id);
        }
    }
}





int main() {
    treeNode* root = NULL;
    treeNode* A = NULL;

    int id = 0, childLeft = 0, childRight = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &childLeft, &childRight);
        getchar();
        if (i == 0)
        {
            root = makeRootNode(root, id);
            addNode(root, childLeft, childRight);
        }
        else
        {
            search(root, id);
            addNode(node, childLeft, childRight);
        }
    }

    int cnt; // 탐색 횟수
    char str[100];
    int idx=0;
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) {
        scanf("%s", str);
        getchar();

        idx = 0;
        A = root;
        printf("%d", A->data);

        while (str[idx])
        {
            if (str[idx] == 'R')
            {
                A = A->right;
                printf(" %d", A->data);
            }
            else if (str[idx] == 'L')
            {
                A = A->left;
                printf(" %d", A->data);
            }

            idx++;
        }
        printf("\n");
    }

    return 0;
}