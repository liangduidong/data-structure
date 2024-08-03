#include<stdio.h>
void print(int A[], int n);
void InsertSort(int A[], int n);
void print(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return;
}
void InsertSort(int A[], int n){
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        // 将A[i]插入到已排序部分的正确位置
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

int main(){
    int A[]={0,6,1,5,9,8,4,7};
    int len = 8;
    print(A, len);
    printf("\n");
    InsertSort(A, len);
    print(A, len);
    return 0;
}