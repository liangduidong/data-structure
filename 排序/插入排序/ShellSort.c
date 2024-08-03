#include<stdio.h>
void print(int A[], int n);
void ShellSort(int A[], int n);
void print(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return;
}
void ShellSort(int A[], int n){
    for(int d=n/2;d>0;d/=2){
        for(int i=0;i<d;i++){
            int k=A[i];
            for(int j=i+d;j<n;j+=d){
                if(A[j]<A[j-d]){
                    int temp=A[j];
                    A[j] = A[j-d];
                    A[j-d] = temp;
                } 
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
    ShellSort(A, len);
    print(A, len);
    return 0;
}