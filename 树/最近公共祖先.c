#include<stdio.h>
#include<stdlib.h>
#define Max 100
typedef struct{
    int data[Max];
    int len;
}Tree;
// 寻找最小公共祖先
int seekAncestor(Tree tree, int a, int b){
    while(a!=b&&a>0&&b>0){
        if(a>b) a/=2;
        else b/=2;
    }
    if(a==b&&a!=0) return a;
    return 0;
}
int main(){
    Tree tree;
    tree.len=0;
    int ancestor=seekAncestor(tree,2,7);
    if(ancestor!=0) printf("共同祖先: %d", ancestor);
    else printf("未找到公共祖先!");
    return 0;
}