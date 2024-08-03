#include<stdio.h>
void print(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return;   
}

void BubbleSort(int A[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=n;j>i;j--){
            if(A[A[j]<A[j-1]]){
                int temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
    return;
}

int main(){
    int A[]={0,6,1,5,9,8,4,7};
    int len = 8;
    print(A, len);
    printf("\n");
    BubbleSort(A, len);
    print(A, len);
    return 0;
}