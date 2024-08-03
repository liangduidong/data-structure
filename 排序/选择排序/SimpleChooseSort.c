#include<stdio.h>
void print(int A[], int n);
void SimpleChooseSort(int A[], int n);
void print(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return;
}
void SimpleChooseSort(int A[], int n){
    for(int i=0;i<n-1;i++){
        int min=A[i];
        int k=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<min){
                min=A[j];
                k=j;
            }
        }
        min=A[k];
        A[k]=A[i];
        A[i]=min;
    }
    return;
}

int main(){
    int A[]={0,6,1,5,9,8,4,7};
    int len = 8;
    print(A, len);
    printf("\n");
    SimpleChooseSort(A, len);
    print(A, len);
    return 0;
}