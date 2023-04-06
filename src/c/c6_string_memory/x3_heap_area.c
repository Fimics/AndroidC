#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *getSpace() {
    int *p = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        p[i] = i + 100;
    }
    return p;
}


void test01() {
    int *p = getSpace();
    for (int i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }
    //手动开辟  手动释放
    free(p);
    p = NULL;
}

void allocateSpace(char *pp) {
    char *temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello world");
    pp = temp;
    printf("%s",*temp);
}

//主调函数 //错误案例
void test02() {
    char *p = NULL;
    allocateSpace(p);
    printf("%s\n", p);
}

void allocateSpace2(char **pp) {
    char *temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello world");
    *pp = temp;
}

void test03() {
    char *p = NULL;
    allocateSpace2(&p);
    printf("%s\n", p);

    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

int main() {
//    test01();
    test03();
    return EXIT_SUCCESS;
}