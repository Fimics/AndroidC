//
// Created by mac on 2023/3/12.
//
#include "stdio.h"

//1
void arr1() {
    int a = 5, b = 6, c = 7;
    int arr[10] = {1, 2, 3, 4, 6, 7, 8, 9, 0};
    printf("&arr[0]=%p\n", &arr[0]); //数组元素首地址
    printf("arr[0]=%d\n", arr[0]);
    printf("arr name=%p\n", &arr);//数组元素首地址
}

void arr2() {
    int a = 5, b = 29, c = 10;

    int arr[12] = {1, 2, 4, 6, 76, 8, 90, 4, 3, 6, 6, 8};  //int a = 109;

    printf("数组大小：%u\n", sizeof(arr));
    printf("数组元素的大小：%u\n", sizeof(arr[0]));
    printf("数组元素个数：%d\n", sizeof(arr) / sizeof(arr[0]));
}

void initArray() {
    int arr[10];  //int a = 109;
    arr[0] = 5;
    arr[1] = 6;
    arr[2] = 7;

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("array length = %d\n",n);
    for (size_t i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

}

int main() {
    arr1();
    arr2();
    initArray();
    return 0;
}