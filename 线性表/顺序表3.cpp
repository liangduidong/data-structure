#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}sqList;

void print(sqList L){
	for(int i=0;i<L.length;i++){
		printf("%d  ",L.data[i]);
	}
	printf("\n");
	return;
}

void del(sqList *L, int x){
	int del_num=0;  //删除的值为x的个数 
	for(int i=0;i<L->length;i++){
		if(L->data[i]==x) del_num++;
		else L->data[i-del_num]=L->data[i];
	}
	L->length-=del_num;
	return; 
} 

int main(){
	sqList *L=(sqList *)malloc(sizeof(sqList));  //分配空间返回的是一个指针 
	L->length=0;
	for(int i=0;i<10;i++){
		L->data[i]=i;
	    L->length++;
	}
	print(*L);
	del(L, 5);
	print(*L);
	return 0;
} 
