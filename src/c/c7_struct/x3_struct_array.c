#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu {
    //成员列表
    char name[21];
    unsigned int age;
    char tel[16];
    float scores[3];//scores[0]
    char sex;
};

int main() {

    //结构体数组
    struct stu s[2];
    for (int i = 0; i < 2; i++) {
        printf("请您输入 姓名  年龄  电话  成绩  性别:\n");
        scanf("%s%d%s%f%f%f,%c", s[i].name, &s[i].age, s[i].tel, &s[i].scores[0], &s[i].scores[1], &s[i].scores[2],
              &s[i].sex);
    }


    for (int i = 0; i < 2; i++) {
        printf("姓名：%s\n", s[i].name);
        printf("年龄：%d\n", s[i].age);
        printf("电话: %s\n", s[i].tel);
        printf("成绩: %.1f   %.1f   %.1f\n", s[i].scores[0], s[i].scores[1], s[i].scores[2]);
        printf("性别: %s\n", s[i].sex == 'M' ? "男" : "女");
    }
}