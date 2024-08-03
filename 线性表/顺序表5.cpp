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

void del(sqList *L){
	int del_num=0;  //ɾ����ֵΪx�ĸ��� 
	for(int i=1;i<L->length;i++){
		if(L->data[i]==L->data[i-1]) del_num++;
		else L->data[i-del_num]=L->data[i];
	}
	L->length-=del_num;
	return; 
} 

int main(){
	sqList *L=(sqList *)malloc(sizeof(sqList));  //����ռ䷵�ص���һ��ָ�� 
	L->length=0;
	for(int i=0;i<10;i++){
		L->data[i]=0;
	    L->length++;
	}
	print(*L);
	del(L);
	print(*L);
	return 0;
} 
