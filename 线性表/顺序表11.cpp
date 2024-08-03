#include<stdio.h>
#include<stdlib.h>

void mid_num(int a[],int b[], int n){
	int cur_a=0,cur_b=0;
	int cur=0,mid;
	while(cur!=n){
		if(a[cur_a]<b[cur_b]){
			mid=a[cur_a++];
		}
		else{
			mid=b[cur_b++];
		}
		cur++;	
	}
	printf("%d",mid);
	return;
}

int main(){
	int a[]={11,13,15,17,19},b[]={2,4,6,8,20},n=5;
	mid_num(a,b,n);
	return 0; 
}
