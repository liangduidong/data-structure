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

sqList *del(sqList *L,sqList *L1, sqList *L2){
	int l1=0,l2=0;
	
	while(l1<=L1->length&&l2<=L2->length){
		if(L1->data[l1]<=L2->data[l2]){
			L->data[L->length++]=L1->data[l1++];
		}
		else L->data[L->length++]=L2->data[l2++];
	}
	return L; 
} 

int main(){
	sqList *L1=(sqList *)malloc(sizeof(sqList));  //分配空间返回的是一个指针 
	sqList *L2=(sqList *)malloc(sizeof(sqList));
	sqList *L=(sqList *)malloc(sizeof(sqList));
	L->length=0;
	L1->length=0;
	L2->length=0;
	for(int i=0;i<10;i++){
		L1->data[i]=i;
	    L1->length++;
	    
	    L2->data[i]=i;
	    L2->length++;
	}
	print(*L1);
	L=del(L,L1,L2);
	print(*L);
	return 0;
} 
