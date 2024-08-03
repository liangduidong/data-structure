#include<stdio.h>
/*快速排序*/
void QuickSort(int A[], int low, int high);
int Partion(int A[], int low, int high);
void print(int A[], int n);
void print(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return;   
}
int Partion(int A[], int low, int high){
    int piovt=A[low];
    while(low<high){
        while(low<high&&piovt<=A[high]) --high;
        A[low] = A[high];
        while(low<high&&A[low]<=piovt) ++low;
        A[high] = A[low];
    }
    A[low] = piovt;
    return low;
}
void QuickSort(int A[], int low, int high){
    if(low<high){
        int Partpivot=Partion(A, low, high);
        QuickSort(A, low, Partpivot-1);
        QuickSort(A, Partpivot+1, high);
    }
    return;
}
int main(){
    int A[]={0,6,1,5,9,8,4,7};
    int len = 8;
    int low = 0, high = 7;
    // MaxHeapSort(A, len);
    QuickSort(A, low, high);
    print(A, len);
    return 0;
}