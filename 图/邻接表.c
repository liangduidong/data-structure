#include<stdio.h>
# define MaxVertexNum 100
// 边表
typedef struct ArcNode
{
    int adjvex;        // 边/弧指向哪个结点
    struct ArcNode *next;
    
}ArcNode;
// 节点表
typedef struct VNode{
    int data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

// 用邻接表存储图
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}ArcGraph;


