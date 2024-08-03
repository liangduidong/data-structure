#include <stdio.h>

// 定义小根堆的最大容量
#define MAX_HEAP_SIZE 100

// 全局变量，表示小根堆数组和当前堆的大小
int heap[MAX_HEAP_SIZE];
int heap_size = 0;

// 交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 向小根堆中插入一个新元素
void insertMinHeap(int value) {
    if (heap_size >= MAX_HEAP_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    // 将新元素插入到堆的末尾
    heap[++heap_size] = value;

    // 调整堆，使其保持小根堆的性质
    int current = heap_size;
    while (current > 1 && heap[current] < heap[current / 2]) {
        swap(&heap[current], &heap[current / 2]);
        current = current / 2;
    }
}

// 打印小根堆中的元素
void printMinHeap() {
    printf("Min Heap: ");
    for (int i = 1; i <= heap_size; ++i) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int elements[] = {6, 1, 5, 9, 8, 4, 7};
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    // 依次将元素插入小根堆中
    for (int i = 0; i < num_elements; ++i) {
        insertMinHeap(elements[i]);
        printMinHeap();
    }

    return 0;
}
