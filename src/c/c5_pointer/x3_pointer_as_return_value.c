//
// Created by mac on 2023/3/22.
//
/**
 * 指针做函数返回值，不能返回【局部变量的地址值】。
 */

#include "stdio.h"

int m = 100;   // 全局变量 对应空间消失 ==> 程序结束。

int *test_func2(int a, int b) {
    int p = 1234;  // 局部变量
    //return &m;
    return &p;
}

int main(void) {
    int *ret = NULL;  // NULL == 0

    ret = test_func2(10, 20);

    printf("ret = %d\n", *ret);

    return 1;
}