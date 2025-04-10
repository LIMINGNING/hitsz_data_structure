#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(char** input, int n) {
    if (n == 0 || strcmp(input[0], "null")== 0) return NULL;

    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    TreeNode* root = newNode(atoi(input[0]));
    queue[0] = root;
    int front = 0, rear = 1;

    for (int i = 1; i < n; i += 2) {
        TreeNode* current = queue[front++];

        if (strcmp(input[i], "null")!= 0) {
            current->left = newNode(atoi(input[i]));
            queue[rear++] = current->left;
        }

        if (i + 1 < n && strcmp(input[i + 1], "null")!= 0) {
            current->right = newNode(atoi(input[i + 1]));
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

int max_sum; /* Record max length sum. */

// 计算以 node 为根的“向上最大贡献值”
int max_gain(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    // 递归计算左右子树贡献，负数则丢弃（取 0）
    int left_gain  = max_gain(node->left);
    if (left_gain < 0) {
        left_gain = 0;
    }
    int right_gain = max_gain(node->right);
    if (right_gain < 0) {
        right_gain = 0;
    }

    // 以当前节点为拐点的最大路径和
    int price_newpath = node->val + left_gain + right_gain;

    if (price_newpath > max_sum) {
        max_sum = price_newpath;
    }

    // 返回当前节点对父节点的最大贡献（只能选一侧）
    return node->val + (left_gain > right_gain ? left_gain : right_gain);
}

// 主函数：计算二叉树的最大路径和
int maxPathSum(TreeNode* root) {
    max_sum = INT_MIN;
    max_gain(root);
    return max_sum;
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    char* inputs[100];
    int n = 0;
    while (token != NULL) {
        inputs[n++] = token;
        token = strtok(NULL, " \n");
    }
    TreeNode* root = buildTree(inputs, n);

    int result = maxPathSum(root);
    printf("%d\n", result);

    freeTree(root);

    return 0;
}