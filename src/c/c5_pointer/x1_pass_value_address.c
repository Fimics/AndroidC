//
// Created by mac on 2023/3/22.
//
//
// Created by mac on 2021/6/12.
//

#include "stdio.h"

/**
 * 传值和传地址
 * @return
 */

int swap(int, int);

int swap2(int *, int *);

void pass1() {
    int m = 1;
    int n = 2;

    printf("--before-- m = %d, n = %d\n", m, n);
    // 函数调用
//    swap(m, n);  // m/n 实参

    swap2(&m, &n);

    printf("--after-- m = %d, n = %d\n", m, n);
}

int main() {
    pass1();
    return 1;
}

int swap2(int *a, int *b)    // 形参a、b， 需传地址值
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

// 函数定义
int swap(int a, int b)    // a/b 形参
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
    return 0;
}