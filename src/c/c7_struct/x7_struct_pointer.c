#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct sinfo {
    char *name;
    int age;
} stu;

int main() {
    struct sinfo *s = &stu;
    s->name = (char *) malloc(sizeof(char) * 21);
    strcpy(s->name, "李芮");
    s->age = 50;
    printf("%s   %d\n", s->name, s->age);

    free(s->name);


    system("pause");
    return EXIT_SUCCESS;
}