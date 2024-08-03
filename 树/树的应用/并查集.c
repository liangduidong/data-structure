#include<stdlib.h>
#include<stdio.h>
#define Max 10
// 双亲表示法
typedef struct node{
    int data;
    int parent;
}Node;
typedef struct tree{
    Node nodes[Max];
}ParentTree;

// 初始化并查集
void Initial(ParentTree *S){
    for(int i=0;i<Max;i++){
        S->nodes[i].data=i;
        S->nodes[i].parent=-1;
    }
    return;
}
// 查找根节点操作
int Find(ParentTree *S, int x){
    while(S->nodes[x].parent>=0){
        x=S->nodes[x].parent;
    }
    return x;
}
// 合并集合操作
void Union(ParentTree *S, int root1, int root2){
    if(root1==root2){
        printf("两节点已在同一个集合!");
        return;
    } 
    S->nodes[root2].parent=root1;
    return;
}
// 改进查找
int Improve_Find(ParentTree *S, int x){
    //先找到根节点
    int root=x;
    while(S->nodes[root].parent>=0){
        root=S->nodes[root].parent;
    }
    // 将集合中的所有节点的全部指向根节点
    while(S->nodes[x].parent!=root&&S->nodes[x].parent>=0){
        int temp=S->nodes[x].parent;
        S->nodes[x].parent=root;
        x=temp;
    }
    return root;
}
// 改进合并操作
void Improve_Union(ParentTree *S, int root1, int root2){
    if(root1==root2){
        printf("二者已在同一集合！\n");
        return;
    }
    if(S->nodes[root1].parent<=S->nodes[root2].parent){
        S->nodes[root1].parent += S->nodes[root2].parent;
        printf("合并后的集合大小: %d\n", S->nodes[root1].parent);
        S->nodes[root2].parent=root1;
    }
    else{
        S->nodes[root2].parent+=S->nodes[root1].parent;
        printf("合并后的集合大小: %d\n", S->nodes[root2].parent);
        S->nodes[root1].parent=root2;
    } 
    return;
}

int main(){
    ParentTree S;
    // 改进前的并查集
    // Initial(&S);
    // int root1=Find(&S, 1), root2=Find(&S, 5);
    // printf("当前两节点所属集合: %d, %d\n",root1, root2);
    // Union(&S, root1, root2);  // 合并该集合
    // root1=Find(&S, 1), root2=Find(&S, 5);
    // printf("当前两节点所属集合: %d, %d\n",root1, root2);
    // Union(&S, root1, root2);  // 合并该集合
    
    // 改进后的并查集
    Initial(&S);
    printf("初始化成功!\n");
    int root1=Improve_Find(&S, 1), root2=Improve_Find(&S, 5);
    printf("当前两节点所属集合: %d, %d\n",root1, root2);
    Improve_Union(&S, root1, root2);  // 合并该集合
    root1=Improve_Find(&S, 1), root2=Improve_Find(&S, 5);
    printf("当前两节点所属集合: %d, %d\n",root1, root2);
    Improve_Union(&S, root1, root2);  // 合并该集合
    return 0;
}