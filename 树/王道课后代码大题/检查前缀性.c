#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *lchild, *rchild;
    bool isEndOfword;  // 是否为最后一个符号
} Node;

// 创建新节点
Node* CreateNode() {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode != NULL) {
        NewNode->isEndOfword = false;
        NewNode->lchild = NULL;
        NewNode->rchild = NULL;
    }
    return NewNode;
}

// 将编码插入到树中
bool Insert(Node* tree, const char* key) {
    Node* current = tree;
    bool Conflict1 = false;  // 检查是否有编码为当前编码的前缀
    bool Conflict2 = true;  // 检查当前编码是否为其他编码的的前缀
    for (int i = 0; key[i]; ++i) {
        if (key[i] == '0') {
            if (current->lchild == NULL) {
                current->lchild = CreateNode();
                Conflict2=false;
            }
            current = current->lchild;
        } else if (key[i] == '1') {
            if (current->rchild == NULL) {
                current->rchild = CreateNode();
                Conflict2=false;
            }
            current = current->rchild;
        }
        if (current->isEndOfword) {
            Conflict1 = true;
            break;
        }
    }
    // 标记当前编码的为单词结尾
    current->isEndOfword = true;
    return Conflict1||Conflict2;  // 两种冲突只要有一个成立，则不具备前缀特性
}

// 检查是否具有前缀特性
bool checkPrefixProperty(char** codes, int n) {
    Node* tree = CreateNode(); // 创建空树

    bool PrefixConflict = false;
    for (int i = 0; i < n; ++i) {
        if (Insert(tree, codes[i])) {
            PrefixConflict = true;
            break;
        }
    }
    return !PrefixConflict;
}
int main() {
    // 示例：包含多个0/1编码的数组
    char* codes[] = {"0001", "0010", "0011", "0000", "01", "1", "0"};//{"01", "10", "001", "011", "110"};

    // 检查编码是否具有前缀特性
    bool isPrefixFree = checkPrefixProperty(codes, sizeof(codes) / sizeof(codes[0]));

    if (isPrefixFree) {
        printf("编码具有前缀特性\n");
    } else {
        printf("编码存在前缀冲突\n");
    }

    return 0;
}
