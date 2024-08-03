#include<stdio.h>
#include<stdlib.h>

int query(int A[],int x,int length){
    int left=0,right=length;
	while(left<=right){
		int mid=(left+right)/2;
		if(A[mid]<x) left=mid+1;
		else right=mid-1;
	}
//	if(left+1<length) return A[right+1];
	 return A[right+1];	
}

void out(int a[],int b[],int c[],int n){
	for(int i=0;i<n;i++){
//		printf("%d",a[i]);
		int value_b=query(b,a[i],n);
		int value_c=query(c,a[i],n);
//		printf("%d",value_b);
		if(a[i]==value_b&&a[i]==value_c) printf("%d ",a[i]);
	}
}
int max_num(int a,int b,int c){
	int max=a;
	if(b>max) max=b;
	if(c>max) max=c;
	return max;
}

//void out(int a[],int b[],int c[],int n){
//	int cur_a=0,cur_b=0,cur_c=0;
//	while(cur_a<n&&cur_b<n&&cur_c<n){
//		if(a[cur_a]==b[cur_b]&&a[cur_a]==c[cur_c]){
//			printf("%d ",a[cur_a]);
//			cur_a++;
//			cur_b++;
//			cur_c++;
//		}
//		else{
//			int max=max_num(a[cur_a],b[cur_b],c[cur_c]);
//			if(a[cur_a]<max) cur_a++;
//			if(b[cur_b]<max) cur_b++;
//			if(c[cur_c]<max) cur_c++;
//		}
//	}
//}
int main(){
	int a[]={1,2,3,5},b[]={2,3,4,5},c[]={-1,0,2,5};
	out(a,b,c,4);
//	out(a,b,c,4);
} 
