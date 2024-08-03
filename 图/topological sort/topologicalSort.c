#include<stdio.h>
#include <stdlib.h>

#define MAX 100  // 最大顶点数

void topologicalSort(int n, int adjMatrix[MAX][MAX]) {
    int in_degree[MAX] = {0};  // 初始化每个顶点的入度
    int queue[MAX], front = 0, rear = 0;
    int top_order[MAX], k = 0;

    // 计算每个顶点的入度
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // 将所有入度为0的顶点入队
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 进行拓扑排序
    while (front < rear) {
        int u = queue[front++];
        top_order[k++] = u;

        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 检查是否存在环
    if (k != n) {
        printf("Graph has a cycle\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", top_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int n = 6;  // 顶点数
    int adjMatrix[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(n, adjMatrix);

    return 0;
}
