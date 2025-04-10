#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int color;
};

void dyeNode(struct TreeNode *t, int op, int left, int right) {
    if (t == NULL) {
        return;
    }

    if (t->val >= left && t->val <= right) {
        t->color = op; 
    }

    if (t->val > right) {
        dyeNode(t->left, op, left, right);
    }
    else if (t->val < left) {
        dyeNode(t->right, op, left, right);
    }
    else {
        dyeNode(t->left, op, left, right);
        dyeNode(t->right, op, left, right);
    }
}

void preOrder(struct TreeNode *root, int *count) {
    if (root == NULL)
        return;
    if (root->color == 1) {
        (*count)++;
    }
    preOrder(root->left, count);
    preOrder(root->right, count);
}

void getNumber(struct TreeNode* root, int** ops, int opsSize) {
    for (int i = 0; i < opsSize; i++) {
        dyeNode(root, ops[i][0], ops[i][1], ops[i][2]);
    }
    
    int count = 0;
    preOrder(root, &count);
    printf("%d\n", count);
    return;
}

struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    node->color = 0;
    return node;
}

struct TreeNode* constructTree(int size) {
    if (size == 0)
        return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    for (int i = 0; i < size; i++) {
        int val;
        scanf("%d", &val);
        if (val == -1) {
            nodes[i] = NULL;
        } else {
            nodes[i] = newTreeNode(val);
        }
    }

    for (int i = 0, j = 1; j < size; i++) {
        if (nodes[i] != NULL) {
            if (j < size)
                nodes[i]->left = nodes[j++];
            if (j < size)
                nodes[i]->right = nodes[j++];
        }
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void readOps(int ***ops, int *opsSize) {
    scanf("%d", opsSize);

    *ops = (int **)malloc(*opsSize * sizeof(int *));
    while(getchar() != '[') {}
    for (int i = 0; i < *opsSize; i++) {
        (*ops)[i] = (int *)malloc(3 * sizeof(int));
        while(getchar() != '[') {}
        for (int j = 0; j < 3; j++) {
            scanf("%d", &((*ops)[i][j]));
        }
        while(getchar() != ']') {}
    }
}

int main() {
    int nodeSize;
    scanf("%d", &nodeSize);
    struct TreeNode* root = constructTree(nodeSize);
    int **ops, opsSize;
    readOps(&ops, &opsSize);
    getNumber(root, ops, opsSize);

    return 0;
}