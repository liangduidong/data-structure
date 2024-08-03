#include<stdio.h>
#include <stdlib.h>
void Merge(int A[], int low, int mid, int high);
void MergeSort(int A[], int low, int high);
void print(int A[], int n);
int B[8];
void print(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return;
}

void MergeSort(int A[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

void Merge(int A[], int low, int mid, int high){
    int i, j, k;
    for(k=low;k<=high;k++) B[k] = A[k];
    for(i=low,j=mid+1,k=low;i<=mid&&j<=high;k++){
        if(B[i]<=B[j]) A[k]=B[i++];
        else A[k]=B[j++];
    }
    while(i<=mid) A[k++]=B[i++];
    while(j<=high) A[k++]=B[j++];
    return;
}
int main(){
    int A[]={0,6,1,5,9,8,4,7};
    int len = 8;
    int low=0, high=len-1;
    print(A, len);
    printf("\n");
    MergeSort(A, low, high);
    print(A, len);
    return 0;
}