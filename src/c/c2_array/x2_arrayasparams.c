//
// Created by mac on 2023/3/12.
//


#include "stdio.h"
/**
 * 数组做函数参数
 * @return
 */
//void BubbleSort(int arr[])  // void BubbleSort(int *arr)

void BubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void test_func(int arr[]) {
    printf("size 2 = %u\n", sizeof(arr));  // 整个数组大小传递不再是整个数组，而是数组的首地址（一个指针）。
    printf("%d\n", arr[0]);
}

void test(){
    int arr[] = { 4, 5, 5, 6, 7 };
    printf("size 1 = %u\n", sizeof(arr));  // 整个数组大小
    test_func(arr);
}

int main() {
    int arr[] = {5, 89, 3, 22, 40, 31, 9, 22, 67, 28, 45, 78};
    printf("main: sizeof(arr) = %d\n", sizeof(arr));
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    test();
    return 1;
}