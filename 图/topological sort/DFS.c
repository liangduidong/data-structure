#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 100

// 边表
typedef struct ArcNode {
    int adjvex;            // 边/弧指向哪个结点
    struct ArcNode *next;
} ArcNode;

// 节点表
typedef struct VNode {
    int data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

// 用邻接表存储图
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} Graph;

bool visited[MaxVertexNum];
int stack[MaxVertexNum], top = -1;

// 深度优先遍历的辅助函数，获取第一个邻接点
int FirstNeighbor(Graph G, int v) {
    if (G.vertices[v].first != NULL)
        return G.vertices[v].first->adjvex;
    return -1;
}

// 深度优先遍历的辅助函数，获取下一个邻接点
int NextNeighbor(Graph G, int v, int w) {
    ArcNode *p = G.vertices[v].first;
    while (p != NULL) {
        if (p->adjvex == w && p->next != NULL)
            return p->next->adjvex;
        p = p->next;
    }
    return -1;
}

void DFS(Graph G, int v) {
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
    stack[++top] = v; // 记录拓扑排序
}

void DFSTraverse(Graph G) {
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;
    for (int v = 0; v < G.vexnum; ++v)
        if (!visited[v])
            DFS(G, v);
}

void TopologicalSort(Graph G) {
    DFSTraverse(G);
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// 示例图的创建函数
void createGraph(Graph *G) {
    G->vexnum = 6;  //6个顶点
    G->arcnum = 8;  //7条边

    for (int i = 0; i < G->vexnum; i++) {
        G->vertices[i].data = i;       // 每个顶点存储自己的顶点
        G->vertices[i].first = NULL;   // 指向顶点初始为空
    }

    int edges[8][2] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {4, 3}
    };

    for (int i = 0; i < G->arcnum; i++) {      // 这是一个邻接表
        int start = edges[i][0];
        int end = edges[i][1];
        ArcNode *node = (ArcNode *)malloc(sizeof(ArcNode));
        node->adjvex = end;   // 新建一个边界点
        node->next = G->vertices[start].first;   // 采用头插法
        G->vertices[start].first = node;         
    }
}

int main() {
    Graph G;
    createGraph(&G);
    TopologicalSort(G);
    return 0;
}
