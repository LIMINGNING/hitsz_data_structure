#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode *p[MAXSIZE];
    int rear;
    int front;
}Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    return ;
}

/**
 * Cycle queue:
 * 1.rear = front = -1, queue is empty.
 * 2.rear = front (= 0), queue has only one element.
 * 3.(rear + 1) % MAXSIZE = q->front, queue is full.
 * @param q Operation q. 
 * @param node Node to be enqueue.
 * @return 1 success, 0 fail.
 */
int enQueue(Queue *q, struct TreeNode *node) {
    if ((q->rear + 1) % MAXSIZE == q->front) { /* Queue is full. */
        return 0;
    }

    if (q->front == -1) { /* Add first element to queue. */
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAXSIZE; /* Other cases. */
    }

    q->p[q->rear] = node; /* Enqueue. */

    return 1;
}

int deQueue(Queue *q, struct TreeNode **node) {
    if (q->front == -1) { /* Queue is empty. */
        return 0;
    }

    *node = q->p[q->front]; /* Dequeue. */

    if (q->front == q->rear) { /* (= 0) Queue has only one element. */
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAXSIZE; 
    }

    return 1;
}

int isEmptyQueue(Queue q) {
    return q.front == -1;
}

struct TreeNode* newNode(int val) {
    struct TreeNode *t = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (t == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    t->val = val;
    t->left = t->right = NULL;
    return t;
}

int returnInorderIndex(int val, int *inorder, int left, int right) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize, int left, int right, int *preorderIndex) {
    if (left > right) { /* This node hasn't have child tree. */
        return NULL;
    }

    int currentVal = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct TreeNode *t = newNode(currentVal);

    int inorderIndex = returnInorderIndex(currentVal,inorder,left,right); 

    t->left = buildTree(preorder,preorderSize,inorder,inorderSize,left,inorderIndex - 1, preorderIndex);
    t->right = buildTree(preorder,preorderSize,inorder,inorderSize,inorderIndex + 1,right, preorderIndex);

    return t;
}

void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return ;
    }

    Queue q;
    initQueue(&q);
    struct TreeNode *current = root;

    enQueue(&q,current);

    while (!isEmptyQueue(q)) {
        deQueue(&q,&current);
        if (current == NULL) {
            printf("null ");
            continue;
        }
        printf("%d ",current->val);

        enQueue(&q,current->left);
        enQueue(&q,current->right);
    }

    return ;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return ;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int preorderSize;
    scanf("%d", &preorderSize);
    int* preorder = (int*)malloc(preorderSize * sizeof(int));
    for (int i = 0; i < preorderSize; i++) {
        scanf("%d", &preorder[i]);
    }

    int inorderSize = preorderSize;
    int* inorder = (int*)malloc(inorderSize * sizeof(int));
    for (int i = 0; i < inorderSize; i++) {
        scanf("%d", &inorder[i]);
    }

    int preorderIndex = 0;
    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize, 0, inorderSize - 1, &preorderIndex);
    printTree(root);
    freeTree(root);

    return 0;
}