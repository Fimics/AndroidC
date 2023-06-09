#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void write_file() {
    FILE *fp = fopen("./res/test.txt", "w");
    if (fp == NULL) {
        perror("fopen error");
        return;
    }

    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);
    fputc('d', fp);
    fclose(fp);
}

void read_file() {
    char ch = 0;
    FILE *fp = fopen("./res/test.txt", "r");
    if (fp == NULL) {
        perror("fopen error");
        return;
    }

    while (1) {
        ch = fgetc(fp);
        if (ch == EOF) {
            break;
        }
        printf("%d\n", ch);
    }

    fclose(fp);
}

int main() {
    write_file();
    read_file();
    return EXIT_SUCCESS;
}
