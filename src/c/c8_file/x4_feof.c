#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void read_file() {
    char ch = 0;
    FILE *fp = fopen("./res/test.txt", "r");
    if (fp == NULL) {
        perror("fopen error");
        return;
    }

    while (1) {
        ch = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        printf("%d\n", ch);
    }
    fclose(fp);
}

void test_feof() {
    FILE *fp = fopen("./res/test.txt", "r");
    if (fp == NULL) {
        perror("fopen error");
        return;
    }
    while (1) {
        printf("没有到达文件结尾\n");
        int result =fgetc(fp); // 一次读一个字符，读到字符直接丢弃。
        printf("%c\n", result);
        if (feof(fp)) {
            printf("到达文件结尾-----\n");
            break;
        }
    }
    fclose(fp);
}

void write_file() {
    FILE *fp = fopen("./res/test.txt", "w");
    if (fp == NULL) {
        perror("fopen error");
        return;
    }
    fputc('a', fp);
    fputc('b', fp);
    fputc(-1, fp);
    fputc('c', fp);
    fputc('d', fp);
    fputc('\n', fp);
    fclose(fp);
}

int main(void) {
//    write_file();
//    read_file();
    test_feof();
    return EXIT_SUCCESS;
}