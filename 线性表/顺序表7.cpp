void reverve(int A[],int left,int right){
	if(left>right) return;
	int mid=(left-right)/2;
	for(int i=0;i<=mid;i++){
		int temp=A[left];
		A[left]=A[right-i];
		A[right-i]=temp;
	}
}
void reverve(int A,int m,int n,int maxsize){
	reverve(A,0,m+n-1);
	reverve(A,0,n-1);
	reverve(A,n,m+n-1);
} 
