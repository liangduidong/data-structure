#include<stdio.h>
/*静态分配的顺序表
#define MaxSize 50
typedef struct{
    int data[MaxSize];
    int length;
}sqList;  */

/*动态分配的顺序表*/
#define InitSize 100  //动态表的初始长度
typedef struct{
    int *data;
    int MaxSize,length; 
}sqList;

int main(){
    //初始化动态顺序表
    sqList L;   //结构体取了别名就不用struct
    // L.data=(int *)malloc(sizeof(int)*InitSize); c语言分配储存空间语句
    L.data=new int[InitSize];
}

