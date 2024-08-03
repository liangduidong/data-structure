#include<stdio.h>
#include<stdlib.h>
 
void query_min(int a[],int n){
    bool flg[n]={0};
	int j;
	for(int i=0;i<n;i++){
		if(a[i]>0&&a[i]<=n) flg[a[i]-1]=true;
	}

	for(j=0;j<n;j++){
		if(flg[j]==false) break;
	}
	
	printf("%d",j+1);
	return;
}

int main(){
	int a[]={1,2,3}, n=3;
	query_min(a,n);
	return 0;
}
