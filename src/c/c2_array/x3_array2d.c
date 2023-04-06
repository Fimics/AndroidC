//
// Created by mac on 2023/3/12.
//


#include "stdio.h"

void twoArray() {
    int arr[3][4] = {{2,  7,  8,  5},
                     {75, 8,  9,  8},
                     {26, 37, 99, 9}};
    for (size_t i = 0; i < 3; i++)        //行
    {
        for (size_t j = 0; j < 4; j++)  //列
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("数组的大小为：%u\n", sizeof(arr));
    printf("数组行行的大小：%u\n", sizeof(arr[0]));
    printf("数组一个元素的大小：%u\n", sizeof(arr[0][0]));

    printf("行数=总大小/一行大小：%d\n", sizeof(arr) / sizeof(arr[0]));
    printf("列数=行大小/一个元素大小：%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));

    printf("arr= %p\n", arr);
    printf("&arr[0] = %p\n", &arr[0][0]);
    printf("arr[0] = %p\n", arr[0]);
}

void initTwoArray() {
    int arr[][2] = {1, 3, 4, 6, 7};

    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    for (size_t i = 0; i < row; i++)        //行
    {
        for (size_t j = 0; j < col; j++)  //列
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("数组的大小为：%u\n", sizeof(arr));
    printf("数组行的大小：%u\n", sizeof(arr[0]));
    printf("数组一个元素的大小：%u\n", sizeof(arr[0][0]));

    printf("行数=总大小/一行大小：%d\n", sizeof(arr) / sizeof(arr[0]));
    printf("列数=行大小/一个元素大小：%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));

    printf("arr= %p\n", arr);
    printf("&arr[0] = %p\n", &arr[0][0]);
    printf("arr[0] = %p\n", arr[0]);

}

void testTwoArray() {
    int scores[5][3] = {1, 2, 4, 5, 6, 7, 8, 9};

    int row = sizeof(scores) / sizeof(scores[0]);
    int col = sizeof(scores[0]) / sizeof(scores[0][0]);

    // 获取 5 名学生、3门功课成绩
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            scanf("%c", &scores[i][j]);
        }
    }
    // 求一个学生的总成绩
    for (size_t i = 0; i < row; i++) // 每个学生
    {
        int sum = 0;
        for (size_t j = 0; j < col; j++)// 每个学生的成绩
        {
            sum += scores[i][j];
        }
        printf("第%d个学生的总成绩为：%d\n", i + 1, sum);
    }
    //求一门功课的总成绩
    for (size_t i = 0; i < col; i++)  // 第几门功课
    {
        int sum = 0;
        for (size_t j = 0; j < row; j++)  // 每门功课的第几个学生
        {
            sum += scores[j][i];
        }
        printf("第%d门功课的总成绩为：%d\n", i + 1, sum);
    }

}

int main() {
//    twoArray();
    initTwoArray();
//    testTwoArray();
    return 1;
}