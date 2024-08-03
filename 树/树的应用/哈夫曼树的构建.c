#include <stdio.h>
#include <stdlib.h>

// 定义哈夫曼树的节点结构体
typedef struct TreeNode {
    int weight;  // 权重（或频率）
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 定义优先队列的节点结构体（用于构建哈夫曼树）
typedef struct PriorityQueueNode {
    TreeNode *treeNode;
    struct PriorityQueueNode *next;
} PriorityQueueNode;

// 创建一个空的优先队列
PriorityQueueNode* createEmptyPriorityQueue() {
    return NULL;
}

// 创建一个包含单个节点的优先队列节点
PriorityQueueNode* createPriorityQueueNode(TreeNode *treeNode) {
    PriorityQueueNode *newNode = (PriorityQueueNode*) malloc(sizeof(PriorityQueueNode));
    if (newNode != NULL) {
        newNode->treeNode = treeNode;
        newNode->next = NULL;
    }
    return newNode;
}

// 插入一个新的节点到优先队列中（按权重排序，小的在前）
PriorityQueueNode* insertIntoPriorityQueue(PriorityQueueNode *queue, TreeNode *treeNode) {
    PriorityQueueNode *newNode = createPriorityQueueNode(treeNode);
    
    if (queue == NULL || treeNode->weight <= queue->treeNode->weight) {
        newNode->next = queue;
        return newNode;
    }
    
    PriorityQueueNode *current = queue;
    while (current->next != NULL && current->next->treeNode->weight < treeNode->weight) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return queue;
}

// 弹出优先队列中的最小节点
TreeNode* popPriorityQueue(PriorityQueueNode **queue) {
    if (*queue == NULL) {
        return NULL;
    }
    
    PriorityQueueNode *top = *queue;
    TreeNode *treeNode = top->treeNode;
    *queue = (*queue)->next;
    free(top);
    
    return treeNode;
}

// 构建哈夫曼树
TreeNode* buildHuffmanTree(int weights[], int n) {
    PriorityQueueNode *queue = createEmptyPriorityQueue();
    
    // 将每个权重（或频率）作为一个单节点树插入到优先队列中
    for (int i = 0; i < n; i++) {
        TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
        node->weight = weights[i];
        node->left = NULL;
        node->right = NULL;
        
        queue = insertIntoPriorityQueue(queue, node);
    }
    
    // 不断合并优先队列中的两个最小节点，直到只剩一个节点为止
    while (queue != NULL && queue->next != NULL) {
        TreeNode *leftChild = popPriorityQueue(&queue);
        TreeNode *rightChild = popPriorityQueue(&queue);
        
        TreeNode *parent = (TreeNode*) malloc(sizeof(TreeNode));
        parent->weight = leftChild->weight + rightChild->weight;
        parent->left = leftChild;
        parent->right = rightChild;
        
        queue = insertIntoPriorityQueue(queue, parent);
    }
    
    // 返回根节点
    TreeNode *huffmanTreeRoot = popPriorityQueue(&queue);
    return huffmanTreeRoot;
}

// 释放哈夫曼树的内存
void freeHuffmanTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}

// 打印哈夫曼树的结构（前序遍历）
void printHuffmanTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->weight);
    printHuffmanTree(root->left);
    printHuffmanTree(root->right);
}

int main() {
    int weights[] = {5, 9, 12, 13, 16, 45};  // 举例：每个字符的权重（频率）
    int n = sizeof(weights) / sizeof(weights[0]);
    
    // 构建哈夫曼树
    TreeNode *huffmanTreeRoot = buildHuffmanTree(weights, n);
    
    // 打印哈夫曼树的结构（前序遍历）
    printf("Huffman Tree structure (preorder traversal): ");
    printHuffmanTree(huffmanTreeRoot);
    printf("\n");
    
    // 释放哈夫曼树的内存
    freeHuffmanTree(huffmanTreeRoot);
    
    return 0;
}
