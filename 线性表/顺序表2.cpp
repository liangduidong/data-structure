#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}sqList;

void reserve(sqList *L){
	int temp;
	for(int i=0;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-1-i];
		L->data[L->length-1-i]=L->data[i];
	}
	return;
}

void print(sqList L){
	for(int i=0;i<L.length;i++){
		printf("%d  ",L.data[i]);
	}
	printf("\n");
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
	reserve(L);
	print(*L);
	return 0;
} 
