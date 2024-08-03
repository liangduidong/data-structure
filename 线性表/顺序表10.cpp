#include<stdio.h>
#include<stdlib.h>
void reverse(int A[],int left,int right){
	int mid=(left+right)/2;
	for(int i=left;i<=mid;i++){
		int temp=A[i];
		A[i]=A[right-i+left];
		A[right-i+left]=temp;
	}
}

void print(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d  ",A[i]);
	}
	printf("\n");
	return;
}

int main(){
	int a[]={0,1,2,3,4,5,6,7,8,9},p=6,n=10;
	print(a,n);
	reverse(a,0,n-1);
//	print(a,n);
	reverse(a,0,n-p-1);
//	print(a,n);
	reverse(a,n-p,n-1);
	print(a,n);
	return 0;
}
