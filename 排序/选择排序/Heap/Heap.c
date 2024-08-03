#include<stdio.h>
/*以下为  大根堆  代码*/
// 函数原型声明
// void HeapAdjust(int A[], int k, int len);
// void BuildHeap(int A[], int len);
// void MaxHeapSort(int A[], int len);
// void Swap(int *a, int *b);
// void print(int A[], int len);

// // 建堆
// void BuildHeap(int A[], int len){
//     int i;
// 	for(i=len/2;i>0;i--){
//         HeapAdjust(A, i, len);  // 以i为根节点，进行堆调整
//     }
//     return;
// }

// // 堆调整
// void HeapAdjust(int A[],int k, int len){
//     A[0] = A[k];  // 哨兵记录要调整的节点——k
//     int i;
// 	for(i=2*k;i<=len;i*=2){  //一直寻找要交换的子字节
//         if(i<len&&A[i]<A[i+1]) i++;  // 选择子节点中较大的一个来与其比较
//         if(A[0]>=A[i]) break;
//         else{
//             A[k]=A[i];
//             k=i;   
//         }   
//     }
//     A[k] = A[0];
//     return;
// }

// void Swap(int *a, int *b){
//     int temp=*a;
//     *a = *b;
//     *b = temp;
//     return;
// }

// // 大根堆排序
// void MaxHeapSort(int A[], int len){
//     BuildHeap(A, len);
//     for(int i=len;i>1;i--){
//         Swap(&A[1], &A[i]);
//         HeapAdjust(A, 1, i-1);
//     }
// }

// void print(int A[], int len){
//     int i; 
// 	for(i=1;i<=len;i++)
//        printf("%d ", A[i]);
//     return;
// }

/*以下为  小根堆  代码*/
// 函数声明
void BuildHeap(int A[], int len);
void Swap(int *a, int *b);
void HeapAdjust(int A[], int k, int len);
void MinHeapSort(int A[], int len);
void print(int A[], int len);

void MinHeapSort(int A[], int len){
    BuildHeap(A, len);
    for(int i=len;i>1;i--){
        Swap(&A[1], &A[i]);
        HeapAdjust(A, 1, i-1);
    }
    return;
}
void BuildHeap(int A[], int len){
    for(int i=len/2;i>0;i--){
        HeapAdjust(A, i, len);
    }
    return;
}
void HeapAdjust(int A[], int k, int len){
    A[0] = A[k];
    for(int i=2*k;i<=len;i*=2){
        if(i<len&&A[i]>A[i+1]) i++;
        if(A[0]<=A[i]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
    return;
}
void print(int A[], int len){
    for(int i=1;i<=len;i++){
        printf("%d ", A[i]);
    }
    return;
}
void Swap(int *a, int *b){
    int temp=*a;
    *a = *b;
    *b = temp;
    return;
}
int main(){
    int A[]={0,6,1,5,9,8,4,7};
    int len = 7;
    // MaxHeapSort(A, len);
    MinHeapSort(A, len);
    print(A, len);
    return 0;
}
