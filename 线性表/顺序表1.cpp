#include <stdio.h>
#include <stdlib.h> //需要这个库才能分配空间给顺序表 
#define MaxSize 50
typedef struct{
    int data[MaxSize];
    int length;
}sqList;  

int del_elemt(sqList *L){
	int position, value=L->data[0];
	int i;
	if(L->length==0){
		printf("error");
		return 0;
	}
	for(i=0;i<L->length;i++){
		if(value>L->data[i]){
		   value=L->data[i];
		   position=i;	
		} 
	}
	L->data[position]=L->data[i-1];
	L->length--;
	return value; 
} 

int main(){
	sqList *L = (sqList *)malloc(sizeof(sqList));
	L->length=0;
	int i;
	for(i=0;i<10;i++){
		L->data[i]=i;
	    L->length++;
	}
	int value=del_elemt(L);
	printf("%d",value);
	return 0;
}
