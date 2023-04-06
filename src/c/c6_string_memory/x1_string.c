//
// Created by mac on 2023/3/22.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int noEmptyStringCount(char *str) {
    int count = 0;
    char *p = str;
    while (*p) {
        if (*p != ' ') {
            count++;
        }
        p++;
    }
    return count;
}

void testNoEmptyStringCount() {
    char str[] = "java he xx";
    int count = noEmptyStringCount(str);
    printf("string count =%d\n", count);
}

// 字符串逆序
void str_reversed(char *str) {
    //int i, j;  // str[i] *(str+i)
    char *start = str;                    // 记录首元素地址
    char *end = str + strlen(str) - 1;    // 记录最后一个元素地址。

    while (start < end) {           // 首元素地址是否 < 最后一个元素地址
        char tmp = *start;        // 三杯水 char 元素交换
        *start = *end;
        *end = tmp;
        start++;            // 首元素对应指针后移
        end--;                // 尾元素对应指针前移
    }
}

// 判断回文字符串
int str_palindrome(char *str) {
    char *start = str;        // 记录首元素地址
    char *end = str + strlen(str) - 1;// 记录最后一个元素地址。

    while (start < end) {       // 首元素地址是否 < 最后一个元素地址
        if (*start != *end) {    // 判断字符是否一致。{
            return 0; // 0 表示非 回文
        }
        start++;
        end--;
    }
    return 1;        // 1 表示 回文
}

// strcpy
int testStrcpy(void) {
    char src[] = "abc efg  zhansan wangwu ";
    char dest[10] = {0};
    char *p = strcpy(dest, src);;// 字符串src 拷贝给dest

    printf("p= %s\n", p);
    printf("dest = %s\n", dest);
}

// strncpy
int testStrNcpy(void) {
    char src[] = "hello world";
    char dest[100] = {0};

    char *p = strncpy(dest, src, 100);;// 字符串src 拷贝给dest
    for (size_t i = 0; i < 10; i++) {
        printf("%c\n", p[i]);
    }

    printf("p= %s\n", p);
    printf("dest = %s\n", dest);
}

int strcat_test(void) {
    char src[] = "world";
    char dest[] = "hello";

    char *p = strcat(dest, src);

    printf("p = %s\n", p);
    printf("dest = %s\n", dest);
}

int test_strncat(void) {
    char src[] = "world";
    char dest[6] = "hello";
    char *p = strncat(dest, src, 3);

    printf("p = %s\n", p);
    printf("dest = %s\n", dest);

    printf("%d\n", strlen(dest));
}


int test_strcmp(void) {
    char *str1 = "helloworld";
    char *str2 = "helloz";
    printf("ret = %d\n", strcmp(str1, str2));
}

int test_strncmp(void) {
    char *str1 = "helloworld";
    char *str2 = "helloz";
    printf("ret = %d\n", strncmp(str1, str2, 8));
}

// sprintf
int test_sprintf(void) {
    char buf[100] = {0}; //buffer  string str  source src
    sprintf(buf, "%d%c%d=%d\n", 10, '+', 34, 10 + 34);
    puts(buf);
}

// sscanf
int tset_sscanf(void) {
    char buf[100] = {0}; //buffer  string str  source src
    int a, b, c;
    char str[] = "13+56=89";

    sscanf(str, "%d+%d=%d", &a, &b, &c);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
}


int test_strtok(void) {
    char str[] = "www.itcast.cn.com.net";  // www itcast cn
    char *p = strtok(str, ".");  // 第一次拆分，参1 传 待拆分的原串。
    while (p != NULL) {
        p = strtok(NULL, ".");  // 第1+ 次拆分是，参1传 NULL.
        printf("%s\n", p);
    }
}

int test_malloc(void) {
    //int arr[1000000] = {10, 20, 40};
    int *p = (int *) malloc(sizeof(int) * 10);
    //char *str = (char *)malloc(sizeof(char)*10);
    if (p == NULL) {
        printf("malloc error\n");
        return -1;
    }
    char *tmp = p;  // 记录malloc返回的地址值。用于free

    // 写数据到 malloc 空间。
    for (size_t i = 0; i < 10; i++) {
        p[i] = i + 10;
    }
    // 读出malloc空间中的数据
    //for (size_t i = 0; i < 10; i++)
    //{
    //	printf("%d ", *(p+i));
    //}
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", *p);
        p++;
    }

    // 释放申请的内存。
    free(tmp);
    p = NULL;
}

int main() {
    testNoEmptyStringCount();
    return 0;
}