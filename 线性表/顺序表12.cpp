#include<stdio.h>
#include<stdlib.h>

void main_elemt(int a[],int n){
	int b[n]={0},flg,max=0;
	for(int i=0;i<n;i++){
		b[a[i]]++;
//		printf("%d ",b[a[i]]);
		if(b[a[i]]>max){
		   flg=a[i];
		   max=b[a[i]];	
		} 
	}
	max>n/2? printf("%d",flg):printf("%d",-1);
}

int main(){
	int a[]={0,5,5,3,5,7,5,7},n=8;
	main_elemt(a,n);
}
