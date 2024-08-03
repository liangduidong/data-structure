void insert(sqList *L,int x, int position){
	if(position>L->length||position<0) return;
	if(position==L->length){
		L->data[L->length++]=x; 
		return;
	} 
	for(int i=L->length-1;i>=position;i--){
		L->data[i+1]=L->data[i];
	}
	L->data[position]=x;
	L->length++;
	return; 
}
void query(sqList *L,int x){
	int left=0,right=L->length-1;
//	int position;
	while(left<=right){
		int mid=(left+right)/2;
		if(L->data[mid]<x) left=mid+1;
		else right=mid-1;
	}
	insert(L,x,left+1);
	return;
} 
